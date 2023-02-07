#include "Oil.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../System/Rule/Rule.h"

namespace Calculation
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Oil::Oil():
        GameObjectBase(ObjectTag::Oil)
    {
        FirstPos = { 0,0,0 };
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Oil::Oil(VECTOR pos):
        GameObjectBase(ObjectTag::Oil, pos)
    {
        FirstPos = pos;
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// デストラクタ
    /// </summary>
    Oil::~Oil()
    {
    }

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Oil::Initialize()
    {
        //モデルを非表示
        visible = false;
        //設定されたポジションにセット
        pos = FirstPos;
        //1～5秒のクールタイムをセット
        MaxCoolTime = (float)(1 + GetRand(9));
        //クールタイムを設定
        CoolTime = MaxCoolTime;
    }

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Oil::Update(float deltaTime)
    {
        //落下処理
        Drop(deltaTime);
        //当たり判定の更新処理
        CollisionUpdate();
    }

    /// <summary>
    /// 描画処理
    /// </summary>
    void Oil::Draw()
    {
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// 当たり判定処理
    /// </summary>
    /// <param name="other">当たっているオブジェクトのポインタ</param>
    void Oil::OnCollisionEnter(GameObjectBase* other)
    {
        //衝突オブジェクトのタグを取得
        ObjectTag tag = other->GetTag();
        //プレイヤーと衝突した場合
        if (tag == ObjectTag::Bucket)
        {
        }
    }

    /// <summary>
    /// モデルの読み込み
    /// </summary>
    void Oil::ModelLoad()
    {
        //モデルロード　モデルデータは仮なので後に変更
        modelHandle = AssetManager::GetMesh("../Data/Assets/Oil/Model.mv1");

        //モデルの大きさをセット
        MV1SetScale(modelHandle, Scale);

        //モデルをセット
        MV1SetPosition(modelHandle, pos);

        //当たり判定球セット
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);
    }

    /// <summary>
    /// 落下処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Oil::Drop(float deltaTime)
    {
        if (CoolTime > 0)
        {
            //クールタイムを減算
            CoolTime -= deltaTime;
        }
        //クールタイムが0になれば落下
        if (CoolTime <= 0)
        {
            visible = true;
            pos.y += deltaTime * DropSpeed;
            MV1SetPosition(modelHandle, pos);
        }

        //posのY座標が下限値を下回ったら初期化
        if(pos.y <= LowerLimitPosY)
        {
            //非表示
            visible = false;
            //ミスカウント加算
            Rule::AddMissCount();
            //初期化
            Initialize();
        }
    }
}