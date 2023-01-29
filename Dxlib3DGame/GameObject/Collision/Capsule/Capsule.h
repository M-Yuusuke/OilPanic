#pragma once
#include "../../Collision/CollisionBase/CollisionBase.h"
namespace Calculation
{
    /// <summary>
    /// �J�v�Z����̓����蔻��֘A�̏������s���N���X
    /// </summary>
    class Capsule : public CollisionBase
    {
    public:
        Capsule() {}
        Capsule(const VECTOR& start, const VECTOR& end, float radius);
        /// <summary>
        /// �����蔻��̃��[���h���W�̈ړ�
        /// </summary>
        /// <param name="pos">�Ώۂ̃L�����N�^�[�̌��ݒn</param>
        void Move(const VECTOR& pos)override;

        VECTOR GetWorldStartPos() { return WorldStart; }
        VECTOR GetWorldEndPos() { return WorldStart; }
    };
}


