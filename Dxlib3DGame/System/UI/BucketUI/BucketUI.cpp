#include "BucketUI.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/Objects/Bucket/Bucket.h"

/// <summary>
/// コンストラクタ
/// </summary>
BucketUI::BucketUI():
    acquisition(0)
{
}

/// <summary>
/// デストラクタ
/// </summary>
BucketUI::~BucketUI()
{
}

/// <summary>
/// 更新処理
/// </summary>
void BucketUI::Update()
{
    if (!bucket)
    {
        bucket = static_cast<Calculation::Bucket*>(Calculation::GameObjectManager::GetFirstGameObject(Calculation::ObjectTag::Bucket));
    }
    acquisition = bucket->GetAcquisition();
    //if (CheckHitKey(KEY_INPUT_UP))
    //{
    //    acquisition++;
    //}
    //if (CheckHitKey(KEY_INPUT_DOWN))
    //{
    //    acquisition--;
    //}

    switch (acquisition)
    {
    case 1:
        ColorNum.x = Green.x;
        ColorNum.y = Green.y;
        ColorNum.z = Green.z;
        break;
    case 2:
        ColorNum.x = Yellow.x;
        ColorNum.y = Yellow.y;
        ColorNum.z = Yellow.z;
        break;
    case 3:

        ColorNum.x = Red.x;
        ColorNum.y = Red.y;
        ColorNum.z = Red.z;
        break;
    default:
        break;
    }
}

/// <summary>
/// 描画処理
/// </summary>
void BucketUI::Draw()
{
    //メータの枠
    DrawBox(MeterPosX - FrameSub, MeterPosY - FrameSub, MeterPosX + MeterWidth + FrameSub, MeterPosY + MeterHeight + FrameSub, GetColor(Black.x, Black.y, Black.z), TRUE);
    //メータ
    DrawBox(MeterPosX, MeterPosY + MeterHeight, MeterPosX + MeterWidth, (MeterPosY + MeterHeight) - (acquisition * Magnifincation), GetColor(ColorNum.x, ColorNum.y, ColorNum.z), TRUE);
}