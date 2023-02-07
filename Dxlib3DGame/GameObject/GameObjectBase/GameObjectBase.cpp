#include "GameObjectBase.h"
#include "../AssetManager/AssetManager.h"
#include "../VectorCalculation/VectorCalculation.h"

namespace Calculation
{   /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">�I�u�W�F�N�g�^�O</param>
    GameObjectBase::GameObjectBase(ObjectTag tag) :
        tag(tag),
        pos(),
        modelHandle(-1),
        visible(true),
        alive(true),
        collisionType(),
        collisionLine(),
        collisionSphere(),
        collisionCapsule(),
        collisionModel(-1)
    {
    }

    /// <summary>
    /// �R���X�g���N�^�i�����ʒu�w��j
    /// </summary>
    /// <param name="tag">�I�u�W�F�N�g�^�O</param>
    /// <param name="pos">�I�u�W�F�N�g�̏������W</param>
    GameObjectBase::GameObjectBase(ObjectTag tag, VECTOR pos):
        tag(tag),
        pos(pos),
        modelHandle(-1),
        visible(true),
        alive(true),
        collisionType(),
        collisionLine(),
        collisionSphere(),
        collisionCapsule(),
        collisionModel(-1)
    {
    }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    GameObjectBase::~GameObjectBase()
    {
        if (modelHandle != -1)
        {
            //�R���W�������̌�n��
            MV1TerminateCollInfo(collisionModel);
            //���f���f�[�^�̌�n��
            AssetManager::ReleaseMesh(modelHandle);
            modelHandle = -1;
        }
    }

    /// <summary>
    /// �����蔻��ʒu�̍X�V
    /// </summary>
    void GameObjectBase::CollisionUpdate()
    {
        collisionSphere.Move(pos);
        collisionLine.Move(pos);
        collisionCapsule.Move(pos);

        //���f���̓����蔻������č\�z
        if (collisionModel != -1)
        {
            MV1SetPosition(collisionModel, pos);
            MV1SetupCollInfo(collisionModel);
        }
    }

    /// <summary>
    /// �����蔻��̕`��
    /// </summary>
    void GameObjectBase::DrawCollider()
    {
        //DrawLine3D(collisionLine.GetWorldStart(), collisionLine.GetWorldEnd(), GetColor(0, 0, 0));
        //DrawSphere3D(collisionSphere.GetWorldCenter(), collisionSphere.GetRadius(), 8, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
        //DrawCapsule3D(collisionCapsule.GetWorldStart(), collisionCapsule.GetWorldEnd(), collisionCapsule.GetRadius(), 8, GetColor(0, 255, 0), GetColor(0, 0, 0),FALSE);
        ////�R���W�������f�������݂��Ă����甼�����`��
        //if (collisionModel != -1)
        //{
        //    //�������ɂ���
        //    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
        //    MV1DrawModel(collisionModel);
        //    //���ɖ߂�
        //    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
        //}
    }
}