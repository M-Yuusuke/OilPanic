#pragma once
#include "DxLib.h"

/// <summary>
/// �Q�[�����[���֘A�̏������s���N���X
/// </summary>
class Rule
{
public:
    /// <summary>
    /// �C���X�^���X����
    /// </summary>
    /// <returns>���[���N���X�̃C���X�^���X</returns>
    static Rule* CreateInstance();

    /// <summary>
    /// �C���X�^���X�j��
    /// </summary>
    static void DestoryInstance();

    /// <summary>
    /// ����������
    /// </summary>
    void Initialize();

    //���Ԋ֌W����
    
    /// <summary>
    /// �t���[���̊J�n����
    /// </summary>
    static void SetNowTime() { instance->nowTime = GetNowCount(); }

    /// <summary>
    /// 1�t���[���̌o�ߎ��Ԃ̃Z�b�g
    /// </summary>
    static void SetDeltaTime() { instance->deltaTime = (instance->nowTime - instance->prevTime) / 1000.0f; }

    /// <summary>
    /// 1�t���[���̌o�ߎ��Ԃ�Ԃ�
    /// </summary>
    /// <returns>1�t���[���̌o�ߎ���</returns>
    float GetDeltaTime()const { return deltaTime; }

    /// <summary>
    /// �O�t���[���̊J�n���Ԃ��Z�b�g
    /// </summary>
    static void SetPrevTime() { instance->prevTime = instance->nowTime; }

    /// <summary>
    /// �X�R�A��Ԃ�
    /// </summary>
    /// <returns>�X�R�A</returns>
    int GetScore()const { return instance->score; }


private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    Rule();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Rule();

    //���[���N���X�̃C���X�^���X
    static Rule* instance;

    //�t���[���J�n����
    int nowTime;
    //�O�t���[���̊J�n����
    int prevTime;
    //1�t���[���̌o�ߎ���
    float deltaTime;

    //�X�R�A�L�^�p�ϐ�
    int score;
};

