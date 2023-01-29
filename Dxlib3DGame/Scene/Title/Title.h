#pragma once
#include "../SceneBase/SceneBase.h"

class Title : public SceneBase
{
public:
    //�V���O���g���̐���
    static Title* CreateInstance();
    //�V���O���g���̔j��
    static void DestroyInstance();

    SceneBase* Update()override;
    void Draw()override;

private:
    Title();
    ~Title();
    static Title* Instance;
};

