#include "DxLib.h"
#include "PlayerOil.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../System/Rule/Rule.h"
#include "../Bucket/Bucket.h"

namespace Calculation
{
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    PlayerOil::PlayerOil(VECTOR& pos, int scale):
        GameObjectBase(ObjectTag::PlayerOil,pos)
    {
        magnification = (float)scale;
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    PlayerOil::~PlayerOil()
    {
    }

    /// <summary>
    /// ����������
    /// </summary>
    void PlayerOil::Initialize()
    {
        //�o�P�c�̋��ݎ��ʂɂ���ă��f���̑傫�����g��
        scale = { FirstScale.x * magnification,FirstScale.y * magnification, FirstScale.z * magnification };
    }

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void PlayerOil::Update(float deltaTime)
    {
        //��������
        Drop(deltaTime);
        //�R���C�_�[�̍X�V����
        CollisionUpdate();
    }

    /// <summary>
    /// �`�揈��
    /// </summary>
    void PlayerOil::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// �����蔻�菈��
    /// </summary>
    /// <param name="other">���������I�u�W�F�N�g�̃|�C���^</param>
    void PlayerOil::OnCollisionEnter(GameObjectBase* other)
    {
        ObjectTag tag = other->GetTag();
        //����`���Ƃ̓����蔻��
        if (tag == ObjectTag::Helper)
        {
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
                //�����������\��
                visible = false;
                //�{�[�i�X���݂̃X�R�A���Z
                Rule::AcquisitionScore(bucket->GetAcquisition());
            }
        }
        if (tag == ObjectTag::Player)
        {
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
                //��\��
                visible = false;
                //
            }
        }
    }

    /// <summary>
    /// ���f���f�[�^�̓ǂݍ���
    /// </summary>
    void PlayerOil::ModelLoad()
    {
        //���f�����[�h
        modelHandle = AssetManager::GetMesh("../Data/Assets/EXP/Model.mv1");

        //���̂܂܂��ƃX�e�[�W�ɑ΂��ă��f�����傫���̂ŏk��
        MV1SetScale(modelHandle, scale);

        //���f����z�u
        MV1SetPosition(modelHandle, pos);

        //�����蔻�苅�Z�b�g
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }

    /// <summary>
    /// ��������
    /// </summary>
    void PlayerOil::Drop(float deltaTime)
    {
        pos.y -= deltaTime * DropSpeed;
        MV1SetPosition(modelHandle, pos);
    }
}