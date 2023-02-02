#pragma once
#include "../UIBase/UIBase.h"
class Rule;
/// <summary>
/// プレイヤーのHPバー関連処理
/// </summary>
class PlayerUI : public UIBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PlayerUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~PlayerUI();

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
    //ルールクラスのインスタンス
    Rule* rule;

    int score;
};