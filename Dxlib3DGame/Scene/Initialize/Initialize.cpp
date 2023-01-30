#include "DxLib.h"
#include "Initialize.h"
#include "../SceneManager/SceneManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/Objects/Player/Player.h"
#include "../GameObject/Objects/Stage/Stage.h"
#include "../GameObject/Objects/Camera/Camera.h"
#include "../GameObject/Objects/Oil/Oil.h"
#include "../GameObject/Objects/Bucket/Bucket.h"
#include "../../System/Rule/Rule.h"

Initialize* Initialize::Instance = nullptr;

Initialize::Initialize()
{

}

Initialize::~Initialize()
{

}

Initialize* Initialize::CreateInstance()
{
    if (!Instance)
    {
        Instance = new Initialize;
    }
    return Instance;
}

void Initialize::DestroyInstance()
{
    if (Instance)
    {
        delete Instance;
        Instance = nullptr;
    }
}

SceneBase* Initialize::Update()
{
    Calculation::GameObjectManager::Entry(new Calculation::Player);
    Calculation::GameObjectManager::Entry(new Calculation::Stage);
    for (int i = 0; i < 3; i++)
    {
        Calculation::GameObjectManager::Entry(new Calculation::Oil(VGet((float)-100 + 100 * i, 300.0f, 0)));
    }
    Calculation::GameObjectManager::Entry(new Calculation::Camera);
    Calculation::GameObjectManager::Entry(new Calculation::Bucket);

    Calculation::GameObjectManager::Init();
    rule->Initialize();
    return SceneManager::NextScene(this);
}


