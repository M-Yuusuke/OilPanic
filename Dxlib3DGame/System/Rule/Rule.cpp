#include "Rule.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"

Rule* Rule::instance = nullptr;

Rule::Rule() :
    nowTime(0),
    deltaTime(0),
    prevTime(0),
    score(0),
    bucket(nullptr)
{
}

Rule::~Rule()
{
    nowTime = NULL;
    deltaTime = NULL;
    prevTime = NULL;
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
}

void Rule::Update()
{
}
