#include "GameObjectBase.h"
#include "../AssetManager/AssetManager.h"
#include "../VectorCalculation/VectorCalculation.h"

namespace Calculation
{   /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">オブジェクトタグ</param>
    GameObjectBase::GameObjectBase(ObjectTag tag) :
        tag(tag),
        pos(),
        modelHandle(-1),
        visible(true),
        alive(true),
        collisionType(),
        collisionLine(),
        collisionSphere(),
        collisionCapsule(),
        collisionModel(-1)
    {
    }

    /// <summary>
    /// コンストラクタ（初期位置指定）
    /// </summary>
    /// <param name="tag">オブジェクトタグ</param>
    /// <param name="pos">オブジェクトの初期座標</param>
    GameObjectBase::GameObjectBase(ObjectTag tag, VECTOR pos):
        tag(tag),
        pos(pos),
        modelHandle(-1),
        visible(true),
        alive(true),
        collisionType(),
        collisionLine(),
        collisionSphere(),
        collisionCapsule(),
        collisionModel(-1)
    {
    }

    /// <summary>
    /// デストラクタ
    /// </summary>
    GameObjectBase::~GameObjectBase()
    {
        if (modelHandle != -1)
        {
            //コリジョン情報の後始末
            MV1TerminateCollInfo(collisionModel);
            //モデルデータの後始末
            AssetManager::ReleaseMesh(modelHandle);
            modelHandle = -1;
        }
    }

    /// <summary>
    /// 当たり判定位置の更新
    /// </summary>
    void GameObjectBase::CollisionUpdate()
    {
        collisionSphere.Move(pos);
        collisionLine.Move(pos);
        collisionCapsule.Move(pos);

        //モデルの当たり判定情報を再構築
        if (collisionModel != -1)
        {
            MV1SetPosition(collisionModel, pos);
            MV1SetupCollInfo(collisionModel);
        }
    }

    /// <summary>
    /// 当たり判定の描画
    /// </summary>
    void GameObjectBase::DrawCollider()
    {
        //DrawLine3D(collisionLine.GetWorldStart(), collisionLine.GetWorldEnd(), GetColor(0, 0, 0));
        //DrawSphere3D(collisionSphere.GetWorldCenter(), collisionSphere.GetRadius(), 8, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
        //DrawCapsule3D(collisionCapsule.GetWorldStart(), collisionCapsule.GetWorldEnd(), collisionCapsule.GetRadius(), 8, GetColor(0, 255, 0), GetColor(0, 0, 0),FALSE);
        ////コリジョンモデルが存在していたら半透明描画
        //if (collisionModel != -1)
        //{
        //    //半透明にする
        //    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
        //    MV1DrawModel(collisionModel);
        //    //元に戻す
        //    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
        //}
    }
}