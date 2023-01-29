#include "DxLib.h"
#include "AnimationController.h"
#include "../AssetManager/AssetManager.h"

namespace Calculation
{
    /**
    * �R���X�g���N�^
    * @param[in] modelHandle �A�j���[�V������K�p���郂�f���n���h��
    */
    AnimationController::AnimationController(int modelHandle) :
        modelHandle(modelHandle),
        nowAnimTypeNum(-1),
        nowAnimTime(0),
        attachedIndex(0)
    {
    }

    AnimationController::~AnimationController()
    {
    }

    /// <summary>
    /// �A�j���[�V�����̒ǉ�
    /// </summary>
    /// <param name="animFileName">�A�j���[�V�����̃t�@�C���p�X</param>
    /// <param name="animFps">�A�j���[�V�����Đ��̃t���[�����[�g�i�ȗ��B�f�t�H���g��30fps�j</param>
    /// <param name="isLoop">�A�j���[�V�����̃��[�v�Đ������邩�i�ȗ��B�f�t�H���g�Ń��[�v������j</param>
    /// <returns>�A�j���[�V�����Đ��ɕK�v��ID</returns>
    int AnimationController::AddAnimation(std::string animFileName, float animFps, bool isLoop)
    {
        AnimData Anim;
        Anim.animationPlayFps = animFps;
        Anim.loopAnimation = isLoop;

        //�A�j���[�V�����f�[�^�ǂݍ���
        Anim.animationHandle = AssetManager::GetAnimation(animFileName.c_str());
        if (Anim.animationHandle == -1)
        {
            return -1;
        }
        Anim.animationIndex = MV1GetAnimNum(Anim.animationHandle) - 1;

        //���f���ɃA�j���[�V�������A�^�b�`
        attachedIndex = MV1AttachAnim(modelHandle, Anim.animationIndex, Anim.animationHandle, TRUE);
        Anim.animationTotalTime = MV1GetAnimTotalTime(Anim.animationHandle, Anim.animationIndex);

        //�A�j���[�V��������
        MV1DetachAnim(modelHandle, attachedIndex);

        //�����ɃA�j���[�V�����f�[�^��ǉ�
        animDatas.push_back(Anim);
        //vector�ɓ���Y�����ԍ���Ԃ�
        return static_cast<int> (animDatas.size() - 1);
    }

    /// <summary>
     /// �A�j���[�V�����̑���������ݒ�
     /// ���t���[��AddAnimation���Ăяo���K�v������
     /// </summary>
     /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void AnimationController::AddAnimationTime(float deltaTime)
     {
        nowAnimTime += deltaTime * animDatas[nowAnimTypeNum].animationPlayFps;
        //�A�j���[�V�����̃��[�v�Đ�
        //loop�t���O�������Ă��āA���݂̍Đ����Ԃ��A�j���[�V�����̑��Đ����Ԃ𒴂�����擪�ɖ߂�
        if (animDatas[nowAnimTypeNum].loopAnimation &&
            nowAnimTime > animDatas[nowAnimTypeNum].animationTotalTime)
        {
            nowAnimTime = 0;
        }
        MV1SetAttachAnimTime(modelHandle, attachedIndex, nowAnimTime);
    }

    /// <summary>
    /// �A�j���[�V�����̍Đ��J�n
    /// �����A�j���[�V�������w�肳�ꂽ�ꍇ�A�n�߂���Đ�����
    /// </summary>
    /// <param name="animID">�A�j���[�V����ID</param>
    void AnimationController::StartAnimation(int animID)
    {
        //�ȑO�̃A�j���[�V�����ƈႤ�A�j���[�V�������������x�f�^�b�`
        if (animID != nowAnimTypeNum)
        {
            if (nowAnimTypeNum != -1)
            {
                MV1DetachAnim(modelHandle, attachedIndex);
            }
            //�V�K�A�j���[�V�������Z�b�g
            nowAnimTypeNum = animID;
            attachedIndex = MV1AttachAnim(modelHandle, animDatas[nowAnimTypeNum].animationIndex, animDatas[nowAnimTypeNum].animationHandle, TRUE);
        }
        nowAnimTime = 0.0f;
        MV1SetAttachAnimTime(modelHandle, attachedIndex, nowAnimTime);
    }

    /// <summary>
    /// �A�j���[�V�����̍Đ����X�g�b�v
    /// </summary>
    void AnimationController::StopAnimation()
    {
        nowAnimTime = animDatas[nowAnimTypeNum].animationTotalTime;
    }

    /// <summary>
    /// ���ݍĐ�����
    /// </summary>
    /// <returns>�Đ����Ȃ�true�A��~���Ă����false</returns>
    bool AnimationController::IsPlaying(int animID)
    {
        if (animDatas[animID].loopAnimation && nowAnimTime > animDatas[animID].animationTotalTime)
        {
            return false;
        }
        return true;
    }

    /// <summary>
    /// �A�j���[�V�����f�[�^�\���� �R���X�g���N�^
    /// </summary>
    AnimationController::AnimData::AnimData() :
        animationHandle(-1),
        animationIndex(-1),
        animationTotalTime(-1),
        animationPlayFps(0),
        loopAnimation(false)
    {
    }
}