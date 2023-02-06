#pragma once
#include "../GameObject/GameObjectBase/GameObjectBase.h"
#include "../Bucket/Bucket.h"
namespace Calculation
{
    /// <summary>
    /// �v���C���[�����ݎ�����I�C���Ɋւ��鏈�����s���N���X
    /// </summary>
    class PlayerOil : public GameObjectBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        PlayerOil(VECTOR& pos,int scale);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~PlayerOil();

        /// <summary>
        /// ����������
        /// </summary>
        void Initialize()override;

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        void Update(float deltaTime)override;

        /// <summary>
        /// �`�揈��
        /// </summary>
        void Draw()override;

        /// <summary>
        /// �����蔻�菈��
        /// </summary>
        /// <param name="other">���������I�u�W�F�N�g�̃|�C���^</param>
        void OnCollisionEnter(GameObjectBase* other)override;
    private:
        /// <summary>
        /// ���f���f�[�^�̓ǂݍ���
        /// </summary>
        void ModelLoad();

        /// <summary>
        /// ��������
        /// </summary>
        void Drop(float deltaTime);

        //�������x
        const float DropSpeed = 500.0f;
        //�����蔻�苅�̔��a
        const float Radius = 50.0f;
        //���[�J�����W
        const VECTOR FirstLocalPos = { 0,30.0f,0 };
        //�������f���̑傫��
        const VECTOR FirstScale = { 0.125f,0.125f,0.125f };
        //���f���̔z�u
        const VECTOR Position = { 200.0f,100.0f,0 };

        //�o�P�c�N���X�̃C���X�^���X
        Calculation::Bucket* bucket;
        //���f���̑傫��
        VECTOR scale;
        //�g�嗦
        float magnification;
    };
}

