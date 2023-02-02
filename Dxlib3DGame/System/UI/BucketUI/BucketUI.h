#pragma once
#include "Dxlib.h"
#include "../System/UI/UIBase/UIBase.h"
#include "../../../GameObject/Objects/Bucket/Bucket.h"

class BucketUI : public UIBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    BucketUI();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~BucketUI();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update()override;

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;

private:
    //�ΐF
    const INT4 Green = { 0,255,0 };
    //���F
    const INT4 Yellow = { 255,255,0 };
    //�ԐF
    const INT4 Red = { 255,0,0 };
    //���F
    const INT4 Black = { 255,255,255 };

    //���[�^�̊g�嗦
    const int Magnifincation = 100;
    //���[�^�̍����X���W
    const int MeterPosX = 600;
    //���[�^�̍����Y���W
    const int MeterPosY = 50;
    //���[�^�̏c��
    const int MeterHeight = 50;
    //���[�^�̕��̍ő�l
    const int MeterWidth = 500;
    //���[�^�ƃt���[���̍�
    const int FrameSub = 5;
    //������x���W
    const int StringPosX = MeterPosX - 80;

    //�o�P�c�N���X�̃C���X�^���X
    Calculation::Bucket* bucket;

    //�o�P�c�̊l����
    int acquisition;
    //�F�w��ϐ�
    INT4 ColorNum;
};