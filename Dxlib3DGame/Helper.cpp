#include "Helper.h"
#include "../GameObject/AnimationController/AnimationController.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/AssetManager/AssetManager.h"

namespace Calculation
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Helper::Helper():
        CharacterBase(ObjectTag::Helper)
    {
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// デストラクタ
    /// </summary>
    Helper::~Helper()
    {
        modelHandle = -1;
    }

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Helper::Initialize()
    {
        animTypeID = 0;
        coolTime = MaxCoolTime;
    }

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Helper::Update(float deltaTime)
    {
        animControl->AddAnimationTime(deltaTime);
        Move(deltaTime);
        Rotate();
        CollisionUpdate();
    }

    /// <summary>
    /// 描画処理
    /// </summary>
    void Helper::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// 当たり判定処理
    /// </summary>
    /// <param name="other">衝突を確認したいオブジェクトのポインタ</param>
    void Helper::OnCollisionEnter(GameObjectBase* other)
    {
    }

    /// <summary>
    /// モデルの読み込み
    /// </summary>
    void Helper::ModelLoad()
    {
        //モデルの読み込み
        modelHandle = AssetManager::GetMesh("../Data/Assets/Josh/Model.mv1");

        //アニメーションを追加
        animControl->AddAnimation("../Data/Assets/Josh/Idle.mv1");      //待機モーション
        animControl->AddAnimation("../Data/Assets/Josh/Run.mv1");       //移動モーション

        //モデルを配置
        MV1SetPosition(modelHandle,pos);

        //待機モーションを再生開始
        animControl->StartAnimation(animTypeID);

        //当たり判定球セット
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }

    /// <summary>
    /// 移動処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Helper::Move(float deltaTime)
    {
        VECTOR RightDir = { 1,0,0 };
        VECTOR LeftDir = { -1,0,0 };

        if (coolTime > 0)
        {
            //停止時間の処理
            coolTime -= deltaTime;
        }
        if (coolTime <= 0)
        {
            //左端の移動制限まで来たら反転
            if (pos.x <= -MoveLimit)
            {
                dir = RightDir;
                coolTime = MaxCoolTime;
            }
            //右端の移動制限まで来たら反転
            if (pos.x >= MoveLimit)
            {
                dir = LeftDir;
                coolTime = MaxCoolTime;
            }
            pos += dir * deltaTime * MoveSpeed;
            MV1SetPosition(modelHandle,pos);
        }
    }
}
