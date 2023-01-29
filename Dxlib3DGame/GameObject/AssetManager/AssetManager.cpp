#include "DxLib.h"
#include "AssetManager.h"
#include "../VectorCalculation/VectorCalculation.h"

namespace Calculation
{
    AssetManager* AssetManager::Instance = nullptr;

    /// <summary>
    /// �C���X�^���X����
    /// </summary>
    void Calculation::AssetManager::CreateInstance()
    {
        if (!Instance)
        {
            Instance = new AssetManager;
        }
    }

    /// <summary>
    /// �C���X�^���X�j��
    /// </summary>
    void Calculation::AssetManager::DestroyInstance()
    {
        if (Instance)
        {
            delete Instance;
            Instance = nullptr;
        }
    }

    /// <summary>
    /// ���b�V��(���f��)�n���h���̎擾
    /// </summary>
    /// <param name="meshFileName">���f���̃t�@�C���p�X</param>
    /// <returns>���b�V���n���h��</returns>
    int AssetManager::GetMesh(std::string meshFileName)
    {
        int meshID = 0;
        //�A�z�z��ɓ����f�[�^���o�^����Ă��Ȃ����𒲂ׂ�
        auto iter = Instance->MeshMap.find(meshFileName);

        //������Ȃ������ꍇ�͓ǂݍ��݂��s���A�A�z�z��ɋL�^����
        if (iter == Instance->MeshMap.end())
        {
            meshID = MV1LoadModel(meshFileName.c_str());
            if (meshID == -1)
            {
                return -1;
            }
            Instance->MeshMap.emplace(meshFileName, meshID);
        }
        //�V�K�ǂݍ��݂�2��ڈȍ~�̓ǂݍ��݂��A�����������̂�Ԃ�
        //���b�V�����g���L�����N�^�[�����������ꍇ�ɁA���{���������ƑS�������č��邽��
        //���b�V���̃R�s�[�폜�p��DuplivateMash�ɕۑ�
        meshID = MV1DuplicateModel(Instance->MeshMap[meshFileName]);
        Instance->DuplicatesMesh.push_back(meshID);
        return meshID;
    }

    /// <summary>
    /// �A�j���[�V�����n���h���̎擾
    /// </summary>
    /// <param name="animationFileName">�A�j���[�V�����̃t�@�C���p�X</param>
    /// <returns>�A�j���[�V�����n���h��</returns>
    int AssetManager::GetAnimation(std::string animationFileName)
    {
        int animID = 0;
        auto iter = Instance->AnimationMap.find(animationFileName);
        //������Ȃ������ꍇ�͓ǂݍ��݂��s���A�A�z�z��ɋL�^����
        if (iter == Instance->AnimationMap.end())
        {
            animID = MV1LoadModel(animationFileName.c_str());
            if (animID == -1)
            {
                return -1;
            }
            Instance->AnimationMap.emplace(animationFileName, animID);
        }
        //�o�^���ꂽ�A�j���[�V����ID��Ԃ�
        return Instance->AnimationMap[animationFileName];
    }

    /// <summary>
    /// ���b�V��(���f��)�̍폜
    /// </summary>
    /// <param name="meshID">�폜���������b�V���n���h��</param>
    void AssetManager::ReleaseMesh(int meshID)
    {
        //Duplicate�̒��̃��b�V�����������A�폜
        auto iter = std::find(Instance->DuplicatesMesh.begin(), Instance->DuplicatesMesh.end(), meshID);
        if (iter == Instance->DuplicatesMesh.end())
        {
            //������Ȃ�����
            return;
        }
        MV1DeleteModel(meshID);
        //�����̃f�[�^�Ɠ���ւ��Ė������폜
        std::iter_swap(iter, Instance->DuplicatesMesh.end() - 1);
        Instance->DuplicatesMesh.pop_back();
    }

    /// <summary>
    /// �S���b�V���E�A�j���[�V�����̍폜
    /// </summary>
    void AssetManager::ReleaseAllAsset()
    {
        //�S�ẴA�j���[�V���������
        for (auto iter = Instance->AnimationMap.begin(); iter != Instance->AnimationMap.end(); iter++)
        {
            MV1DeleteModel(iter->second);
        }
        //�S�Ẵ��f�����������
        for (auto iter = Instance->MeshMap.begin(); iter != Instance->MeshMap.end(); iter++)
        {
            MV1DeleteModel(iter->second);
        }
        //�S�Ă̕������f�����폜�폜����
        for (auto iter = Instance->DuplicatesMesh.begin(); iter != Instance->DuplicatesMesh.end(); iter++)
        {
            MV1DeleteModel(*iter);
        }

        Instance->AnimationMap.clear();
        Instance->MeshMap.clear();
        Instance->DuplicatesMesh.clear();
    }
}