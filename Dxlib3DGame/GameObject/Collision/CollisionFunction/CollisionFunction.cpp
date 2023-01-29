#include <math.h>
#include "CollisionFunction.h"
#include "../../VectorCalculation/VectorCalculation.h"

namespace Calculation
{
    /// <summary>
    /// ���̓��m�̓����蔻�菈��
    /// </summary>
    /// <param name="sphereL">����1</param>
    /// <param name="sphereR">����2</param>
    /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
    bool CollisionFunction::CollisionPair(const Sphere& sphereL, const Sphere& sphereR)
    {
        return HitCheck_Sphere_Sphere(sphereL.GetWorldCenter(),sphereL.GetRadius(), sphereR.GetWorldCenter(), sphereR.GetRadius());
    }

    /// <summary>
    /// �����Ƌ��̂̓����蔻�菈��
    /// </summary>
    /// <param name="line">����</param>
    /// <param name="sphere">����</param>
    /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
    bool CollisionFunction::CollisionPair(const LineSegment& line, const Sphere& sphere)
    {
        return HitCheck_Line_Sphere(line.GetWorldStart(), line.GetWorldEnd(), sphere.GetWorldCenter(), sphere.GetRadius());
    }

    /// <summary>
    /// ���̂ƃ��f���̓����蔻�菈��
    /// </summary>
    /// <param name="sphere">����</param>
    /// <param name="modelHandle">���f���n���h��</param>
    /// <param name="collisionInfo">�R���W�������ʑ���p�|���S���z��</param>
    /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
    bool CollisionFunction::CollisionPair(const Sphere& sphere, const int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo)
    {
        collisionInfo = MV1CollCheck_Sphere(modelHandle, -1, sphere.GetWorldCenter(), sphere.GetRadius());
        if (collisionInfo.HitNum == 0)
        {
            return false;
        }
        return true;
    }

    /// <summary>
     /// �J�v�Z���ƃ��f���̓����蔻�菈��
     /// </summary>
     /// <param name="capsule">�J�v�Z��</param>
     /// <param name="modelHandle">���f���n���h��</param>
     /// <param name="collisionInfo">�R���W�������ʑ���p�|���S���z��</param>
     /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
    bool CollisionFunction::CollisionPair(const Capsule& capsule, const int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo)
    {
        MV1RefreshCollInfo(modelHandle);
        collisionInfo = MV1CollCheck_Capsule(modelHandle, -1, capsule.GetWorldStart(), capsule.GetWorldEnd(), capsule.GetRadius());
        if (collisionInfo.HitNum == 0)
        {
            return false;
        }
        return true;
    }

    /// <summary>
    /// �����ƃ��f���̓����蔻�菈��
    /// </summary>
    /// <param name="line">����</param>
    /// <param name="modelHandle">���f���n���h��</param>
    /// <param name="collisionInfo">�R���W�������ʑ���p�|���S���z��</param>
    /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
    bool CollisionFunction::CollisionPair(const LineSegment& line, const int modelHandle, MV1_COLL_RESULT_POLY& collisionInfo)
    {
        collisionInfo = MV1CollCheck_Line(modelHandle, -1, line.GetWorldStart(), line.GetWorldEnd());
        return collisionInfo.HitFlag;
    }

    /// <summary>
    /// ���̂ƃ��b�V���Ƃ̉����߂��ʌv�Z
    /// </summary>
    /// <param name="sphere">����</param>
    /// <param name="collisionInfo">�R���W�������ʑ���p�|���S���z��</param>
    /// <returns>�����߂���</returns>
    VECTOR CollisionFunction::CalcSpherePushBackVecFormMesh(const Sphere& sphere, const MV1_COLL_RESULT_POLY_DIM& collisionInfo)
    {
        //�Փˋ�

        //�����S
        VECTOR MoveCandidate = sphere.GetWorldCenter();
        //�����a
        float Radius = sphere.GetRadius();
        //�|���S�����ʖ@��
        VECTOR PlaneNormal;
        //�ړ��x�N�g��
        VECTOR MoveVec = VGet(0, 0, 0);
        //�ړ���
        float MoveLen = 0.0f;
        //�ړ����
        VECTOR NewCenter = MoveCandidate;
        for (int i = 0; i < collisionInfo.HitNum; i++)
        {
            //�Փ˃|���S���̕�
            VECTOR Edge1, Edge2;
            Edge1 = collisionInfo.Dim[i].Position[1] - collisionInfo.Dim[i].Position[0];
            Edge2 = collisionInfo.Dim[i].Position[2] - collisionInfo.Dim[i].Position[0];

            //�Փ˃|���S���̕ӂ��A�|���S���ʂ̖@���x�N�g�������߂�
            PlaneNormal = VCross(Edge1, Edge2);
            PlaneNormal = VNorm(PlaneNormal);

            //�����S�ɂ����Ƃ��߂��|���S�����ʂ̓_�����߂�
            VECTOR Distance = MoveCandidate - collisionInfo.Dim[i].Position[0];
            float Dot = VDot(PlaneNormal,Distance);

            //�Փ˓_
            VECTOR HitPos = MoveCandidate - (PlaneNormal * Dot);

            //�����ǂꂮ�炢�߂荞��ł��邩
            float Diff = VSize(MoveCandidate - HitPos);

            //�߂荞��ł���
            if (HitCheck_Sphere_Triangle(MoveCandidate, Radius,
                collisionInfo.Dim[i].Position[0],
                collisionInfo.Dim[i].Position[1],
                collisionInfo.Dim[i].Position[2]) == TRUE)
            {
                //�߂荞�݂���������܂ŉ����߂�
                VECTOR MoveVec;
                MoveVec = PlaneNormal * Diff;
                MoveCandidate += MoveVec;
            }
        }
        //�����߂��ʒu�̊m��
        NewCenter = MoveCandidate;

        //�����߂��ʂ�Ԃ�
        return NewCenter - sphere.GetWorldCenter();
    }
}