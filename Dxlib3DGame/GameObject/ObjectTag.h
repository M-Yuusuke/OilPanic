#pragma once
//#include <vector>

namespace Calculation
{
    //ゲーム内アクター・当たり判定の種類別タグ
    //必要なものはBeginとEndの間に254個まで定義できる
    enum class ObjectTag : unsigned char
    {
        Player,
        Helper,
        Oil,
        Bucket,
        Stage,
        Camera,
        Effect
    };

    /**
    *ループ制御用。上記タグの全要素を記述しておくこと
    * 
    *@details　使用法として、for(ObjectTag &tag : ObjectTagAll)とすることで、
    * 全Tag要素のループにできる
    */
    constexpr static ObjectTag ObjectTagAll[] =
    {
        ObjectTag::Player,
        ObjectTag::Helper,
        ObjectTag::Oil,
        ObjectTag::Bucket,
        ObjectTag::Stage,
        ObjectTag::Camera,
        ObjectTag::Effect
    };
}