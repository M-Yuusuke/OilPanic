#pragma once
class UIBase
{
public:
    /// <summary>
    /// コンストラクタ(フォントデータの読み込み)
    /// </summary>
    UIBase();

    /// <summary>
    /// デストラクタ(フォントデータの破棄)
    /// </summary>
    virtual ~UIBase();

    /// <summary>
    /// 更新処理
    /// </summary>
    virtual void Update() {}

    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw() = 0;
};

