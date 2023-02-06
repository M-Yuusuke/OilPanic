#pragma once
#include "../GameObject/GameObjectBase/GameObjectBase.h"
namespace Calculation
{
    class Oil :public GameObjectBase
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Oil();
        Oil(VECTOR pos);

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Oil();

        /// <summary>
        /// 初期化処理
        /// </summary>
        void Initialize() override;

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
        /// <param name="other">当たっているオブジェクトのポインタ</param>
        void OnCollisionEnter(GameObjectBase* other)override;

    private:
        /// <summary>
        /// モデルの読み込み
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// 落下処理
        /// </summary>
        /// <param name="deltaTime">1フレームの経過時間</param>
        void Drop(float deltaTime);

        //モデルの大きさ
        const VECTOR Scale = { 0.25f,0.25f,0.25f };
        //落下速度
        const float DropSpeed = -100.0f;
        //当たり判定球の中心座標
        const VECTOR FirstLocalPos = { 0,25.0f,0 };
        //当たり判定球の半径
        const float Radius = 20.0f;

        //ミスした回数
        static int missCount;
        
        //落下の下限値
        const float LowerLimitPosY = 250.0f;
        //落下クールタイムの最大値(乱数)
        float MaxCoolTime;
        //クールタイムを保存する変数
        float CoolTime;
        //初期値を保存するための変数
        VECTOR FirstPos;
    };
}

