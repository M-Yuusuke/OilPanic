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

/**
* Ruleのインスタンスを生成する
* @note staticメソッドを内部で使用する際に必要
*/
Rule* Rule::CreateInstance()
{
    if (!instance)
    {
        instance = new Rule;
    }
    return instance;
}

/**
* Ruleの後始末処理
* @detail アプリケーション終了前に呼び出し、ルールクラスが確保した領域と
* ルールクラス自身の解放処理を行う。
*/
void Rule::DestoryInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void Rule::Initialize()
{
    nowTime = 0;
    deltaTime = 0;
    prevTime = 0;

    SetNowTime();
    SetDeltaTime();
    SetPrevTime();
}