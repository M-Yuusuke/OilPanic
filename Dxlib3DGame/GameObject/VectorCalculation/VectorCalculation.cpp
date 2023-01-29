#include "VectorCalculation.h"

namespace Calculation
{
    /// <summary>
    /// �x�N�g�����m�̍���
    /// </summary>
    /// <param name="lhs">�����������x�N�g��1</param>
    /// <param name="rhs">�����������x�N�g��2</param>
    /// <returns>���������x�N�g��</returns>
    VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs)
    {
        VECTOR Ret;
        Ret.x = lhs.x + rhs.x;
        Ret.y = lhs.y + rhs.y;
        Ret.z = lhs.z + rhs.z;
        return Ret;
    }

    /// <summary>
    /// �x�N�g�����m�̕���
    /// </summary>
    /// <param name="lhs">�����������x�N�g��1</param>
    /// <param name="rhs">�����������x�N�g��2</param>
    /// <returns>���������x�N�g��</returns>
    VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs)
    {
        VECTOR Ret;
        Ret.x = lhs.x - rhs.x;
        Ret.y = lhs.y - rhs.y;
        Ret.z = lhs.z - rhs.z;
        return Ret;
    }

    /// <summary>
    /// �x�N�g���̃X�J���[�{
    /// </summary>
    /// <param name="lhs">�X�J���[�{�������x�N�g��</param>
    /// <param name="s">�X�J���[�{����W��</param>
    /// <returns>�X�J���[�{��̃x�N�g��</returns>
    VECTOR operator*(const VECTOR& lhs, float s)
    {
        VECTOR Ret;
        Ret.x = s * lhs.x;
        Ret.y = s * lhs.y;
        Ret.z = s * lhs.z;
        return Ret;
    }

    /// <summary>
    /// �x�N�g���̉��Z�̕���������Z�q
    /// </summary>
    /// <param name="lhs">�����������x�N�g��1</param>
    /// <param name="rhs">�����������x�N�g��2</param>
    /// <returns>������̃x�N�g��</returns>
    VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs)
    {
        lhs = lhs + rhs;
        return lhs;
    }

    /// <summary>
    /// �x�N�g���̌��Z�̕���������Z�q
    /// </summary>
    /// <param name="lhs">�����������x�N�g��1</param>
    /// <param name="rhs">�����������x�N�g��2</param>
    /// <returns>������̃x�N�g��</returns>
    VECTOR operator-=(VECTOR& lhs, const VECTOR& rhs)
    {
        lhs = lhs - rhs;
        return lhs;
    }

    /// <summary>
    /// �x�N�g���̃X�J���[�{�̕���������Z�q
    /// </summary>
    /// <param name="lhs">�X�J���[�{�������x�N�g��</param>
    /// <param name="s">�X�J���[�{����W��</param>
    /// <returns>�X�J���[�{��̃x�N�g��</returns>
    VECTOR operator*=(VECTOR& lhs, float s)
    {
        lhs = lhs * s;
        return lhs;
    }

    /// <summary>
    /// 2�̃x�N�g���̊p�x�͂قړ�����
    /// </summary>
    /// <param name="lhs"> �����������x�N�g��1 </param>
    /// <param name="rhs"> �����������x�N�g��2 </param>
    /// <returns>2�̃x�N�g���̊p�x���قړ����ł����true �قȂ��false��Ԃ�</returns>
    bool IsNearAngle(const VECTOR& lhs, const VECTOR& rhs)
    {
        float dot = VDot(lhs, rhs);
        if (dot > dotMax)
        {
            return true;
        }
        return false;
    }

    /// <summary>
    /// �������Ă����������������������ւ̍ŒZ�̉�]�����𒲂ׂ�(Y����])
    /// </summary>
    /// <param name="nowVec">�������Ă������</param>
    /// <param name="dirVec">������������</param>
    /// <returns>�ŒZ�̉�]�����i�E���Ȃ�1.0�A�����Ȃ�-1.0�j</returns>
    float CalcRotationDirectionYAxis(const VECTOR& nowVec, const VECTOR& dirVec)
    {
        VECTOR Axis;
        //�O�ω��Z
        Axis = VCross(nowVec, dirVec);
        if (Axis.y < 0.0f)
        {
            return -1.0f;
        }
        return 1.0f;
    }

    /// <summary>
    /// //NowVec����AimVec�Ɍ�������DegreeVelocity�̑��x��Y��]����
    /// </summary>
    /// <param name="nowVec">�������Ă������</param>
    /// <param name="aimVec">������������</param>
    /// <param name="degreeVelocity">��]���x</param>
    /// <returns>��]����</returns>
    VECTOR RotateForAimVecYAxis(const VECTOR& nowVec, const VECTOR& aimVec, float degreeVelocity)
    {
        //�p���x(�x��)��rad�ɕϊ��A�E��肩����肩�𒲂ׂ�
        float RotRad = (DX_PI_F * degreeVelocity / 180.0f);
        RotRad *= CalcRotationDirectionYAxis(nowVec, aimVec);

        //Y����]�s����쐬����
        MATRIX YRotMat = MGetRotY(RotRad);

        //Y����]����
        VECTOR RotVec;
        RotVec = VTransform(nowVec, YRotMat);
        return RotVec;
    }
}

