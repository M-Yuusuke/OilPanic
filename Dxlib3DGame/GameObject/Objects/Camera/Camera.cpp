#include "Camera.h"
#include "../../VectorCalculation/VectorCalculation.h"
#include "../../GameObjectManager/GameObjectManager.h"
#include "../../ObjectTag.h"

namespace Calculation
{
    //Camera* Camera::Instance = nullptr;
    Camera::Camera():
    Calculation::GameObjectBase(ObjectTag::Camera)
    {
    }

    Camera::~Camera()
    {
    }

    void Camera::Initialize()
    {
        //�J�����̕`�拗���̐ݒ�
        SetCameraNearFar(Near, Far);
        //�J�����̎��_�A�����_��ݒ�
        SetCameraPositionAndTarget_UpVecY(FirstCameraPos, Target);
    }
}