#include "ScoreUI.h"
#include "../GameObject/GameObjectManager/GameObjectManager.h"
#include "../GameObject/ObjectTag.h"
#include "../System/Rule/Rule.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ScoreUI::ScoreUI():
    score(0),
    rule(nullptr)
{
    rule = Rule::CreateInstance();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
ScoreUI::~ScoreUI()
{
    Rule::DestoryInstance();
}

/// <summary>
/// �X�V����
/// </summary>
void ScoreUI::Update()
{
    score = rule->GetScore();
}

/// <summary>
/// �`�揈��
/// </summary>
void ScoreUI::Draw()
{
    //�t�H���g�T�C�Y���w��
    SetFontSize(FontSize);
    //�X�R�A�\��
    DrawFormatString(StringPosX, StringPosY, GetColor(Black.x, Black.y, Black.z), "SCORE %d", score);
}