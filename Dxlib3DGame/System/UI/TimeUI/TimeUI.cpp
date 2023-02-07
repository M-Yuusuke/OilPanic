#include "TimeUI.h"
#include "../System/Rule/Rule.h"

/// <summary>
/// コンストラクタ
/// </summary>
TimeUI::TimeUI():
    timeLimit(0),
    rule(nullptr)
{
    rule = Rule::CreateInstance();
}

/// <summary>
/// デストラクタ
/// </summary>
TimeUI::~TimeUI()
{
    Rule::DestoryInstance();
}

/// <summary>
/// 更新処理
/// </summary>
void TimeUI::Update()
{
    timeLimit = rule->GetTimeLimit();
}

/// <summary>
/// 描画処理
/// </summary>
void TimeUI::Draw()
{
    //フォントサイズを指定
    SetFontSize(FontSize);
    //スコア表示
    DrawFormatString(StringPosX, StringPosY, GetColor(White.x, White.y, White.z), "Time %2.0f", timeLimit);
}
