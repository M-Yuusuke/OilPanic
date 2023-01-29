#pragma once
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"

namespace Calculation
{
    class Bucket : public CharacterBase
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Bucket();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Bucket();

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize();

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="deltaTime">1フレームの経過時間</param>
        void Update(float deltaTime)override;

        /// <summary>
        /// 描画処理
        /// </summary>
        void Draw();

        /// <summary>
        /// 当たり判定処理
        /// </summary>
        /// <param name="Obj">オブジェクトのポインタ</param>
        void OnCollisionEnter(GameObjectBase* other)override;

    private:
        /// <summary>
        /// モデルロード
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// 移動処理
        /// </summary>
        void Move();

        //当たり判定球の中心点の座標
        const VECTOR FirstLocalPos = { 0,70.0f,0 };
        //プレイヤーが左向きの時のプレイヤーとの相対位置
        const VECTOR LeftRelativePos = { -100.0f,0,0 };
        //プレイヤーが右向きの時のプレイヤーとの相対位置
        const VECTOR RightRelativePos = { 100.0f, 0, 0 };
        //当たり判定球の半径
        const float Radius = 30.0f;
        //プレイヤーのポインタ
        CharacterBase* player;
        
    };
}

