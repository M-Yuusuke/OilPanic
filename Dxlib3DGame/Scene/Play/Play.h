#pragma once
#include "../SceneBase/SceneBase.h"
class ScoreUI;
class BucketUI;
class TimeUI;
class Play : public SceneBase
{
public:
    //シングルトンの生成
    static Play* CreateInstance();
    //シングルトンの破棄
    static void DestroyInstance();

    SceneBase* Update()override;
    void Draw()override;

private:
    Play();
    ~Play();
    static Play* Instance;
    ScoreUI* scoreUI;
    BucketUI* bucketUI;
    TimeUI* timeUI;
};

