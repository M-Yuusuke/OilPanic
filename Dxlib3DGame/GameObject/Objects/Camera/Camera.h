#pragma once
#include "../../GameObjectBase/GameObjectBase.h"

namespace Calculation 
{
    /// <summary>
    /// �J�����֘A�������s���N���X
    /// </summary>
    class Camera : public GameObjectBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^�i�V���O���g���j
        /// </summary>
        Camera();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Camera();

        /// <summary>
        /// ����������
        /// </summary>
        void Initialize()override;

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Update(float deltaTime) override {}

    private:
        //�J�����̏������W
        const VECTOR FirstCameraPos = { 0,300.0f,-700.0f };
        //�J�����̒����_��ݒ�
        const VECTOR Target = { 0,100.0f,100.0f };

        //�`�拗���̉���
        const float Near = 10.0f;
        //�`�拗���̏��
        const float Far = 3000.0f;
    };
}


