#include "DxLib.h"
#include "Play.h"
#include "../SceneManager/SceneManager.h"
#include "../../GameObject/VectorCalculation/VectorCalculation.h"
#include "../../GameObject/GameObjectManager/GameObjectManager.h"
#include "../../System/Rule/Rule.h"
#include "../System/UI/PlayerUI/PlayerUI.h"
#include "../GameObject/Objects/Player/Player.h"

Play* Play::Instance = nullptr;

Play::Play():
    playerUI(new PlayerUI)
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
    //�v���C���[�̗̑͂��s������I��
    if (player->IsAlive())
    {
        sceneManager->NextScene(this);
    }
    Calculation::GameObjectManager::Update(rule->GetDeltaTime());
    Calculation::GameObjectManager::Collision();
    playerUI->Update();
    rule->SetPrevTime();
    return this;
}

void Play::Draw()
{
    ClearDrawScreen();
    Calculation::GameObjectManager::Draw();
    //�v���C���[��HP�Q�[�W�̕`��
    playerUI->Draw();
    ScreenFlip();
}