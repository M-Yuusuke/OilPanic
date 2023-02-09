#pragma once
//#include <vector>

namespace Calculation
{
    //�Q�[�����A�N�^�[�E�����蔻��̎�ޕʃ^�O
    //�K�v�Ȃ��̂�Begin��End�̊Ԃ�254�܂Œ�`�ł���
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
    *���[�v����p�B��L�^�O�̑S�v�f���L�q���Ă�������
    * 
    *@details�@�g�p�@�Ƃ��āAfor(ObjectTag &tag : ObjectTagAll)�Ƃ��邱�ƂŁA
    * �STag�v�f�̃��[�v�ɂł���
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