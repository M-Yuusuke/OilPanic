#pragma once
#include "../SceneBase/SceneBase.h"

class Result : public SceneBase
{
public:
    //�V���O���g���̐���
    static Result* CreateInstance();
    //�V���O���g���̔j��
    static void DestroyInstance();

    SceneBase* Update()override;
    void Draw()override;

private:
    Result();
    ~Result();
    static Result* Instance;
};

