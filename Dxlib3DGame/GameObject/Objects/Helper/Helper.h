#pragma once
#include "../CharacterBase/CharacterBase.h"
namespace Calculation
{
    class Helper : public CharacterBase
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Helper();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Helper();

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
        /// <param name="other">衝突を確認したいオブジェクトのポインタ</param>
        void OnCollisionEnter(GameObjectBase* other)override;

    private:
        /// <summary>
        /// モデルの読み込み
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// 移動処理
        /// </summary>
        /// <param name="deltaTime">1フレームの経過時間</param>
        void Move(float deltaTime)override;

        //当たり判定球の初期配置
        const VECTOR FirstLocalPos = { 0,50.0f,0 };
        //モデルの初期位置
        const VECTOR FirstPos = { 350.0f,-100.0f,0 };
        //当たり判定球の半径
        const float Radius = 30.0f;
        //最大停止時間
        const float MaxCoolTime = 5.0f;
        //移動速度
        const float MoveSpeed = 300.0f;
        //移動制限
        const float MoveLimitX = 350.0f;

        //移動停止時間
        float coolTime;
    };
}

