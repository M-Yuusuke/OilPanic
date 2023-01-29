#include "SceneBase.h"
#include "../SceneManager/SceneManager.h"
#include "../../System/Rule/Rule.h"

SceneBase::SceneBase() :
    sceneManager(SceneManager::CreateInstance()),
    rule(Rule::CreateInstance())
{
}

SceneBase::~SceneBase()
{
    Rule::DestoryInstance();
    rule = nullptr;
}
