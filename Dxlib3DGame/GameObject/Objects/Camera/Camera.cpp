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
        //カメラの描画距離の設定
        SetCameraNearFar(Near, Far);
        //カメラの視点、注視点を設定
        SetCameraPositionAndTarget_UpVecY(FirstCameraPos, Target);
    }
}