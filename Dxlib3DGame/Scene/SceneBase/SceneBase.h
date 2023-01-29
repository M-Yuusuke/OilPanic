#pragma once
#include "DxLib.h"
class SceneManager;
class Rule;
class SceneBase
{
public:
    SceneBase();
    virtual ~SceneBase();
    virtual SceneBase* Update() = 0;
    virtual void Draw() {};

protected:
    SceneManager* sceneManager;
    Rule* rule;
    XINPUT_STATE gamePadState;
};

