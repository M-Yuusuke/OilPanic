#include "LineSegment.h"
#include "../../VectorCalculation/VectorCalculation.h"

namespace Calculation
{
    //�����̓����蔻��̃R���X�g���N�^
    LineSegment::LineSegment(const VECTOR& start, const VECTOR& end)
    {
        LocalStart = start;
        LocalEnd = end;
        WorldStart = start;
        WorldEnd = end;
    }

    //�����̃��[���h���W���ړ�����
    void LineSegment::Move(const VECTOR& pos)
    {
        WorldStart = LocalStart + pos;
        WorldEnd = LocalEnd + pos;
    }
}