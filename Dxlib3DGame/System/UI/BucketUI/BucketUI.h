#pragma once
#include "Dxlib.h"
#include "../System/UI/UIBase/UIBase.h"
#include "../../../GameObject/Objects/Bucket/Bucket.h"

class BucketUI : public UIBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    BucketUI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~BucketUI();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update()override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;

private:
    //緑色
    const INT4 Green = { 0,255,0 };
    //黄色
    const INT4 Yellow = { 255,255,0 };
    //赤色
    const INT4 Red = { 255,0,0 };
    //黒色
    const INT4 Black = { 255,255,255 };

    //メータの拡大率
    const int Magnifincation = 100;
    //メータの左上のX座標
    const int MeterPosX = 600;
    //メータの左上のY座標
    const int MeterPosY = 50;
    //メータの縦幅
    const int MeterHeight = 50;
    //メータの幅の最大値
    const int MeterWidth = 500;
    //メータとフレームの差
    const int FrameSub = 5;
    //文字のx座標
    const int StringPosX = MeterPosX - 80;

    //バケツクラスのインスタンス
    Calculation::Bucket* bucket;

    //バケツの獲得数
    int acquisition;
    //色指定変数
    INT4 ColorNum;
};