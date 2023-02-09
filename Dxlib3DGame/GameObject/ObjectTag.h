#pragma once
//#include <vector>

namespace Calculation
{
    //ゲーム内アクター・当たり判定の種類別タグ
    //必要なものはBeginとEndの間に254個まで定義できる
    enum class ObjectTag : unsigned char
    {
        Background,
        Player,
        Helper,
        Customer,
        PlayerOil,
        Oil,
        Bucket,
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
        ObjectTag::Background,
        ObjectTag::Player,
        ObjectTag::Helper,
        ObjectTag::Customer,
        ObjectTag::PlayerOil,
        ObjectTag::Oil,
        ObjectTag::Bucket,
        ObjectTag::Camera,
        ObjectTag::Effect
    };
}