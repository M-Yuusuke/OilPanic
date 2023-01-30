#include "Bucket.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"

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
        visible = true;
    }

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Bucket::Update(float deltaTime)
    {
        //�ړ�����
        Move();
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
        //�I�C���Ƃ̓����蔻��
        if (tag == ObjectTag::Oil)
        {
            //�����蔻�苅���m���������Ă�����
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
            }
        }
    }

    /// <summary>
    /// ���f�����[�h
    /// </summary>
    void Bucket::ModelLoad()
    {
        //modelHandle = AssetManager::GetMesh("../Data/Assets/Bucket/Model.mv1");
        //MV1SetScale(modelHandle,);
        //MV1SetPosition(modelHandle, pos);

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
            player = static_cast<CharacterBase*>(GameObjectManager::GetFirstGameObject(ObjectTag::Player));
        }
        //�o�P�c�̃��f���̓v���C���[�̑��Έʒu�ɔz�u
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
    }
}