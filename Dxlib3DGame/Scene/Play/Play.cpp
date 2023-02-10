#include "DxLib.h"
#include "Play.h"
#include "../SceneManager/SceneManager.h"
#include "../../GameObject/VectorCalculation/VectorCalculation.h"
#include "../../GameObject/GameObjectManager/GameObjectManager.h"
#include "../../System/Rule/Rule.h"
#include "../System/UI/ScoreUI/ScoreUI.h"
#include "../System/UI/BucketUI/BucketUI.h"
#include "../System/UI/TimeUI/TimeUI.h"
#include "../GameObject/Objects/Player/Player.h"

Play* Play::Instance = nullptr;

Play::Play():
    scoreUI(new ScoreUI),
    bucketUI(new BucketUI),
    timeUI(new TimeUI)
{
}

Play::~Play()
{
    delete scoreUI;
    delete bucketUI;
    delete timeUI;
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
    Calculation::GameObjectManager::Update(rule->GetDeltaTime());
    Calculation::GameObjectManager::Collision();
    scoreUI->Update();
    bucketUI->Update();
    timeUI->Update();
    rule->Update();
    //終了条件を満たしていれば次のシーンへ遷移
    if (rule->Judgment())
    {
        return sceneManager->NextScene(this);
    }
    rule->SetPrevTime();
    return this;
}

void Play::Draw()
{
    ClearDrawScreen();
    Calculation::GameObjectManager::Draw();
    //スコアを描画
    scoreUI->Draw();
    //バケツメータを描画
    bucketUI->Draw();
    timeUI->Draw();
    ScreenFlip();
}