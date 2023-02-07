#include "DxLib.h"
#include "Background.h"
#include "../GameObject/GameObjectBase/GameObjectBase.h"
#include "../GameObject/ObjectTag.h"

namespace Calculation
{
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Background::Background():
        GameObjectBase(ObjectTag::Background)
    {
        //�w�i�摜�ǂݍ���
        img = LoadGraph("../Data/Img/Background/Background.png");
    }

    Background::~Background()
    {
        DeleteGraph(img);
    }


    /// <summary>
    /// �`�揈��
    /// </summary>
    void Background::Draw()
    {
        //�w�i��`��
        DrawGraph(0, 0, img, FALSE);
    }
}
