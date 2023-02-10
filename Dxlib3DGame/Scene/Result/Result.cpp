#include "DxLib.h"
#include "Result.h"
#include "../SceneManager/SceneManager.h"

Result* Result::Instance = nullptr;
Result::Result()
{
}

Result::~Result()
{
}

Result* Result::CreateInstance()
{
    if (!Instance)
    {
        Instance = new Result;
    }
    return Instance;
}

void Result::DestroyInstance()
{
    delete Instance;
    Instance = nullptr;
}

SceneBase* Result::Update()
{
    GetJoypadXInputState(DX_INPUT_PAD1, &gamePadState);
    if (CheckHitKey(KEY_INPUT_SPACE) || gamePadState.Buttons[13])
    {
        return SceneManager::NextScene(this);
    }
    return this;
}

void Result::Draw()
{
    ClearDrawScreen();
    DrawString(50, 50, "Result\n Title To Space or B", GetColor(255, 255, 255));
    ScreenFlip();
}


