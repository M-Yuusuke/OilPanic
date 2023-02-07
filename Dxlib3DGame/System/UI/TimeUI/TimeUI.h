#pragma once
#include "DxLib.h"
#include "../UIBase/UIBase.h"
class Rule;
/// <summary>
/// 残り時間処理
/// </summary>
class TimeUI : public UIBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    TimeUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TimeUI();

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
    const int StringPosX = 50;
    //文章のy座標
    const int StringPosY = 80;
    //文字の色
    const INT4 White = { 255,255,255 };
    //ルールクラスのインスタンス
    Rule* rule;

    float timeLimit;
};

