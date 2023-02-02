#include "DxLib.h"
#include "Play.h"
#include "../SceneManager/SceneManager.h"
#include "../../GameObject/VectorCalculation/VectorCalculation.h"
#include "../../GameObject/GameObjectManager/GameObjectManager.h"
#include "../../System/Rule/Rule.h"
#include "../System/UI/PlayerUI/PlayerUI.h"
#include "../System/UI/BucketUI/BucketUI.h"
#include "../GameObject/Objects/Player/Player.h"

Play* Play::Instance = nullptr;

Play::Play():
    playerUI(new PlayerUI),
    bucketUI(new BucketUI)
{
}

Play::~Play()
{
}
Play* Play::CreateInstance()
{
    if (!Instance)
    {
        Instance = new Play;
    }
    return Instance;
}

void Play::DestroyInstance()
{
    delete Instance;
    Instance = nullptr;
}

SceneBase* Play::Update()
{
    rule->SetNowTime();
    rule->SetDeltaTime();
    Calculation::GameObjectBase* player = Calculation::GameObjectManager::GetFirstGameObject(Calculation::ObjectTag::Player);
    //プレイヤーの体力が尽きたら終了
    if (player->IsAlive())
    {
        sceneManager->NextScene(this);
    }
    Calculation::GameObjectManager::Update(rule->GetDeltaTime());
    Calculation::GameObjectManager::Collision();
    playerUI->Update();
    bucketUI->Update();
    rule->SetPrevTime();
    return this;
}

void Play::Draw()
{
    ClearDrawScreen();
    Calculation::GameObjectManager::Draw();
    //
    playerUI->Draw();
    //
    bucketUI->Draw();
    ScreenFlip();
}