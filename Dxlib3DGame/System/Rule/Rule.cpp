#include "Rule.h"

Rule* Rule::instance = nullptr;

Rule::Rule() :
    nowTime(0),
    deltaTime(0),
    prevTime(0),
    score(0)
{
}

Rule::~Rule()
{
    nowTime = NULL;
    deltaTime = NULL;
    prevTime = NULL;
}

/**
* Rule�̃C���X�^���X�𐶐�����
* @note static���\�b�h������Ŏg�p����ۂɕK�v
*/
Rule* Rule::CreateInstance()
{
    if (!instance)
    {
        instance = new Rule;
    }
    return instance;
}

/**
* Rule�̌�n������
* @detail �A�v���P�[�V�����I���O�ɌĂяo���A���[���N���X���m�ۂ����̈��
* ���[���N���X���g�̉���������s���B
*/
void Rule::DestoryInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void Rule::Initialize()
{
    nowTime = 0;
    deltaTime = 0;
    prevTime = 0;

    SetNowTime();
    SetDeltaTime();
    SetPrevTime();
}