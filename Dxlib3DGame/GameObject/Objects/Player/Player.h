#pragma once
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"
#include "../System/UI/PlayerUI/PlayerUI.h"
namespace Calculation
{
    /// <summary>
    /// プレイヤー関連処理を行うクラス
    /// </summary>
    class Player : public CharacterBase
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Player();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Player();

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
        /// <param name="other">当たっているオブジェクトのポインタ</param>
        void OnCollisionEnter(GameObjectBase* other)override;

    private:
        /// <summary>
        /// モデルの読み込み
        /// </summary>
        void ModelLoad()override;

        /// <summary>
        /// 入力処理
        /// </summary>
        /// <param name="deltaTime">1フレームの経過時間</param>
        void Move(float deltaTime)override;

        /// <summary>
        /// 溜めたオイルを渡す処理
        /// </summary>
        void HandOver();

        //プレイヤーの大きさ
        const VECTOR PlayerScale = { 0.5f,0.5f, 0.5f };
        //プレイヤーの初期座標
        const VECTOR FirstPos = { 0,100,0 };
        //プレイヤーの初期向き
        const VECTOR FirstDir = { 1,0,0 };

        //球の初期ローカル座標
        const VECTOR FirstLocalPos = { 0, 50.0f, 0 };

        //球状の当たり判定の半径
        const float Radius = 40.0f;
        //入力ベクトルの最小値
        const float InputVecMin = 0.5f;
        //移動速度
        const float MoveSpeed = 200.0f;

        //ゲームパッド入力状態
        XINPUT_STATE gamePadState;
    };
}