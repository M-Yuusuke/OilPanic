#pragma once
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"

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

    private:
        /// <summary>
        /// ���f�����[�h
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// �ړ�����
        /// </summary>
        void Move();

        //�����蔻�苅�̒��S�_�̍��W
        const VECTOR FirstLocalPos = { 0,70.0f,0 };
        //�v���C���[���������̎��̃v���C���[�Ƃ̑��Έʒu
        const VECTOR LeftRelativePos = { -100.0f,0,0 };
        //�v���C���[���E�����̎��̃v���C���[�Ƃ̑��Έʒu
        const VECTOR RightRelativePos = { 100.0f, 0, 0 };
        //�����蔻�苅�̔��a
        const float Radius = 30.0f;
        //�v���C���[�̃|�C���^
        CharacterBase* player;
        
    };
}

