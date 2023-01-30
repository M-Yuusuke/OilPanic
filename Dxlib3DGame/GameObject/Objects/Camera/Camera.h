#pragma once
#include "../../GameObjectBase/GameObjectBase.h"

namespace Calculation 
{
    /// <summary>
    /// カメラ関連処理を行うクラス
    /// </summary>
    class Camera : public GameObjectBase
    {
    public:
        /// <summary>
        /// コンストラクタ（シングルトン）
        /// </summary>
        Camera();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Camera();

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize()override;

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="deltaTime">1フレームの経過時間</param>
        void Update(float deltaTime) override {}

    private:
        //カメラの初期座標
        const VECTOR FirstCameraPos = { 0,300.0f,-700.0f };
        //カメラの注視点を設定
        const VECTOR Target = { 0,100.0f,100.0f };

        //描画距離の下限
        const float Near = 10.0f;
        //描画距離の上限
        const float Far = 3000.0f;
    };
}


