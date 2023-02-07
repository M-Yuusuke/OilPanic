#include "TimeUI.h"
#include "../System/Rule/Rule.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
TimeUI::TimeUI():
    timeLimit(0),
    rule(nullptr)
{
    rule = Rule::CreateInstance();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
TimeUI::~TimeUI()
{
    Rule::DestoryInstance();
}

/// <summary>
/// �X�V����
/// </summary>
void TimeUI::Update()
{
    timeLimit = rule->GetTimeLimit();
}

/// <summary>
/// �`�揈��
/// </summary>
void TimeUI::Draw()
{
    //�t�H���g�T�C�Y���w��
    SetFontSize(FontSize);
    //�X�R�A�\��
    DrawFormatString(StringPosX, StringPosY, GetColor(White.x, White.y, White.z), "Time %2.0f", timeLimit);
}
