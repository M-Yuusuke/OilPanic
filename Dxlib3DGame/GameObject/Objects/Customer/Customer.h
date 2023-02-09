#pragma once
#include "../CharacterBase/CharacterBase.h"
namespace Calculation
{
    class Customer : public CharacterBase
    {
    public:
        Customer();
        ~Customer();

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
        /// <param name="other">�Փˊm�F������I�u�W�F�N�g�̃|�C���^</param>
        void OnCollisionEnter(GameObjectBase* other)override;
    private:
        /// <summary>
        /// ���f���̓ǂݍ���
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// �I�C���ɓ����������̃��A�N�V�������s��
        /// </summary>
        void Reaction();

        //���f���̏����z�u
        const VECTOR FirstPos = { -500.0f,-500.0f,0 };
        //�����蔻�苅�̒��S�̃��[�J�����W
        const VECTOR FirstLocalPos = {};
        //�����蔻�苅�̔��a
        const float Radius = 30.0f;
    };
}