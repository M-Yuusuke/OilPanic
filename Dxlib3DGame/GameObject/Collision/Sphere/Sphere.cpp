#include "Sphere.h"
#include "../../VectorCalculation/VectorCalculation.h"

namespace Calculation
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Sphere::Sphere(const VECTOR& center, float radius)
    {
        LocalCenter = center;
        WorldCenter = center;
        Radius = radius;
    }

    /// <summary>
    /// 移動処理
    /// </summary>
    /// <param name="pos">オブジェクトのワールド座標</param>
    void Sphere::Move(const VECTOR& pos)
    {
        WorldCenter = LocalCenter + pos;
    }

    /// <summary>
    /// センターのローカル座標・ワールド座標をセット
    /// </summary>
    /// <param name="pos">オブジェクトのワールド座標</param>
    void Sphere::SetLocalCenter(const VECTOR& pos)
    {
        LocalCenter = pos;
        WorldCenter = LocalCenter;
    }
}