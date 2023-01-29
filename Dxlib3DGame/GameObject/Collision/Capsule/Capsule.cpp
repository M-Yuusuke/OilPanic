#include "Capsule.h"
#include "../../VectorCalculation/VectorCalculation.h"
namespace Calculation
{
    //�J�v�Z���̓����蔻��R���X�g���N�^
    Capsule::Capsule(const VECTOR& start, const VECTOR& end, float radius)
    {
        LocalStart = start;
        LocalEnd = end;
        WorldStart = start;
        WorldEnd = end;
        Radius = radius;
    }

    /// <summary>
    /// �����蔻��̃��[���h���W�̈ړ�
    /// </summary>
    /// <param name="pos">�Ώۂ̃L�����N�^�[�̌��ݒn</param>
    void Capsule::Move(const VECTOR& pos)
    {
        WorldStart = LocalStart + pos;
        WorldEnd = LocalEnd + pos;
    }
}