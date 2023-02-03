#include "Player.h"
#include <math.h>
#include "../GameObject/VectorCalculation/VectorCalculation.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/AssetManager/AssetManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/Collision/CollisionFunction/CollisionFunction.h"
#include "../System/Rule/Rule.h"

namespace Calculation
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Player::Player() :
        CharacterBase(ObjectTag::Player)
    {
        Initialize();
        ModelLoad();
    }

    /// <summary>
    /// デストラクタ
    /// </summary>
    Player::~Player()
    {
        AssetManager::ReleaseMesh(modelHandle);
        delete animControl;
        modelHandle = -1;
        collisionModel = -1;
    }

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Player::Initialize()
    {
        dir = { 0,0,0 };
        aimDir = { 0,0,0 };
        velocity = { 0,0,0 };
        animTypeID = 0;
        rotateNow = false;
        attack = false;

        pos = FirstPos;
        dir = FirstDir;
        aimDir = dir;
    }

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Player::Update(float deltaTime)
    {
        animControl->AddAnimationTime(deltaTime);
        Rotate();
        Move(deltaTime);

        //当たり判定モデルも位置更新
        CollisionUpdate();
    }

    /// <summary>
    /// 描画処理
    /// </summary>
    void Player::Draw()
    {
        //3Dモデルの描画
        MV1DrawModel(modelHandle);
        DrawCollider();
    }

    /// <summary>
    /// 当たり判定処理
    /// </summary>
    /// <param name="other">当たっているオブジェクトのポインタ</param>
    void Player::OnCollisionEnter(GameObjectBase* other)
    {
        ObjectTag tag = other->GetTag();

        //ステージとの衝突
        if (tag == ObjectTag::Stage)
        {
            OnCollisionStage(other);
        }
    }

    /// <summary>
    /// モデルの読み込み
    /// </summary>
    void Player::ModelLoad()
    {
        //モデルロード
        modelHandle = AssetManager::GetMesh("../Data/Assets/Remy/Model.mv1");

        //そのままだとステージに対してモデルが大きいので縮小
        MV1SetScale(modelHandle, PlayerScale);

        //アニメーションコントローラーの生成
        animControl = new AnimationController(modelHandle);

        //アニメーションロード
        animControl->AddAnimation("../Data/Assets/Remy/Idle.mv1");  //待機モーション
        animControl->AddAnimation("../Data/Assets/Remy/Run.mv1");   //走りモーション

        //待機モーションをセット
        animControl->StartAnimation(animTypeID);

        //当たり判定球セット
        collisionType = CollisionType::Sphere;
        collisionSphere.SetLocalCenter(FirstLocalPos);
        collisionSphere.SetRadius(Radius);

        //足元当たり判定線分セット
        //collisionLine = LineSegment(LineStart, LineEnd);
    }

    /// <summary>
    /// 入力処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Player::Move(float deltaTime)
    {
        //キー入力状態取得
        GetJoypadXInputState(DX_INPUT_PAD1, &gamePadState);
        VECTOR LEFT = { -1,0,0 };
        VECTOR RIGHT = { 1,0,0 };

        VECTOR inputVec = { 0,0,0 };
        //入力状態
        bool input = false;
        //左を入力していたら左に進む
        if (CheckHitKey(KEY_INPUT_A) || gamePadState.ThumbLX < 0 || gamePadState.Buttons[2])
        {
            inputVec += LEFT;
            input = true;
        }
        //右を入力していたら右に進む
        if (CheckHitKey(KEY_INPUT_D) || gamePadState.ThumbLX > 0 || gamePadState.Buttons[3])
        {
            inputVec += RIGHT;
            input = true;
        }

        //入力があったら加速
        if (input)
        {
            //上下・左右同時押しなどで入力ベクトルが0の時は無視
            if (VSquareSize(inputVec) < InputVecMin)
            {
                return;
            }
            //方向を正規化
            inputVec = VNorm(inputVec);

            //入力方向は現在向いてる向きと異なるか？
            if (IsNearAngle(inputVec, dir))
            {
                dir = inputVec;
            }
            else
            {
                rotateNow = true;
                aimDir = inputVec;
            }
            velocity = inputVec + (inputVec * deltaTime * MoveSpeed);

            //もしほかのモーション中だったら走りモーションへ
            if (animTypeID != 1)
            {
                animTypeID = 1;
                animControl->StartAnimation(animTypeID);
            }
        }
        //入力がなかったら減速
        else
        {
            velocity *= 0.9f;
            //もし待機モーションでなければ待機モーションにする
            if (!attack && animTypeID != 0)
            {
                animTypeID = 0;
                animControl->StartAnimation(animTypeID);
            }
        }

        //左右の移動制限
        if ((pos + velocity).x >= -MoveLimit && (pos + velocity).x <= MoveLimit)
        {
            //移動処理
            pos += velocity;
        }

        //3Dモデルのポジション設定
        MV1SetPosition(modelHandle, pos);
    }
}