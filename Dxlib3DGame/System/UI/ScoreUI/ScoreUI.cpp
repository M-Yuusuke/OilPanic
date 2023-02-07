#include "ScoreUI.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/ObjectTag.h"
#include "../System/Rule/Rule.h"

/// <summary>
/// コンストラクタ
/// </summary>
ScoreUI::ScoreUI():
    score(0),
    rule(nullptr)
{
    rule = Rule::CreateInstance();
}

/// <summary>
/// デストラクタ
/// </summary>
ScoreUI::~ScoreUI()
{
    Rule::DestoryInstance();
}

/// <summary>
/// 更新処理
/// </summary>
void ScoreUI::Update()
{
    score = rule->GetScore();
}

/// <summary>
/// 描画処理
/// </summary>
void ScoreUI::Draw()
{
    //フォントサイズを指定
    SetFontSize(FontSize);
    //スコア表示
    DrawFormatString(StringPosX, StringPosY, GetColor(Black.x, Black.y, Black.z), "SCORE %d", score);
}