#pragma once
class UIBase
{
public:
    /// <summary>
    /// �R���X�g���N�^(�t�H���g�f�[�^�̓ǂݍ���)
    /// </summary>
    UIBase();

    /// <summary>
    /// �f�X�g���N�^(�t�H���g�f�[�^�̔j��)
    /// </summary>
    virtual ~UIBase();

    /// <summary>
    /// �X�V����
    /// </summary>
    virtual void Update() {}

    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw() = 0;
};

