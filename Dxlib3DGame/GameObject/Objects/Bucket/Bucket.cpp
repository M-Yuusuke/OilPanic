#include "Bucket.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/Objects/CharacterBase/CharacterBase.h"
#include "../System/Rule/Rule.h"
#include "../Oil/Oil.h"

namespace Calculation
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Bucket::Bucket():
        CharacterBase(ObjectTag::Bucket)
    {
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// デストラクタ
    /// </summary>
    Bucket::~Bucket()
    {
        AssetManager::ReleaseMesh(modelHandle);
        modelHandle = -1;
    }

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Bucket::Initialize()
    {
        //獲得数の初期化
        acquisition = 0;
    }

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Bucket::Update(float deltaTime)
    {
        //移動処理
        Move();
        //当たり判定の更新処理
        CollisionUpdate();
    }

    /// <summary>
    /// 描画処理
    /// </summary>
    void Bucket::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// 当たり判定処理
    /// </summary>
    /// <param name="Obj">オブジェクトのポインタ</param>
    void Bucket::OnCollisionEnter(GameObjectBase* other)
    {
        ObjectTag tag = other->GetTag();
        if (tag == ObjectTag::Oil)
        {
            //球体同士の当たり判定
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
                //獲得数が上限値よりも小さい場合のみ獲得(獲得上限3回)
                if (acquisition < AcquisitionLimit)
                {
                    //現在の獲得数を加算
                    acquisition++;
                    //獲得できたら初期化
                    static_cast<Oil*>(other)->Initialize();
                    //スコア加算
                    Rule::AcquisitionScore();
                }
            }
        }
    }

    /// <summary>
    /// モデルロード
    /// </summary>
    void Bucket::ModelLoad()
    {
        //モデルデータの読み込み
        modelHandle = AssetManager::GetMesh("../Data/Assets/Bucket/Model.mv1");
        //モデルの大きさのセット
        MV1SetScale(modelHandle,Scale);
        //モデルの配置
        MV1SetPosition(modelHandle, pos);

        //当たり判定球セット
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }

    /// <summary>
    /// 移動処理(プレイヤーを基準に配置)
    /// </summary>
    void Bucket::Move()
    {
        if (!player)
        {
            player = static_cast<CharacterBase*>(GameObjectManager::GetFirstGameObject(ObjectTag::Player));
        }
        //プレイヤーの向いている方向を取得
        VECTOR dir = player->GetDir();
        //プレイヤーが右を向いていたら
        if (dir.x > 0)
        {
            //プレイヤーの正面に配置
            pos = player->GetPos() + RightRelativePos;
        }
        //プレイヤーが左を向いていたら
        if (dir.x < 0)
        {
            //プレイヤーの正面に配置
            pos = player->GetPos() + LeftRelativePos;
        }
        //モデルの配置
        MV1SetPosition(modelHandle, pos);
    }
}