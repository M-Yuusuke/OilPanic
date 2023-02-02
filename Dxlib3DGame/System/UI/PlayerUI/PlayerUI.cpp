#include "PlayerUI.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/ObjectTag.h"
#include "../System/Rule/Rule.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
PlayerUI::PlayerUI():
    score(0),
    rule(nullptr)
{
    rule = Rule::CreateInstance();
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
void PlayerUI::Update()
{
    this->score = rule->GetScore();
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