#pragma once
//#include <vector>

namespace Calculation
{
    //�Q�[�����A�N�^�[�E�����蔻��̎�ޕʃ^�O
    //�K�v�Ȃ��̂�Begin��End�̊Ԃ�254�܂Œ�`�ł���
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
    *���[�v����p�B��L�^�O�̑S�v�f���L�q���Ă�������
    * 
    *@details�@�g�p�@�Ƃ��āAfor(ObjectTag &tag : ObjectTagAll)�Ƃ��邱�ƂŁA
    * �STag�v�f�̃��[�v�ɂł���
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