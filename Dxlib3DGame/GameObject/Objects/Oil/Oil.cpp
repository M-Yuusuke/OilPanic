#include "Oil.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../System/Rule/Rule.h"

namespace Calculation
{
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Oil::Oil():
        GameObjectBase(ObjectTag::Oil)
    {
        FirstPos = { 0,0,0 };
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Oil::Oil(VECTOR pos):
        GameObjectBase(ObjectTag::Oil, pos)
    {
        FirstPos = pos;
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    Oil::~Oil()
    {
    }

    /// <summary>
    /// ����������
    /// </summary>
    void Oil::Initialize()
    {
        //���f�����\��
        visible = false;
        //�ݒ肳�ꂽ�|�W�V�����ɃZ�b�g
        pos = FirstPos;
        //1�`5�b�̃N�[���^�C�����Z�b�g
        MaxCoolTime = (float)(1 + GetRand(9));
        //�N�[���^�C����ݒ�
        CoolTime = MaxCoolTime;
    }

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Oil::Update(float deltaTime)
    {
        //��������
        Drop(deltaTime);
        //�����蔻��̍X�V����
        CollisionUpdate();
    }

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Oil::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// �����蔻�菈��
    /// </summary>
    /// <param name="other">�������Ă���I�u�W�F�N�g�̃|�C���^</param>
    void Oil::OnCollisionEnter(GameObjectBase* other)
    {
        //�Փ˃I�u�W�F�N�g�̃^�O���擾
        ObjectTag tag = other->GetTag();
        //�v���C���[�ƏՓ˂����ꍇ
        if (tag == ObjectTag::Bucket)
        {
        }
    }

    /// <summary>
    /// ���f���̓ǂݍ���
    /// </summary>
    void Oil::ModelLoad()
    {
        //���f�����[�h�@���f���f�[�^�͉��Ȃ̂Ō�ɕύX
        modelHandle = AssetManager::GetMesh("../Data/Assets/Oil/Model.mv1");

        //���f���̑傫�����Z�b�g
        MV1SetScale(modelHandle, Scale);

        //���f�����Z�b�g
        MV1SetPosition(modelHandle, pos);

        //�����蔻�苅�Z�b�g
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }

    /// <summary>
    /// ��������
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Oil::Drop(float deltaTime)
    {
        if (CoolTime > 0)
        {
            //�N�[���^�C�������Z
            CoolTime -= deltaTime;
        }
        //�N�[���^�C����0�ɂȂ�Η���
        if (CoolTime <= 0)
        {
            visible = true;
            pos.y += deltaTime * DropSpeed;
            MV1SetPosition(modelHandle, pos);
        }

        //pos��Y���W�������l����������珉����
        if(pos.y <= LowerLimitPosY)
        {
            //��\��
            visible = false;
            //�~�X�J�E���g���Z
            Rule::AddMissCount();
            //������
            Initialize();
        }
    }
}