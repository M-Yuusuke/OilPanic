#pragma once
#include "../UIBase/UIBase.h"
#include "../GameObject/Objects/Player/Player.h"
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
    void Update(int score);

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

private:
    //PlayerUIのフォントサイズ
    const int FontSize = 48;

    //HPゲージの色
    const INT4 HpColor = { 0,0,255 };

    //ゲージの拡大率
    const int Magnifincation = 5;
    //ゲージの左端の位置
    const int MeterPosX = 200;
    //ゲージの縦幅
    const int MeterHeight = 50;
    //ゲージの幅の最大値
    const int MeterWidth = 500;
    //ゲージとフレームの差
    const int FrameSub = 5;
    //HPゲージのY座標
    const int HpMeterPosY = 50;
    //HPの文字のx座標
    const int HpStringPosX = MeterPosX - 80;
    //白色
    const INT4 White = { 255,255,255 };

    int hp;
    int score;
};