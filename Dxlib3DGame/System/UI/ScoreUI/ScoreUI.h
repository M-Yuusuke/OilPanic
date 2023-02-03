#pragma once
#include "DxLib.h"
#include "../UIBase/UIBase.h"
class Rule;
/// <summary>
/// �X�R�A�\������
/// </summary>
class ScoreUI : public UIBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    ScoreUI();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~ScoreUI();

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
    const int StringPosY = 20;
    //�����̐F
    const INT4 White = { 255,255,255 };
    //���[���N���X�̃C���X�^���X
    Rule* rule;

    int score;
};