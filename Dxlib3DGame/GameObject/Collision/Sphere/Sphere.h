#pragma once
#include "../CollisionBase/CollisionBase.h"
namespace Calculation
{
    class Sphere : public CollisionBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Sphere() { WorldCenter = { 0, 0, 0 }, LocalCenter = { 0,0,0 } ;}

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        Sphere(const VECTOR& center, float radius);

        /// <summary>
        /// �ړ�����
        /// </summary>
        /// <param name="pos">�I�u�W�F�N�g�̃��[���h���W</param>
        void Move(const VECTOR& pos)override;

        /// <summary>
        /// �Z���^�[�̃��[�J�����W�E���[���h���W���Z�b�g
        /// </summary>
        /// <param name="pos">�I�u�W�F�N�g�̃��[���h���W</param>
        void SetLocalCenter(const VECTOR& pos);

        /// <summary>
        /// �����蔻�苅�̔��a���Z�b�g
        /// </summary>
        /// <param name="radius"></param>
        void SetRadius(const float radius) { Radius = radius; }

        /// <summary>
        /// �����蔻�苅�̒��S�̃��[���h���W��Ԃ�
        /// </summary>
        /// <returns>�����蔻�苅�̒��S�̃��[���h���W</returns>
        VECTOR GetWorldCenter() const { return WorldCenter; }

    private:
        //�Z���^�[�̃��[�J�����W
        VECTOR LocalCenter;
        //�Z���^�[�̃��[���h���W
        VECTOR WorldCenter;
    };
}


