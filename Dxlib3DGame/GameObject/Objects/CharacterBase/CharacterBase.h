#pragma once
#include "../GameObject/GameObjectBase/GameObjectBase.h"
#include "../GameObject/AnimationController/AnimationController.h"

namespace Calculation
{
    class CharacterBase : public GameObjectBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        CharacterBase(ObjectTag tag);
        CharacterBase(ObjectTag tag, VECTOR pos);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        virtual ~CharacterBase() {}

        /// <summary>
        /// �_���[�W���󂯂鏈��
        /// </summary>
        virtual void OnDamage() {}

        /// <summary>
        /// �c��HP��Ԃ�
        /// </summary>
        /// <returns>�c��HP</returns>
        int GetHP()const { return hp; }

        /// <summary>
        /// �����Ă�������x�N�g����Ԃ�
        /// </summary>
        /// <returns>�����Ă�������x�N�g��</returns>
        VECTOR GetDir()const { return dir; }

        /// <summary>
        /// �U�������ǂ����̃t���O��Ԃ�
        /// </summary>
        /// <returns>�U���t���O��Ԃ�</returns>
        bool IsAttack()const { return attack; }

        /// <summary>
        /// �h�䒆�����ǂ����̃t���O��Ԃ�
        /// </summary>
        /// <returns>�h��t���O��Ԃ�</returns>
        bool IsGuard()const { return guard; }

    protected:
        /// <summary>
        /// ���f���ƃA�j���[�V�����̓ǂݍ���
        /// </summary>
        virtual void ModelLoad() = 0;
        /// <summary>
        /// �ړ�����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        virtual void Move(float deltaTime) {}
        /// <summary>
        /// ��]����
        /// </summary>
        void Rotate();

        /// <summary>
        /// �v���C���[�ƃX�e�[�W�̓����蔻��
        /// </summary>
        /// <param name="other">�������Ă���I�u�W�F�N�g�̃|�C���^</param>
        void OnCollisionStage(const GameObjectBase* other);

        //��]���x
        const float RotateVelocity = 10.0f;
        //����
        VECTOR dir;
        //�ڕW����
        VECTOR aimDir;
        //���x
        VECTOR velocity;

        //�A�j���[�V�����Ǘ��p
        AnimationController* animControl;
        //�A�j���[�V�������ID
        int animTypeID;
        //��]�����ǂ���
        bool rotateNow;

        //�c��HP
        int hp;

        //�U������
        bool attack;
        //�h�䒆��
        bool guard;
    };
}