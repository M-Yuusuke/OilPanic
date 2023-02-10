#pragma once
#include "../GameObject/GameObjectBase/GameObjectBase.h"
namespace Calculation
{
    class Oil :public GameObjectBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Oil();
        Oil(VECTOR pos);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Oil();

        /// <summary>
        /// ����������
        /// </summary>
        void Initialize() override;

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Update(float deltaTime)override;

        /// <summary>
        /// �`�揈��
        /// </summary>
        void Draw()override;

    private:
        /// <summary>
        /// ���f���̓ǂݍ���
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Drop(float deltaTime);

        //���f���̑傫��
        const VECTOR Scale = { 0.25f,0.25f,0.25f };
        //�������x
        const float DropSpeed = -50.0f;
        //�����蔻�苅�̒��S���W
        const VECTOR FirstLocalPos = { 0,0,0 };
        //�����蔻�苅�̔��a
        const float Radius = 30.0f;
        
        //�����̉����l
        const float LowerLimitPosY = 250.0f;
        //�����N�[���^�C���̍ő�l(����)
        float MaxCoolTime;
        //�N�[���^�C����ۑ�����ϐ�
        float CoolTime;
        //�����l��ۑ����邽�߂̕ϐ�
        VECTOR FirstPos;
    };
}

