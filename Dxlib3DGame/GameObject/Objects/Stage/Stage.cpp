#include "Stage.h"
#include "../../VectorCalculation/VectorCalculation.h"
#include "../../ObjectTag.h"
#include "../../AssetManager/AssetManager.h"
#include "../../GameObjectManager/GameObjectManager.h"

namespace Calculation
{
    /// <summary>
    /// �R���X�g���N�^�i�V���O���g���j
    /// </summary>
    Stage::Stage():
        GameObjectBase(ObjectTag::Stage)
    {
        pos = StagePos;
        ModelLoad();
    }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    Stage::~Stage()
    {
        AssetManager::ReleaseMesh(modelHandle);
        AssetManager::ReleaseMesh(collisionModel);
        modelHandle = -1;
        collisionModel = -1;
    }

    /// <summary>
    /// ���f���̓ǂݍ���
    /// </summary>
    void Stage::ModelLoad()
    {
        //�\�����f���ǂݍ���&�X�P�[�����O&�ʒu�Z�b�g
        modelHandle = AssetManager::GetMesh("../Data/Assets/Stage/Stage.mv1");
        MV1SetScale(modelHandle, VGet(1.0f, 0.05f, 1.0f));
        MV1SetPosition(modelHandle, pos);

        //�����蔻�胂�f���ǂݍ���&�X�P�[�����O&�����蔻����\�z
        collisionModel = AssetManager::GetMesh("../Data/Assets/Stage/StageHitMesh.mv1");
        MV1SetScale(collisionModel, VGet(1.0f, 1.0f, 1.0f));
        MV1SetOpacityRate(collisionModel, 0.3f);

        //�\�����f���Ɠ����蔻�胂�f���̈ʒu�𒲐�
        //MV1SetPosition(collisionModel, pos + VGet(-45, 200, -35));
        MV1SetupCollInfo(collisionModel);
    }

    /// <summary>
    /// ����������
    /// </summary>
    void Stage::Initialize()
    {
        //���f���f�[�^���Ȃ�������ǂݍ���
        if (modelHandle == -1)
        {
            ModelLoad();
        }
    }

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Stage::Draw()
    {
        //MV1DrawModel(modelHandle);
        //DrawCollider();
    }
}