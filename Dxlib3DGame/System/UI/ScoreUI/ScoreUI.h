#pragma once
#include "DxLib.h"
#include "../UIBase/UIBase.h"
class Rule;
/// <summary>
/// スコア表示処理
/// </summary>
class ScoreUI : public UIBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    ScoreUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~ScoreUI();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

private:
    //フォントサイズ
    const int FontSize = 48;
    //文章のx座標
    const int StringPosX = 600;
    //文章のy座標
    const int StringPosY = 20;
    //文字の色
    const INT4 Black = { 0,0,0 };
    //ルールクラスのインスタンス
    Rule* rule;

    int score;
};