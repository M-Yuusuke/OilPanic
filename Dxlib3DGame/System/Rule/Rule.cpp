#include "Rule.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"

Rule* Rule::instance = nullptr;

Rule::Rule() :
    timeLimit(0),
    nowTime(0),
    deltaTime(0),
    prevTime(0),
    score(0),
    missCount(0)
{
}

Rule::~Rule()
{
    nowTime = NULL;
    deltaTime = NULL;
    prevTime = NULL;
}

/// <summary>
/// 終了条件判定
/// </summary>
/// <returns>終了条件を満たしていればtrue、満たしていなければfalse</returns>
bool Rule::Judgment()
{
    //ミスが既定値に達するもしくは制限時間切れになったら
    if (missCount == MaxMissCount || timeLimit <= 0)
    {
        return true;
    }
    return false;
}

/// <summary>
/// インスタンス生成
/// </summary>
/// <returns>ルールクラスのインスタンス</returns>
Rule* Rule::CreateInstance()
{
    if (!instance)
    {
        instance = new Rule;
    }
    return instance;
}

/// <summary>
/// インスタンス破棄
/// </summary>
void Rule::DestoryInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

/// <summary>
/// 初期化処理
/// </summary>
void Rule::Initialize()
{
    nowTime = 0;
    deltaTime = 0;
    prevTime = 0;

    SetNowTime();
    SetDeltaTime();
    SetPrevTime();
    timeLimit = MaxTimeLimit;
    missCount = 0;
}


/// <summary>
/// 更新処理
/// </summary>
void Rule::Update()
{
    if (timeLimit <= 0)
    {
        timeLimit = 0;
    }
    else
    {
        timeLimit -= deltaTime;
    }
}
