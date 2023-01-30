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
void PlayerUI::Update(int score)
{
    this->score = score;
}

/// <summary>
/// 描画処理
/// </summary>
void PlayerUI::Draw()
{
    //フォントサイズを指定
    SetFontSize(FontSize);
    //スコア表示
    DrawFormatString(50, 20, GetColor(255, 255, 255), "SCORE %d", score);
}