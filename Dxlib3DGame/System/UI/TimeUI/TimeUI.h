#pragma once
#include "DxLib.h"
#include "../UIBase/UIBase.h"
class Rule;
/// <summary>
/// �c�莞�ԏ���
/// </summary>
class TimeUI : public UIBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    TimeUI();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~TimeUI();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update();

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw();

private:
    //�t�H���g�T�C�Y
    const int FontSize = 48;
    //���͂�x���W
    const int StringPosX = 50;
    //���͂�y���W
    const int StringPosY = 80;
    //�����̐F
    const INT4 White = { 255,255,255 };
    //���[���N���X�̃C���X�^���X
    Rule* rule;

    float timeLimit;
};

