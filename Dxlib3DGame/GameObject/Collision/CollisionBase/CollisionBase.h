#pragma once
#include "DxLib.h"
namespace Calculation
{
    /// <summary>
    /// �����蔻��̊��N���X
    /// </summary>
    class CollisionBase
    {
    public:
        CollisionBase();

        /// <summary>
        /// �����蔻��̃��[���h���W�̈ړ�
        /// </summary>
        /// <param name="pos">�Ώۂ̃L�����N�^�[�̌��ݒn</param>
        virtual void Move(const VECTOR& pos) = 0;

        /// <summary>
        /// ���[���h���W��ł̊J�n���W�̃Q�b�^�[
        /// </summary>
        /// <returns>���[���h���W��ł̊J�n���W</returns>
        VECTOR GetWorldStart() const { return WorldStart; }

        /// <summary>
        /// ���[���h���W��ł̏I�����W�̃Q�b�^�[
        /// </summary>
        /// <returns>���[���h���W��ł̏I�����W</returns>
        VECTOR GetWorldEnd() const { return WorldEnd; }

        /// <summary>
        /// �����蔻��̔��a�̃Q�b�^�[
        /// </summary>
        /// <returns>�����蔻��̔��a</returns>
        float GetRadius()const { return Radius; }

    protected:
        //���[�J���J�n���W
        VECTOR LocalStart;
        //���[�J���I�����W
        VECTOR LocalEnd;
        //���[���h�J�n���W
        VECTOR WorldStart;
        //���[���h�I�����W
        VECTOR WorldEnd;
        //�J�v�Z���⋅�̂̔��a
        float Radius;
    };
}