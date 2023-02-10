#pragma once
#include "../SceneBase/SceneBase.h"
class ScoreUI;
class BucketUI;
class TimeUI;
class Play : public SceneBase
{
public:
    /// <summary>
    /// Playシーンのインスタンス生成
    /// </summary>
    /// <returns>Playシーンのインスタンス</returns>
    static Play* CreateInstance();

    /// <summary>
    /// Playシーンのインスタンス破棄
    /// </summary>
    static void DestroyInstance();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <returns>現在のシーンもしくは次のシーンポインタ</returns>
    SceneBase* Update()override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    Play();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Play();

    static Play* Instance;

    ScoreUI* scoreUI;
    BucketUI* bucketUI;
    TimeUI* timeUI;
};

