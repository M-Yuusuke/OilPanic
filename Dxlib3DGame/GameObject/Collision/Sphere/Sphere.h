#pragma once
#include "../CollisionBase/CollisionBase.h"
namespace Calculation
{
    class Sphere : public CollisionBase
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Sphere() { WorldCenter = { 0, 0, 0 }, LocalCenter = { 0,0,0 } ;}

        /// <summary>
        /// デストラクタ
        /// </summary>
        Sphere(const VECTOR& center, float radius);

        /// <summary>
        /// 移動処理
        /// </summary>
        /// <param name="pos">オブジェクトのワールド座標</param>
        void Move(const VECTOR& pos)override;

        /// <summary>
        /// センターのローカル座標・ワールド座標をセット
        /// </summary>
        /// <param name="pos">オブジェクトのワールド座標</param>
        void SetLocalCenter(const VECTOR& pos);

        /// <summary>
        /// 当たり判定球の半径をセット
        /// </summary>
        /// <param name="radius"></param>
        void SetRadius(const float radius) { Radius = radius; }

        /// <summary>
        /// 当たり判定球の中心のワールド座標を返す
        /// </summary>
        /// <returns>当たり判定球の中心のワールド座標</returns>
        VECTOR GetWorldCenter() const { return WorldCenter; }

    private:
        //センターのローカル座標
        VECTOR LocalCenter;
        //センターのワールド座標
        VECTOR WorldCenter;
    };
}


