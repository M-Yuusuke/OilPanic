#pragma once
#include "../GameObject/GameObjectBase/GameObjectBase.h"
#include "../GameObject/AnimationController/AnimationController.h"

namespace Calculation
{
    class CharacterBase : public GameObjectBase
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        CharacterBase(ObjectTag tag);
        CharacterBase(ObjectTag tag, VECTOR pos);

        /// <summary>
        /// デストラクタ
        /// </summary>
        virtual ~CharacterBase() {}

        /// <summary>
        /// ダメージを受ける処理
        /// </summary>
        virtual void OnDamage() {}

        /// <summary>
        /// 残存HPを返す
        /// </summary>
        /// <returns>残存HP</returns>
        int GetHP()const { return hp; }

        /// <summary>
        /// 向いている方向ベクトルを返す
        /// </summary>
        /// <returns>向いている方向ベクトル</returns>
        VECTOR GetDir()const { return dir; }

        /// <summary>
        /// 攻撃中かどうかのフラグを返す
        /// </summary>
        /// <returns>攻撃フラグを返す</returns>
        bool IsAttack()const { return attack; }

        /// <summary>
        /// 防御中かかどうかのフラグを返す
        /// </summary>
        /// <returns>防御フラグを返す</returns>
        bool IsGuard()const { return guard; }

    protected:
        /// <summary>
        /// モデルとアニメーションの読み込み
        /// </summary>
        virtual void ModelLoad() = 0;
        /// <summary>
        /// 移動処理
        /// </summary>
        /// <param name="deltaTime">1フレームの経過時間</param>
        virtual void Move(float deltaTime) {}
        /// <summary>
        /// 回転処理
        /// </summary>
        void Rotate();

        /// <summary>
        /// プレイヤーとステージの当たり判定
        /// </summary>
        /// <param name="other">当たっているオブジェクトのポインタ</param>
        void OnCollisionStage(const GameObjectBase* other);

        //回転速度
        const float RotateVelocity = 10.0f;
        //向き
        VECTOR dir;
        //目標向き
        VECTOR aimDir;
        //速度
        VECTOR velocity;

        //アニメーション管理用
        AnimationController* animControl;
        //アニメーション種類ID
        int animTypeID;
        //回転中かどうか
        bool rotateNow;

        //残存HP
        int hp;

        //攻撃中か
        bool attack;
        //防御中か
        bool guard;
    };
}