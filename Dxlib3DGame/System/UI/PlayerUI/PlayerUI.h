#pragma once
#include "../UIBase/UIBase.h"
class Rule;
/// <summary>
/// �v���C���[��HP�o�[�֘A����
/// </summary>
class PlayerUI : public UIBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    PlayerUI();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~PlayerUI();

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
    //���[���N���X�̃C���X�^���X
    Rule* rule;

    int score;
};