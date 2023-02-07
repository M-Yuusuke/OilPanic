#pragma once
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"
#include "../Player/Player.h"

namespace Calculation
{
    class Bucket : public CharacterBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Bucket();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Bucket();

        /// <summary>
        /// ����������
        /// </summary>
        void Initialize();

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Update(float deltaTime)override;

        /// <summary>
        /// �`�揈��
        /// </summary>
        void Draw();

        /// <summary>
        /// �����蔻�菈��
        /// </summary>
        /// <param name="Obj">�I�u�W�F�N�g�̃|�C���^</param>
        void OnCollisionEnter(GameObjectBase* other)override;

        /// <summary>
        /// �I�C���̊l������Ԃ�
        /// </summary>
        /// <returns>���݂̃I�C���̊l����</returns>
        int GetAcquisition()const { return acquisition; }

    private:
        /// <summary>
        /// ���f�����[�h
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// �ړ�����
        /// </summary>
        void Move();

        /// <summary>
        /// ���߂��I�C����n������
        /// </summary>
        void HandOver();

        //�����蔻�苅�̒��S�_�̍��W
        const VECTOR FirstLocalPos = { 0,10.0f,0 };
        //�v���C���[���������̎��̃v���C���[�Ƃ̑��Έʒu
        const VECTOR LeftRelativePos = { -50.0f,100.0f,0 };
        //�v���C���[���E�����̎��̃v���C���[�Ƃ̑��Έʒu
        const VECTOR RightRelativePos = { 50.0f, 100.0f, 0 };
        //���f���̑傫��
        const VECTOR Scale = { 2.0f,2.0f,2.0f };
        //�����蔻�苅�̔��a
        const float Radius = 50.0f;
        //�l�����
        const int AcquisitionLimit = 3;

        //�v���C���[�̃|�C���^
        Player* player;
        //���݂̊l����
        int acquisition;
        //�Q�[���p�b�h���͏��
        XINPUT_STATE gamePadState;
    };
}

