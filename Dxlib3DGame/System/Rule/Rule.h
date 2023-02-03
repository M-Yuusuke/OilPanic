#pragma once
#include "DxLib.h"
#include "../GameObject/Objects/Bucket/Bucket.h"

/// <summary>
/// ゲームルール関連の処理を行うクラス
/// </summary>
class Rule
{
public:
    /// <summary>
    /// インスタンス生成
    /// </summary>
    /// <returns>ルールクラスのインスタンス</returns>
    static Rule* CreateInstance();

    /// <summary>
    /// インスタンス破棄
    /// </summary>
    static void DestoryInstance();

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Initialize();

    void Update();


    //時間関係処理
    
    /// <summary>
    /// フレームの開始時間
    /// </summary>
    static void SetNowTime() { instance->nowTime = GetNowCount(); }

    /// <summary>
    /// 1フレームの経過時間のセット
    /// </summary>
    static void SetDeltaTime() { instance->deltaTime = (instance->nowTime - instance->prevTime) / 1000.0f; }

    /// <summary>
    /// 1フレームの経過時間を返す
    /// </summary>
    /// <returns>1フレームの経過時間</returns>
    float GetDeltaTime()const { return deltaTime; }

    /// <summary>
    /// 前フレームの開始時間をセット
    /// </summary>
    static void SetPrevTime() { instance->prevTime = instance->nowTime; }

    /// <summary>
    /// スコアを返す
    /// </summary>
    /// <returns>スコア</returns>
    int GetScore()const { return instance->score; }

    /// <summary>
    /// スコア加算（ボーナス無し）
    /// </summary>
    static void AcquisitionScore() { instance->score++; }

    /// <summary>
    /// スコア加算（ボーナス有り）
    /// </summary>
    /// <param name="bonus">バケツに汲み取った回数</param>
    static void AcquisitionScore(int bonus) { instance->score += instance->Bonus[bonus]; }

    /// <summary>
    /// ミスカウント加算
    /// </summary>
    void AddMissCount() { instance->missCount++; }

    /// <summary>
    /// ミスカウントを返す
    /// </summary>
    /// <returns>ミスカウント</returns>
    int GetMissCount()const { return instance->missCount; }

private:
    /// <summary>
    /// コンストラクタ(シングルトン)
    /// </summary>
    Rule();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Rule();

    //ルールクラスのインスタンス
    static Rule* instance;

    //ボーナス
    const int Bonus[3] = { 1,2,5 };

    //フレーム開始時間
    int nowTime;
    //前フレームの開始時間
    int prevTime;
    //1フレームの経過時間
    float deltaTime;

    //スコア記録用変数
    int score;
    //ミスカウント
    int missCount;
    //バケツのポインタ
    Calculation::Bucket* bucket;
};

