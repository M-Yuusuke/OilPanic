#include "DxLib.h"
#include "PlayerOil.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../System/Rule/Rule.h"
#include "../Bucket/Bucket.h"

namespace Calculation
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PlayerOil::PlayerOil(VECTOR& pos, int scale):
        GameObjectBase(ObjectTag::PlayerOil,pos)
    {
        magnification = (float)scale;
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// デストラクタ
    /// </summary>
    PlayerOil::~PlayerOil()
    {
    }

    /// <summary>
    /// 初期化処理
    /// </summary>
    void PlayerOil::Initialize()
    {
        //バケツの汲み取り量によってモデルの大きさを拡大
        scale = { FirstScale.x * magnification,FirstScale.y * magnification, FirstScale.z * magnification };
    }

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void PlayerOil::Update(float deltaTime)
    {
        //落下処理
        Drop(deltaTime);
        //コライダーの更新処理
        CollisionUpdate();
    }

    /// <summary>
    /// 描画処理
    /// </summary>
    void PlayerOil::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// 当たり判定処理
    /// </summary>
    /// <param name="other">当たったオブジェクトのポインタ</param>
    void PlayerOil::OnCollisionEnter(GameObjectBase* other)
    {
        ObjectTag tag = other->GetTag();
        //お手伝いとの当たり判定
        if (tag == ObjectTag::Helper)
        {
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
                //当たったら非表示
                visible = false;
                //ボーナス込みのスコア加算
                Rule::AcquisitionScore(bucket->GetAcquisition());
            }
        }
        if (tag == ObjectTag::Player)
        {
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
                //非表示
                visible = false;
                //
            }
        }
    }

    /// <summary>
    /// モデルデータの読み込み
    /// </summary>
    void PlayerOil::ModelLoad()
    {
        //モデルロード
        modelHandle = AssetManager::GetMesh("../Data/Assets/EXP/Model.mv1");

        //そのままだとステージに対してモデルが大きいので縮小
        MV1SetScale(modelHandle, scale);

        //モデルを配置
        MV1SetPosition(modelHandle, pos);

        //当たり判定球セット
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }

    /// <summary>
    /// 落下処理
    /// </summary>
    void PlayerOil::Drop(float deltaTime)
    {
        pos.y -= deltaTime * DropSpeed;
        MV1SetPosition(modelHandle, pos);
    }
}