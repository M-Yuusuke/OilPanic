#pragma once
#include "../UIBase/UIBase.h"
#include "../GameObject/Objects/Player/Player.h"
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
    void Update(int score);

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw();

private:
    //PlayerUI�̃t�H���g�T�C�Y
    const int FontSize = 48;

    //HP�Q�[�W�̐F
    const INT4 HpColor = { 0,0,255 };

    //�Q�[�W�̊g�嗦
    const int Magnifincation = 5;
    //�Q�[�W�̍��[�̈ʒu
    const int MeterPosX = 200;
    //�Q�[�W�̏c��
    const int MeterHeight = 50;
    //�Q�[�W�̕��̍ő�l
    const int MeterWidth = 500;
    //�Q�[�W�ƃt���[���̍�
    const int FrameSub = 5;
    //HP�Q�[�W��Y���W
    const int HpMeterPosY = 50;
    //HP�̕�����x���W
    const int HpStringPosX = MeterPosX - 80;
    //���F
    const INT4 White = { 255,255,255 };

    int hp;
    int score;
};