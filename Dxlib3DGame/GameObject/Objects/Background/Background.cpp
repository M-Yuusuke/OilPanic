#include "DxLib.h"
#include "Background.h"
#include "../GameObject/GameObjectBase/GameObjectBase.h"
#include "../GameObject/ObjectTag.h"

namespace Calculation
{
    /// <summary>
    /// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
    /// </summary>
    Background::Background():
        GameObjectBase(ObjectTag::Background)
    {
        //”wŒi‰æ‘œ“Ç‚İ‚İ
        img = LoadGraph("../Data/Img/Background/Background.png");
    }

    Background::~Background()
    {
        DeleteGraph(img);
    }


    /// <summary>
    /// •`‰æˆ—
    /// </summary>
    void Background::Draw()
    {
        //”wŒi‚ğ•`‰æ
        DrawGraph(0, 0, img, FALSE);
    }
}
