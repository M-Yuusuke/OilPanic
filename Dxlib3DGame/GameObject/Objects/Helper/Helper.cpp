#include "Helper.h"
#include "../GameObject/AnimationController/AnimationController.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/AssetManager/AssetManager.h"

namespace Calculation
{
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Helper::Helper():
        CharacterBase(ObjectTag::Helper)
    {
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    Helper::~Helper()
    {
        AssetManager::ReleaseMesh(modelHandle);
        modelHandle = -1;
    }

    /// <summary>
    /// ����������
    /// </summary>
    void Helper::Initialize()
    {
        animTypeID = 0;
        coolTime = MaxCoolTime;
        pos = FirstPos;
        dir = { 1,0,0 };
    }

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Helper::Update(float deltaTime)
    {
        animControl->AddAnimationTime(deltaTime);
        Move(deltaTime);
        Rotate();
        CollisionUpdate();
    }

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Helper::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// �����蔻�菈��
    /// </summary>
    /// <param name="other">�Փ˂��m�F�������I�u�W�F�N�g�̃|�C���^</param>
    void Helper::OnCollisionEnter(GameObjectBase* other)
    {
    }

    /// <summary>
    /// ���f���̓ǂݍ���
    /// </summary>
    void Helper::ModelLoad()
    {
        //���f���̓ǂݍ���
        modelHandle = AssetManager::GetMesh("../Data/Assets/Josh/Model.mv1");

        //�A�j���[�V�����R���g���[���[�̐���
        animControl = new AnimationController(modelHandle);

        //�A�j���[�V������ǉ�
        animControl->AddAnimation("../Data/Assets/Josh/Idle.mv1");      //�ҋ@���[�V����
        animControl->AddAnimation("../Data/Assets/Josh/Run.mv1");       //�ړ����[�V����

        //���f����z�u
        MV1SetPosition(modelHandle,pos);

        //�ҋ@���[�V�������Đ��J�n
        animControl->StartAnimation(animTypeID);

        //�����蔻�苅�Z�b�g
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }

    /// <summary>
    /// �ړ�����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Helper::Move(float deltaTime)
    {
        VECTOR RightDir = { 1,0,0 };
        VECTOR LeftDir = { -1,0,0 };

        if (coolTime > 0)
        {
            //��~���Ԃ̏���
            coolTime -= deltaTime;
            //�ҋ@���[�V�������łȂ���Αҋ@���[�V�����ɕύX
            if (animTypeID != 0)
            {
                animTypeID = 0;
                animControl->StartAnimation(animTypeID);
            }
        }
        if (coolTime <= 0)
        {
            //�ړ����[�V�������łȂ���Έړ����[�V�����ɕύX
            if (animTypeID != 1)
            {
                animTypeID = 1;
                animControl->StartAnimation(animTypeID);
            }
            //���[�̈ړ������܂ŗ������莞�Ԓ�~�㔽�Ε����Ɉړ�
            if (pos.x <= -MoveLimitX)
            {
                dir = RightDir;
                coolTime = MaxCoolTime;
            }
            //�E�[�̈ړ������܂ŗ������莞�Ԓ�~�㔽�Ε����Ɉړ�
            if (pos.x >= MoveLimitX)
            {
                dir = LeftDir;
                coolTime = MaxCoolTime;
            }
            pos += dir * deltaTime * MoveSpeed;
            MV1SetPosition(modelHandle,pos);
        }
    }
}
