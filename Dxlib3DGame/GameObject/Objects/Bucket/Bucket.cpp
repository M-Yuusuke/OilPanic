#include "Bucket.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"
#include "../Player/Player.h" 
#include "../System/Rule/Rule.h"
#include "../Oil/Oil.h"
#include "../PlayerOil/PlayerOil.h"

namespace Calculation
{
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Bucket::Bucket():
        CharacterBase(ObjectTag::Bucket)
    {
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    Bucket::~Bucket()
    {
        AssetManager::ReleaseMesh(modelHandle);
        modelHandle = -1;
    }

    /// <summary>
    /// ����������
    /// </summary>
    void Bucket::Initialize()
    {
        //�l�����̏�����
        acquisition = 0;
    }

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Bucket::Update(float deltaTime)
    {
        //�ړ�����
        Move();
        //���ݎ��ʐ���
        if (acquisition > 0)
        {
            HandOver();
        }
        //�����蔻��̍X�V����
        CollisionUpdate();
    }

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Bucket::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// �����蔻�菈��
    /// </summary>
    /// <param name="Obj">�I�u�W�F�N�g�̃|�C���^</param>
    void Bucket::OnCollisionEnter(GameObjectBase* other)
    {
        ObjectTag tag = other->GetTag();
        if (tag == ObjectTag::Oil)
        {
            //���̓��m�̓����蔻��
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
                //�l����������l�����������ꍇ�̂݊l��(�l�����3��)
                if (acquisition < AcquisitionLimit)
                {
                    //���݂̊l���������Z
                    acquisition++;
                    //�l���ł����珉����
                    static_cast<Oil*>(other)->Initialize();
                    //�X�R�A���Z�i�{�[�i�X�����j
                    Rule::AcquisitionScore();
                }
            }
        }
    }

    /// <summary>
    /// ���f�����[�h
    /// </summary>
    void Bucket::ModelLoad()
    {
        //���f���f�[�^�̓ǂݍ���
        modelHandle = AssetManager::GetMesh("../Data/Assets/Bucket/Model.mv1");
        //���f���̑傫���̃Z�b�g
        MV1SetScale(modelHandle,Scale);
        //���f���̔z�u
        MV1SetPosition(modelHandle, pos);

        //�����蔻�苅�Z�b�g
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }

    /// <summary>
    /// �ړ�����(�v���C���[����ɔz�u)
    /// </summary>
    void Bucket::Move()
    {
        if (!player)
        {
            player = static_cast<Player*>(GameObjectManager::GetFirstGameObject(ObjectTag::Player));
        }
        //�v���C���[�̌����Ă���������擾
        VECTOR dir = player->GetDir();
        //�v���C���[���E�������Ă�����
        if (dir.x > 0)
        {
            //�v���C���[�̐��ʂɔz�u
            pos = player->GetPos() + RightRelativePos;
        }
        //�v���C���[�����������Ă�����
        if (dir.x < 0)
        {
            //�v���C���[�̐��ʂɔz�u
            pos = player->GetPos() + LeftRelativePos;
        }
        //���f���̔z�u
        MV1SetPosition(modelHandle, pos);
    }

    /// <summary>
    /// ���߂��I�C����n������
    /// </summary>
    void Bucket::HandOver()
    {
        //�v���C���[���ړ������܂ŗ�����
        if (player->IsMoveLimit())
        {
            //�Q�[���p�b�h�̓��͏�Ԃ��擾
            GetJoypadXInputState(DX_INPUT_PAD1, &gamePadState);
            //�Q�[���p�b�h��B�{�^���������̓X�y�[�X�L�[�������ꂽ��
            if (gamePadState.Buttons[13] || CheckHitKey(KEY_INPUT_SPACE))
            {
                //�I�C���𐶐�
                GameObjectManager::Entry(new PlayerOil(pos, acquisition));
                //���܂����ʂ�������
                acquisition = 0;
            }
        }
    }
}