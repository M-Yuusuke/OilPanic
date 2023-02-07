#pragma once
#include "../GameObject/GameObjectBase/GameObjectBase.h"
namespace Calculation
{
    class Background : public GameObjectBase
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Background();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Background();

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="deltaTime">1フレームの経過時間</param>
        void Update(float deltaTime)override {}

        /// <summary>
        /// 描画処理
        /// </summary>
        void Draw()override;

    private:
        //画像ハンドルを保存する変数
        int img;
    };
}

