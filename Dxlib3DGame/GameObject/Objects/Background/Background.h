#pragma once
#include "../GameObject/GameObjectBase/GameObjectBase.h"
namespace Calculation
{
    class Background : public GameObjectBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Background();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Background();

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Update(float deltaTime)override {}

        /// <summary>
        /// �`�揈��
        /// </summary>
        void Draw()override;

    private:
        //�摜�n���h����ۑ�����ϐ�
        int img;
    };
}

