#pragma once
#include <Dxlib.h>

/// <summary>
/// ���Z�q�I�[�o�[���[�h���L�q�������O���
/// </summary>
namespace Calculation
{    /// <summary>
    /// �x�N�g�����m�̍���
    /// </summary>
    /// <param name="lhs">�����������x�N�g��1</param>
    /// <param name="rhs">�����������x�N�g��2</param>
    /// <returns>������̃x�N�g��</returns>
    VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs);

    /// <summary>
    /// �x�N�g�����m�̕���
    /// </summary>
    /// <param name="lhs">�����������x�N�g��1</param>
    /// <param name="rhs">�����������x�N�g��2</param>
    /// <returns>������̃x�N�g��</returns>
    VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs);

    /// <summary>
    /// �x�N�g���̃X�J���[�{
    /// </summary>
    /// <param name="lhs">�X�J���[�{�������x�N�g��</param>
    /// <param name="s">�X�J���[�{����W��</param>
    /// <returns>�X�J���[�{��̃x�N�g��</returns>
    VECTOR operator*(const VECTOR& lhs ,float s);

    /// <summary>
    /// �x�N�g���̉��Z�̕���������Z�q
    /// </summary>
    /// <param name="lhs">�����������x�N�g��1</param>
    /// <param name="rhs">�����������x�N�g��2</param>
    /// <returns>������̃x�N�g��</returns>
    VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs);

    /// <summary>
    /// �x�N�g���̌��Z�̕���������Z�q
    /// </summary>
    /// <param name="lhs">�����������x�N�g��1</param>
    /// <param name="rhs">�����������x�N�g��2</param>
    /// <returns>������̃x�N�g��</returns>
    VECTOR operator-=(VECTOR& lhs, const VECTOR& rhs);

    /// <summary>
    /// �x�N�g���̃X�J���[�{�̕���������Z�q
    /// </summary>
    /// <param name="lhs">�X�J���[�{�������x�N�g��</param>
    /// <param name="s">�X�J���[�{����W��</param>
    /// <returns>�X�J���[�{��̃x�N�g��</returns>
    VECTOR operator*=(VECTOR& lhs, float s);

    /// <summary>
    /// 2�̃x�N�g���̊p�x�͂قړ�����
    /// </summary>
    /// <param name="lhs"> �����������x�N�g��1 </param>
    /// <param name="rhs"> �����������x�N�g��2 </param>
    /// <returns>2�̃x�N�g���̊p�x���قړ����ł����true �قȂ��false��Ԃ�</returns>
    bool IsNearAngle(const VECTOR& lhs, const VECTOR& rhs);

    /// <summary>
    /// �������Ă����������������������ւ̍ŒZ�̉�]�����𒲂ׂ�(Y����])
    /// </summary>
    /// <param name="nowVec">�������Ă������</param>
    /// <param name="dirVec">������������</param>
    /// <returns>�ŒZ�̉�]����</returns>
    float CalcRotationDirectionYAxis(const VECTOR& nowVec, const VECTOR& dirVec);

    /// <summary>
    /// //NowVec����AimVec�Ɍ�������DegreeVelocity�̑��x��Y��]����
    /// </summary>
    /// <param name="nowVec">�������Ă������</param>
    /// <param name="aimVec">������������</param>
    /// <param name="degreeVelocity">��]���x</param>
    /// <returns>��]����</returns>
    VECTOR RotateForAimVecYAxis(const VECTOR& nowVec, const VECTOR& aimVec, float degreeVelocity);

    //���ς̍ő�l
    const float dotMax = 0.99f;
}