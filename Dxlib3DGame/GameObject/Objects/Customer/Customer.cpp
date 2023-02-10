#include "DxLib.h"
#include "Customer.h"
#include "../PlayerOil/PlayerOil.h"
#include "../System/Rule/Rule.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/AnimationController/AnimationController.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"

namespace Calculation
{
    Customer::Customer():
        CharacterBase(ObjectTag::Customer)
    {
        Initialize();
        ModelLoad();
    }

    Customer::~Customer()
    {
        //モデルデータを削除
        AssetManager::ReleaseMesh(modelHandle);
        modelHandle = -1;
        //アニメーションコントローラを削除
        delete animControl;
        animControl = nullptr;
    }

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Customer::Initialize()
    {
        //初期座標に配置
        pos = FirstPos;
        //右向き
        dir = { 1.0f,0,0 };
    }

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Customer::Update(float deltaTime)
    {
        animControl->AddAnimationTime(deltaTime);
        Rotate();
        CollisionUpdate();
    }

    /// <summary>
    /// 描画処理
    /// </summary>
    void Customer::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// 当たり判定処理
    /// </summary>
    /// <param name="other">衝突確認をするオブジェクトのポインタ</param>
    void Customer::OnCollisionEnter(GameObjectBase* other)
    {
        ObjectTag tag = other->GetTag();
        //汲み取ったオイルとの当たり判定
        if (tag == ObjectTag::PlayerOil)
        {
            //当たり判定球同士が当たったら
            if (collisionFunction.CollisionPair(other->GetCollisionSphere(), collisionSphere))
            {
                //当たった際のリアクション
                Reaction();
                //ミスカウントを加算
                Rule::AddMissCount();
            }
        }
    }

    /// <summary>
    /// オイルに当たった時のリアクションを行う
    /// </summary>
    void Customer::Reaction()
    {
        //怒りモーション中でなければ怒りモーションを再生
        if (animTypeID != 1)
        {
            animTypeID = 1;
            animControl->StartAnimation(animTypeID);
        }

        //怒りモーションが再生中でなければ待機モーションを再生
        if (!animControl->IsPlaying(1))
        {
            animTypeID = 0;
            animControl->StartAnimation(animTypeID);
        }
    }

    /// <summary>
    /// モデルの読み込み
    /// </summary>
    void Customer::ModelLoad()
    {
        //モデル読み込み
        modelHandle = AssetManager::GetMesh("../Data/Assets/Alex/Model.mv1");
        //アニメーションコントローラを生成
        animControl = new AnimationController(modelHandle);

        //アニメーションデータ読み込み
        animControl->AddAnimation("../Data/Assets/Alex/Idle.mv1");   //待機モーション
        animControl->AddAnimation("../Data/Assets/Alex/Angry.mv1");  //怒りモーション

        //モデルを指定の座標に配置
        MV1SetPosition(modelHandle, pos);

        //待機モーションをセット
        animControl->StartAnimation(animTypeID);

        //当たり判定球セット
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }
}