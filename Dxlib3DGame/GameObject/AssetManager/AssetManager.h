#pragma once
#include <atlstr.h>
#include <unordered_map>
#include <vector>

namespace Calculation
{
    /// <summary>
    /// ���f���E�A�j���[�V�����̊Ǘ����s���N���X
    /// </summary>
    class AssetManager final
    {
    public:
        /// <summary>
        /// �C���X�^���X����
        /// </summary>
        static void CreateInstance();

        /// <summary>
        /// �C���X�^���X�j��
        /// </summary>
        static void DestroyInstance();

        /// <summary>
        /// ���b�V��(���f��)�n���h���̎擾
        /// </summary>
        /// <param name="meshFileName">���f���̃t�@�C���p�X</param>
        /// <returns>���b�V���n���h��</returns>
        static int GetMesh(std::string meshFileName);

        /// <summary>
        /// �A�j���[�V�����n���h���̎擾
        /// </summary>
        /// <param name="animationFileName">�A�j���[�V�����̃t�@�C���p�X</param>
        /// <returns>�A�j���[�V�����n���h��</returns>
        static int GetAnimation(std::string animationFileName);

        /// <summary>
        /// ���b�V��(���f��)�̍폜
        /// </summary>
        /// <param name="meshID">�폜���������b�V���n���h��</param>
        static void ReleaseMesh(int meshID);

        /// <summary>
        /// �S���b�V���E�A�j���[�V�����̍폜
        /// </summary>
        static void ReleaseAllAsset();

    private:
        //�V���O���g��
        AssetManager() {}
        ~AssetManager() { ReleaseAllAsset(); }
        static AssetManager* Instance;

        //���b�V�����{(���{�Ƃ��ĕۑ������s���ADuplicate���ꂽ���̂�Ԃ�)
        std::unordered_map<std::string, int> MeshMap;
        //�A�j���[�V�������{
        std::unordered_map < std::string, int> AnimationMap;
        //���b�V�����R�s�[��������(������g�p����)
        std::vector<int> DuplicatesMesh;
    };
}


