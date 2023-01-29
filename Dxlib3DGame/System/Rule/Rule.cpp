#include "Rule.h"

Rule* Rule::Instance = nullptr;

Rule::Rule() :
    NowTime(0),
    DeltaTime(0),
    PrevTime(0)
{
}

Rule::~Rule()
{
    NowTime = NULL;
    DeltaTime = NULL;
    PrevTime = NULL;
}

/**
* Rule�̃C���X�^���X�𐶐�����
* @note static���\�b�h������Ŏg�p����ۂɕK�v
*/
Rule* Rule::CreateInstance()
{
    if (!Instance)
    {
        Instance = new Rule;
    }
    return Instance;
}

/**
* Rule�̌�n������
* @detail �A�v���P�[�V�����I���O�ɌĂяo���A���[���N���X���m�ۂ����̈��
* ���[���N���X���g�̉���������s���B
*/
void Rule::DestoryInstance()
{
    if (Instance)
    {
        delete Instance;
        Instance = nullptr;
    }
}

void Rule::Initialize()
{
    NowTime = 0;
    DeltaTime = 0;
    PrevTime = 0;
}