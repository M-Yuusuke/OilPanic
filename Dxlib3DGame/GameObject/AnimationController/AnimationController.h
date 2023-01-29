#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace Calculation
{
    /// <summary>
    /// �A�j���[�V�����֘A�̏������s���N���X
    /// </summary>
    class AnimationController final
    {
    public:
        AnimationController(int modelHandle);
        ~AnimationController();

        /// <summary>
        /// �A�j���[�V�����̒ǉ�
        /// </summary>
        /// <param name="animFileName">�A�j���[�V�����̃t�@�C���p�X</param>
        /// <param name="animFps">�A�j���[�V�����Đ��̃t���[�����[�g�i�ȗ��B�f�t�H���g��30fps�j</param>
        /// <param name="isLoop">�A�j���[�V�����̃��[�v�Đ������邩�i�ȗ��B�f�t�H���g�Ń��[�v������j</param>
        /// <returns>�A�j���[�V�����Đ��ɕK�v��ID</returns>
        int AddAnimation(std::string animFileName, float animFps = 30.0f, bool isLoop = true);

        /// <summary>
        /// �A�j���[�V�����̑���������ݒ�
        /// ���t���[��AddAnimation���Ăяo���K�v������
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void AddAnimationTime(float deltaTime);
        
        /// <summary>
        /// �A�j���[�V�����̍Đ��J�n
        /// �����A�j���[�V�������w�肳�ꂽ�ꍇ�A�n�߂���Đ�����
        /// </summary>
        /// <param name="animID">�A�j���[�V����ID</param>
        void StartAnimation(int animID);

        /// <summary>
        /// �A�j���[�V�����̍Đ����X�g�b�v
        /// </summary>
        void StopAnimation();

        /// <summary>
        /// ���ݍĐ�����
        /// </summary>
        /// <returns>�Đ����Ȃ�true�A��~���Ă����false</returns>
        bool IsPlaying(int animID);

    private:
        struct AnimData
        {
        public:
            /// <summary>
            /// �A�j���[�V�����f�[�^�\���� �R���X�g���N�^
            /// </summary>
            AnimData();

            int animationHandle;
            //�A�^�b�`����A�j���[�V�����ԍ�
            int animationIndex;
            //�A�j���[�V�����̑��Đ�����
            float animationTotalTime;
            //�A�j���[�V�����̍Đ����x
            float animationPlayFps;
            //���[�v�Đ��������邩
            bool loopAnimation;
        };

        int modelHandle;
        //�A�j���[�V���������o�^�p
        std::vector<AnimData> animDatas;
        //���ݍĐ����̃A�j���[�V����ID
        int nowAnimTypeNum;
        //���t����̃C���f�b�N�X
        int attachedIndex;
        //���ݍĐ����̃A�j���[�V��������
        float nowAnimTime;
    };
}

