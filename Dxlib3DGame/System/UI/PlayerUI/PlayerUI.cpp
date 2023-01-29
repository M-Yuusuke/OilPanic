#include "PlayerUI.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/Objects/Player/Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerUI::PlayerUI():
    hp(0)
{
}

/// <summary>
/// デストラクタ
/// </summary>
PlayerUI::~PlayerUI()
{
}

/// <summary>
/// 更新処理
/// </summary>
void PlayerUI::Update()
{
    //Calculation::Player* player = static_cast<Calculation::Player*>(Calculation::GameObjectManager::GetFirstGameObject(Calculation::ObjectTag::Player));
    //hp = player->GetHP();
}

/// <summary>
/// 描画処理
/// </summary>
void PlayerUI::Draw()
{
    //SetFontSize(FontSize);
    //DrawString(HpStringPosX, HpMeterPosY, "HP", GetColor(White.x, White.y, White.z));
    ////HPゲージフレーム
    //DrawBox(MeterPosX - FrameSub, HpMeterPosY - FrameSub, MeterPosX + MeterWidth + FrameSub, HpMeterPosY + MeterHeight + FrameSub, GetColor(0, 0, 0), TRUE);
    ////HPゲージ
    //DrawBox(MeterPosX, HpMeterPosY, MeterPosX + (hp * Magnifincation), HpMeterPosY + MeterHeight, GetColor(HpColor.x, HpColor.y, HpColor.z), TRUE);
}