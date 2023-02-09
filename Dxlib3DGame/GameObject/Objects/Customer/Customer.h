#pragma once
#include "../CharacterBase/CharacterBase.h"
namespace Calculation
{
    class Customer : public CharacterBase
    {
    public:
        Customer();
        ~Customer();

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize()override;

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="deltaTime">1フレームの経過時間</param>
        void Update(float deltaTime)override;

        /// <summary>
        /// 描画処理
        /// </summary>
        void Draw()override;

        /// <summary>
        /// 当たり判定処理
        /// </summary>
        /// <param name="other">衝突確認をするオブジェクトのポインタ</param>
        void OnCollisionEnter(GameObjectBase* other)override;
    private:
        /// <summary>
        /// モデルの読み込み
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// オイルに当たった時のリアクションを行う
        /// </summary>
        void Reaction();

        //モデルの初期配置
        const VECTOR FirstPos = { -500.0f,-500.0f,0 };
        //当たり判定球の中心のローカル座標
        const VECTOR FirstLocalPos = {};
        //当たり判定球の半径
        const float Radius = 30.0f;
    };
}