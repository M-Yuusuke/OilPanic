#include "DxLib.h"
#include "Customer.h"
#include "../PlayerOil/PlayerOil.h"
#include "../System/Rule/Rule.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/AnimationController/AnimationController.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"

namespace Calculation
{
    Customer::Customer():
        CharacterBase(ObjectTag::Customer)
    {
        Initialize();
        ModelLoad();
    }

    Customer::~Customer()
    {
        //���f���f�[�^���폜
        AssetManager::ReleaseMesh(modelHandle);
        modelHandle = -1;
        //�A�j���[�V�����R���g���[�����폜
        delete animControl;
        animControl = nullptr;
    }

    /// <summary>
    /// ����������
    /// </summary>
    void Customer::Initialize()
    {
        //�������W�ɔz�u
        pos = FirstPos;
        //�E����
        dir = { 1.0f,0,0 };
    }

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Customer::Update(float deltaTime)
    {
        animControl->AddAnimationTime(deltaTime);
        Rotate();
        CollisionUpdate();
    }

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Customer::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// �����蔻�菈��
    /// </summary>
    /// <param name="other">�Փˊm�F������I�u�W�F�N�g�̃|�C���^</param>
    void Customer::OnCollisionEnter(GameObjectBase* other)
    {
        ObjectTag tag = other->GetTag();
        //���ݎ�����I�C���Ƃ̓����蔻��
        if (tag == ObjectTag::PlayerOil)
        {
            //�����蔻�苅���m������������
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
                //���������ۂ̃��A�N�V����
                Reaction();
                //�~�X�J�E���g�����Z
                Rule::AddMissCount();
            }
        }
    }

    /// <summary>
    /// �I�C���ɓ����������̃��A�N�V�������s��
    /// </summary>
    void Customer::Reaction()
    {
        //�{�胂�[�V�������łȂ���Γ{�胂�[�V�������Đ�
        if (animTypeID != 1)
        {
            animTypeID = 1;
            animControl->StartAnimation(animTypeID);
        }

        //�{�胂�[�V�������Đ����łȂ���Αҋ@���[�V�������Đ�
        if (!animControl->IsPlaying(1))
        {
            animTypeID = 0;
            animControl->StartAnimation(animTypeID);
        }
    }

    /// <summary>
    /// ���f���̓ǂݍ���
    /// </summary>
    void Customer::ModelLoad()
    {
        //���f���ǂݍ���
        modelHandle = AssetManager::GetMesh("../Data/Assets/Alex/Model.mv1");
        //�A�j���[�V�����R���g���[���𐶐�
        animControl = new AnimationController(modelHandle);

        //�A�j���[�V�����f�[�^�ǂݍ���
        animControl->AddAnimation("../Data/Assets/Alex/Idle.mv1");   //�ҋ@���[�V����
        animControl->AddAnimation("../Data/Assets/Alex/Angry.mv1");  //�{�胂�[�V����

        //���f�����w��̍��W�ɔz�u
        MV1SetPosition(modelHandle, pos);

        //�ҋ@���[�V�������Z�b�g
        animControl->StartAnimation(animTypeID);

        //�����蔻�苅�Z�b�g
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }
}