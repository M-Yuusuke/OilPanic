#pragma once
#include "../CharacterBase/CharacterBase.h"
namespace Calculation
{
    class Helper : public CharacterBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Helper();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Helper();

        /// <summary>
        /// ����������
        /// </summary>
        void Initialize()override;

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Update(float deltaTime)override;

        /// <summary>
        /// �`�揈��
        /// </summary>
        void Draw()override;

        /// <summary>
        /// �����蔻�菈��
        /// </summary>
        /// <param name="other">�Փ˂��m�F�������I�u�W�F�N�g�̃|�C���^</param>
        void OnCollisionEnter(GameObjectBase* other)override;

    private:
        /// <summary>
        /// ���f���̓ǂݍ���
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// �ړ�����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Move(float deltaTime)override;

        //�����蔻�苅�̏����z�u
        const VECTOR FirstLocalPos = { 0,50.0f,0 };
        //���f���̏����ʒu
        const VECTOR FirstPos = { 350.0f,-100.0f,0 };
        //�����蔻�苅�̔��a
        const float Radius = 30.0f;
        //�ő��~����
        const float MaxCoolTime = 5.0f;
        //�ړ����x
        const float MoveSpeed = 300.0f;
        //�ړ�����
        const float MoveLimitX = 350.0f;

        //�ړ���~����
        float coolTime;
    };
}

