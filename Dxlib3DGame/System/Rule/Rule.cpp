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
/// �I����������
/// </summary>
/// <returns>�I�������𖞂����Ă����true�A�������Ă��Ȃ����false</returns>
bool Rule::Judgment()
{
    //�~�X������l�ɒB����������͐������Ԑ؂�ɂȂ�����
    if (missCount == MaxMissCount || timeLimit <= 0)
    {
        return true;
    }
    return false;
}

/// <summary>
/// �C���X�^���X����
/// </summary>
/// <returns>���[���N���X�̃C���X�^���X</returns>
Rule* Rule::CreateInstance()
{
    if (!instance)
    {
        instance = new Rule;
    }
    return instance;
}

/// <summary>
/// �C���X�^���X�j��
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
/// ����������
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
/// �X�V����
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
