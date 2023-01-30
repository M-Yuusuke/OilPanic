#include "PlayerUI.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/ObjectTag.h"
#include "../GameObject/Objects/Player/Player.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
PlayerUI::PlayerUI():
    hp(0)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
PlayerUI::~PlayerUI()
{
}

/// <summary>
/// �X�V����
/// </summary>
void PlayerUI::Update(int score)
{
    this->score = score;
}

/// <summary>
/// �`�揈��
/// </summary>
void PlayerUI::Draw()
{
    //�t�H���g�T�C�Y���w��
    SetFontSize(FontSize);
    //�X�R�A�\��
    DrawFormatString(50, 20, GetColor(255, 255, 255), "SCORE %d", score);
}