#include "PlayerUI.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/ObjectTag.h"
#include "../System/Rule/Rule.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerUI::PlayerUI():
    score(0),
    rule(nullptr)
{
    rule = Rule::CreateInstance();
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
    this->score = rule->GetScore();
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