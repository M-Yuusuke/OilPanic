#pragma once
#include "../Sphere/Sphere.h"
#include "../LineSegment/LineSegment.h"
#include "../Capsule/Capsule.h"

namespace Calculation
{
    /// <summary>
    /// �����蔻��֐����܂Ƃ߂�N���X
    /// </summary>
    class CollisionFunction
    {
    public:
        //�����蔻��̊֐��g�ݍ��킹
        
        /// <summary>
        /// ���̓��m�̓����蔻�菈��
        /// </summary>
        /// <param name="sphereL">����1</param>
        /// <param name="sphereR">����2</param>
        /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
        bool CollisionPair(const Sphere& sphereL, const Sphere& sphereR);

        /// <summary>
        /// �����Ƌ��̂̓����蔻�菈��
        /// </summary>
        /// <param name="line">����</param>
        /// <param name="sphere">����</param>
        /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
        bool CollisionPair(const LineSegment& line, const Sphere& sphere);

        /// <summary>
        /// ���̂ƃ��f���̓����蔻�菈��
        /// </summary>
        /// <param name="sphere">����</param>
        /// <param name="modelHandle">���f���n���h��</param>
        /// <param name="collisionInfo">�R���W�������ʑ���p�|���S���z��</param>
        /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
        bool CollisionPair(const Sphere& sphere, const int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo);


        /// <summary>
        /// �J�v�Z���ƃ��f���̓����蔻�菈��
        /// </summary>
        /// <param name="capsule">�J�v�Z��</param>
        /// <param name="modelHandle">���f���n���h��</param>
        /// <param name="collisionInfo">�R���W�������ʑ���p�|���S���z��</param>
        /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
        bool CollisionPair(const Capsule& capsule, const int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo);



        /// <summary>
        /// �����ƃ��f���̓����蔻�菈��
        /// </summary>
        /// <param name="line">����</param>
        /// <param name="modelHandle">���f���n���h��</param>
        /// <param name="collisionInfo">�R���W�������ʑ���p�|���S���z��</param>
        /// <returns>�Փ˂��Ă����true�A���Ă��Ȃ����false</returns>
        bool CollisionPair(const LineSegment& line,const int modelHandle, MV1_COLL_RESULT_POLY& collisionInfo);

        /// <summary>
        /// ���̂ƃ��b�V���Ƃ̉����߂��ʌv�Z
        /// </summary>
        /// <param name="sphere">����</param>
        /// <param name="collisionInfo">�R���W�������ʑ���p�|���S���z��</param>
        /// <returns>�����߂���</returns>
        VECTOR CalcSpherePushBackVecFormMesh(const Sphere& sphere, const MV1_COLL_RESULT_POLY_DIM& collisionInfo);
    };
}


