#pragma once
#include "../SceneBase/SceneBase.h"
class ScoreUI;
class BucketUI;
class TimeUI;
class Play : public SceneBase
{
public:
    /// <summary>
    /// Play�V�[���̃C���X�^���X����
    /// </summary>
    /// <returns>Play�V�[���̃C���X�^���X</returns>
    static Play* CreateInstance();

    /// <summary>
    /// Play�V�[���̃C���X�^���X�j��
    /// </summary>
    static void DestroyInstance();

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <returns>���݂̃V�[���������͎��̃V�[���|�C���^</returns>
    SceneBase* Update()override;

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    Play();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Play();

    static Play* Instance;

    ScoreUI* scoreUI;
    BucketUI* bucketUI;
    TimeUI* timeUI;
};

