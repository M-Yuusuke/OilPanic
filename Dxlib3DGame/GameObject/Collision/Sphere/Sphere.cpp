#include "Sphere.h"
#include "../../VectorCalculation/VectorCalculation.h"

namespace Calculation
{
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Sphere::Sphere(const VECTOR& center, float radius)
    {
        LocalCenter = center;
        WorldCenter = center;
        Radius = radius;
    }

    /// <summary>
    /// �ړ�����
    /// </summary>
    /// <param name="pos">�I�u�W�F�N�g�̃��[���h���W</param>
    void Sphere::Move(const VECTOR& pos)
    {
        WorldCenter = LocalCenter + pos;
    }

    /// <summary>
    /// �Z���^�[�̃��[�J�����W�E���[���h���W���Z�b�g
    /// </summary>
    /// <param name="pos">�I�u�W�F�N�g�̃��[���h���W</param>
    void Sphere::SetLocalCenter(const VECTOR& pos)
    {
        LocalCenter = pos;
        WorldCenter = LocalCenter;
    }
}