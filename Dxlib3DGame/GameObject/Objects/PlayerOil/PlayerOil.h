#pragma once
#include "../GameObject/GameObjectBase/GameObjectBase.h"
namespace Calculation
{
    /// <summary>
    /// プレイヤーが汲み取ったオイルに関する処理を行うクラス
    /// </summary>
    class PlayerOil : public GameObjectBase
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        PlayerOil(VECTOR& pos,int scale);

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~PlayerOil();

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
        /// <param name="other">当たったオブジェクトのポインタ</param>
        void OnCollisionEnter(GameObjectBase* other)override;

    private:
        /// <summary>
        /// モデルデータの読み込み
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// 落下処理
        /// </summary>
        void Drop(float deltaTime);

        //落下速度
        const float DropSpeed = 500.0f;
        //落下の下限値
        const float LowerLimitPosY = -500.0f;
        //当たり判定球の半径
        const float Radius = 30.0f;
        //ローカル座標
        const VECTOR FirstLocalPos = { 0,0,0 };
        //初期モデルの大きさ
        const VECTOR FirstScale = { 0.125f,0.125f,0.125f };
        //モデルの配置
        const VECTOR Position = { 200.0f,100.0f,0 };

        //モデルの大きさ
        VECTOR scale;
        //拡大率
        float magnification;
    };
}

