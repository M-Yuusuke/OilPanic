#include "../GameObject/Objects/CharacterBase/CharacterBase.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
namespace Calculation
{
    CharacterBase::CharacterBase(ObjectTag tag):
        GameObjectBase(tag),
        dir({0,0,0}),
        aimDir({0,0,0}),
        velocity({0,0,0}),
        animControl(nullptr),
        animTypeID(0),
        rotateNow(false)
    {
    }

    CharacterBase::CharacterBase(ObjectTag tag, VECTOR pos) :
        GameObjectBase(tag,pos),
        dir({ 0,0,0 }),
        aimDir({ 0,0,0 }),
        velocity({ 0,0,0 }),
        animControl(nullptr),
        animTypeID(0),
        rotateNow(false)
    {
    }

    /// <summary>
    /// ��]����
    /// </summary>
    void CharacterBase::Rotate()
    {
        if (rotateNow)
        {
            //��]���ڕW�p�x�ɏ\���߂���Ή�]���[�h�I��
            if (IsNearAngle(aimDir, dir))
            {
                dir = aimDir;
                rotateNow = false;
            }
            else
            {
                //��]������
                VECTOR interPolateDir;
                interPolateDir = RotateForAimVecYAxis(dir, aimDir, RotateVelocity);

                //��]���ڕW�p�x�𒴂��Ă��Ȃ���
                VECTOR cross1, cross2;
                cross1 = VCross(dir, aimDir);
                cross2 = VCross(interPolateDir, aimDir);

                //�ڕW�p�x�𒴂�����I��
                if (cross1.y * cross2.y < 0)
                {
                    interPolateDir = aimDir;
                    rotateNow = false;
                }
                //�ڕW�x�N�g����10�x�����߂Â����p�x
                dir = interPolateDir;
            }
        }
        //�����ɍ��킹�ă��f������]
        //mixamo�̃��f����X�������Ό����ɏo��̂ł܂��x�N�g����180�x��]������
        MATRIX RotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
        dir.y = 0;
        VECTOR NegativeVec = VTransform(dir, RotYMat);

        //���f���ɉ�]���Z�b�g����
        MV1SetRotationZYAxis(modelHandle, NegativeVec, { 0,1.0f,0 }, 0);
    }

    void CharacterBase::OnCollisionStage(const GameObjectBase* other)
    {
        int ColModel = other->GetCollisionModel();

        //�X�e�[�W�Ǝ����̋��E���Ƃ̓����蔻��
        MV1_COLL_RESULT_POLY_DIM colInfo;
        if (collisionFunction.CollisionPair(collisionSphere, ColModel, colInfo))
        {
            //�������Ă���ꍇ�͉����߂��ʂ��v�Z
            VECTOR pushBackVec = collisionFunction.CalcSpherePushBackVecFormMesh(collisionSphere, colInfo);
            pos += pushBackVec;

            //�R���W�������̉��
            MV1CollResultPolyDimTerminate(colInfo);
            CollisionUpdate();
        }

        ////�X�e�[�W�Ƒ������������蔻��
        //MV1_COLL_RESULT_POLY colInfoLine;
        //if (collisionFunction.CollisionPair(collisionLine, ColModel, colInfoLine))
        //{
        //    //�������Ă���ꍇ�͑������Փ˓_�ɍ��킹��
        //    pos = colInfoLine.HitPosition;
        //    CollisionUpdate();
        //}
    }
    
}