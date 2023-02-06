#pragma once
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"
#include "../System/UI/ScoreUI/ScoreUI.h"
namespace Calculation
{
    /// <summary>
    /// �v���C���[�֘A�������s���N���X
    /// </summary>
    class Player : public CharacterBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Player();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Player();

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
        /// <param name="other">�������Ă���I�u�W�F�N�g�̃|�C���^</param>
        void OnCollisionEnter(GameObjectBase* other)override;

        /// <summary>
        /// �ړ������t���O��Ԃ�
        /// </summary>
        /// <returns>�ړ������t���O</returns>
        bool IsMoveLimit()const { return moveLimitFlag; }

    private:
        /// <summary>
        /// ���f���̓ǂݍ���
        /// </summary>
        void ModelLoad()override;

        /// <summary>
        /// ���͏���
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Move(float deltaTime)override;

        //�傫��
        const VECTOR PlayerScale = { 0.5f,0.5f, 0.5f };
        //�������W
        const VECTOR FirstPos = { 0,100,0 };
        //��������
        const VECTOR FirstDir = { 1,0,0 };
        //�ړ�����
        const float MoveLimit = 200.0f;

        //���̏������[�J�����W
        const VECTOR FirstLocalPos = { 0, 50.0f, 0 };

        //����̓����蔻��̔��a
        const float Radius = 40.0f;
        //���̓x�N�g���̍ŏ��l
        const float InputVecMin = 0.5f;
        //�ړ����x
        const float MoveSpeed = 200.0f;

        //�Q�[���p�b�h���͏��
        XINPUT_STATE gamePadState;

        //�ړ������ɗ���������̃t���O
        bool moveLimitFlag;
    };
}