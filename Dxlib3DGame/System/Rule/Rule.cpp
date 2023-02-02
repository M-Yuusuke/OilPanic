#include "Rule.h"

Rule* Rule::instance = nullptr;

Rule::Rule() :
    nowTime(0),
    deltaTime(0),
    prevTime(0),
    score(0)
{
}

Rule::~Rule()
{
    nowTime = NULL;
    deltaTime = NULL;
    prevTime = NULL;
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
}