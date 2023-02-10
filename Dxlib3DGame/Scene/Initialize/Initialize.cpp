#include "DxLib.h"
#include "Initialize.h"
#include "../SceneManager/SceneManager.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/Objects/Player/Player.h"
#include "../GameObject/Objects/Camera/Camera.h"
#include "../GameObject/Objects/Oil/Oil.h"
#include "../GameObject/Objects/Bucket/Bucket.h"
#include "../../System/Rule/Rule.h"
#include "../GameObject/Objects/Helper/Helper.h"
#include "../GameObject/Objects/Background/Background.h"
#include "../GameObject/Objects/Customer/Customer.h"

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
    //�}�l�[�W���ɓo�^����Ă���I�u�W�F�N�g�f�[�^���폜
    Calculation::GameObjectManager::ReleaseAllObj();

    //�I�u�W�F�N�g�f�[�^���}�l�[�W���ɓo�^
    Calculation::GameObjectManager::Entry(new Calculation::Background);
    Calculation::GameObjectManager::Entry(new Calculation::Player);
    for (int i = 0; i < 3; i++)
    {
        Calculation::GameObjectManager::Entry(new Calculation::Oil(VGet((float)-200 + 200 * i, 600.0f, 0)));
    }
    Calculation::GameObjectManager::Entry(new Calculation::Camera);
    Calculation::GameObjectManager::Entry(new Calculation::Bucket);
    Calculation::GameObjectManager::Entry(new Calculation::Helper);
    Calculation::GameObjectManager::Entry(new Calculation::Customer);

    //�o�^���ꂽ�I�u�W�F�N�g�f�[�^��������
    Calculation::GameObjectManager::Init();
    //���[���N���X�̏�����
    rule->Initialize();
    return SceneManager::NextScene(this);
}


