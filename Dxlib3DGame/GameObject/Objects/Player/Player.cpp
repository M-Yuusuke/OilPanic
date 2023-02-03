#include "Player.h"
#include <math.h>
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/Collision/CollisionFunction/CollisionFunction.h"
#include "../System/Rule/Rule.h"

namespace Calculation
{
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Player::Player() :
        CharacterBase(ObjectTag::Player)
    {
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    Player::~Player()
    {
        AssetManager::ReleaseMesh(modelHandle);
        delete animControl;
        modelHandle = -1;
        collisionModel = -1;
    }

    /// <summary>
    /// ����������
    /// </summary>
    void Player::Initialize()
    {
        dir = { 0,0,0 };
        aimDir = { 0,0,0 };
        velocity = { 0,0,0 };
        animTypeID = 0;
        rotateNow = false;
        attack = false;

        pos = FirstPos;
        dir = FirstDir;
        aimDir = dir;
    }

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Player::Update(float deltaTime)
    {
        animControl->AddAnimationTime(deltaTime);
        Rotate();
        Move(deltaTime);

        //�����蔻�胂�f�����ʒu�X�V
        CollisionUpdate();
    }

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Player::Draw()
    {
        //3D���f���̕`��
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// �����蔻�菈��
    /// </summary>
    /// <param name="other">�������Ă���I�u�W�F�N�g�̃|�C���^</param>
    void Player::OnCollisionEnter(GameObjectBase* other)
    {
        ObjectTag tag = other->GetTag();

        //�X�e�[�W�Ƃ̏Փ�
        if (tag == ObjectTag::Stage)
        {
            OnCollisionStage(other);
        }
    }

    /// <summary>
    /// ���f���̓ǂݍ���
    /// </summary>
    void Player::ModelLoad()
    {
        //���f�����[�h
        modelHandle = AssetManager::GetMesh("../Data/Assets/Remy/Model.mv1");

        //���̂܂܂��ƃX�e�[�W�ɑ΂��ă��f�����傫���̂ŏk��
        MV1SetScale(modelHandle, PlayerScale);

        //�A�j���[�V�����R���g���[���[�̐���
        animControl = new AnimationController(modelHandle);

        //�A�j���[�V�������[�h
        animControl->AddAnimation("../Data/Assets/Remy/Idle.mv1");  //�ҋ@���[�V����
        animControl->AddAnimation("../Data/Assets/Remy/Run.mv1");   //���胂�[�V����

        //�ҋ@���[�V�������Z�b�g
        animControl->StartAnimation(animTypeID);

        //�����蔻�苅�Z�b�g
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);

        //���������蔻������Z�b�g
        //collisionLine = LineSegment(LineStart, LineEnd);
    }

    /// <summary>
    /// ���͏���
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Player::Move(float deltaTime)
    {
        //�L�[���͏�Ԏ擾
        GetJoypadXInputState(DX_INPUT_PAD1, &gamePadState);
        VECTOR LEFT = { -1,0,0 };
        VECTOR RIGHT = { 1,0,0 };

        VECTOR inputVec = { 0,0,0 };
        //���͏��
        bool input = false;
        //������͂��Ă����獶�ɐi��
        if (CheckHitKey(KEY_INPUT_A) || gamePadState.ThumbLX < 0 || gamePadState.Buttons[2])
        {
            inputVec += LEFT;
            input = true;
        }
        //�E����͂��Ă�����E�ɐi��
        if (CheckHitKey(KEY_INPUT_D) || gamePadState.ThumbLX > 0 || gamePadState.Buttons[3])
        {
            inputVec += RIGHT;
            input = true;
        }

        //���͂������������
        if (input)
        {
            //�㉺�E���E���������Ȃǂœ��̓x�N�g����0�̎��͖���
            if (VSquareSize(inputVec) < InputVecMin)
            {
                return;
            }
            //�����𐳋K��
            inputVec = VNorm(inputVec);

            //���͕����͌��݌����Ă�����ƈقȂ邩�H
            if (IsNearAngle(inputVec, dir))
            {
                dir = inputVec;
            }
            else
            {
                rotateNow = true;
                aimDir = inputVec;
            }
            velocity = inputVec + (inputVec * deltaTime * MoveSpeed);

            //�����ق��̃��[�V�������������瑖�胂�[�V������
            if (animTypeID != 1)
            {
                animTypeID = 1;
                animControl->StartAnimation(animTypeID);
            }
        }
        //���͂��Ȃ������猸��
        else
        {
            velocity *= 0.9f;
            //�����ҋ@���[�V�����łȂ���Αҋ@���[�V�����ɂ���
            if (!attack && animTypeID != 0)
            {
                animTypeID = 0;
                animControl->StartAnimation(animTypeID);
            }
        }

        //���E�̈ړ�����
        if ((pos + velocity).x >= -MoveLimit && (pos + velocity).x <= MoveLimit)
        {
            //�ړ�����
            pos += velocity;
        }

        //3D���f���̃|�W�V�����ݒ�
        MV1SetPosition(modelHandle, pos);
    }
}