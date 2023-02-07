#pragma once
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"
#include "../Player/Player.h"

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

        /// <summary>
        /// オイルの獲得数を返す
        /// </summary>
        /// <returns>現在のオイルの獲得数</returns>
        int GetAcquisition()const { return acquisition; }

    private:
        /// <summary>
        /// モデルロード
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// 移動処理
        /// </summary>
        void Move();

        /// <summary>
        /// 溜めたオイルを渡す処理
        /// </summary>
        void HandOver();

        //当たり判定球の中心点の座標
        const VECTOR FirstLocalPos = { 0,10.0f,0 };
        //プレイヤーが左向きの時のプレイヤーとの相対位置
        const VECTOR LeftRelativePos = { -50.0f,100.0f,0 };
        //プレイヤーが右向きの時のプレイヤーとの相対位置
        const VECTOR RightRelativePos = { 50.0f, 100.0f, 0 };
        //モデルの大きさ
        const VECTOR Scale = { 2.0f,2.0f,2.0f };
        //当たり判定球の半径
        const float Radius = 50.0f;
        //獲得上限
        const int AcquisitionLimit = 3;

        //プレイヤーのポインタ
        Player* player;
        //現在の獲得数
        int acquisition;
        //ゲームパッド入力状態
        XINPUT_STATE gamePadState;
    };
}

