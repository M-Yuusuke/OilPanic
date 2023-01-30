#include "GameObjectManager.h"
#include "../Objects/CharacterBase/CharacterBase.h"

namespace Calculation
{
    GameObjectManager* GameObjectManager::Instance = nullptr;

    /// <summary>
    /// ���̃N���X�̃C���X�^���X����
    /// </summary>
    GameObjectManager* GameObjectManager::CreateInstance()
    {
        if (!Instance)
        {
            Instance = new GameObjectManager;
        }
        return Instance;
    }

    /// <summary>
    /// ���̃N���X�̃C���X�^���X�j��
    /// </summary>
    void GameObjectManager::DestroyInstance()
    {
        if (Instance)
        {
            delete Instance;
            Instance = nullptr;
        }
    }

    /// <summary>
    /// �Q�[���I�u�W�F�N�g�̓o�^
    /// </summary>
    /// <param name="newObj">�o�^����I�u�W�F�N�g�̃|�C���^</param>
    void GameObjectManager::Entry(GameObjectBase* newObj)
    {
        Instance->PendingObjects.push_back(newObj);
    }

    /// <summary>
    /// �Q�[���I�u�W�F�N�g�̍폜
    /// </summary>
    /// <param name="releaseObj">�폜����I�u�W�F�N�g�̃|�C���^</param>
    void GameObjectManager::Release(GameObjectBase* releaseObj)
    {
        //�y���f�B���O�I�u�W�F�N�g�����猟��
        auto itr = std::find(Instance->PendingObjects.begin(), Instance->PendingObjects.end(), releaseObj);
        if (itr != Instance->PendingObjects.end())
        {
            //�������I�u�W�F�N�g���Ō���Ɉړ����ăf�[�^������
            std::iter_swap(itr, Instance->PendingObjects.end() - 1);
            Instance->PendingObjects.pop_back();

            return;
        }

        //�������I�u�W�F�N�g�̃^�O�𓾂�
        ObjectTag tag = releaseObj->GetTag();

        //�A�N�e�B�u�I�u�W�F�N�g������폜�I�u�W�F�N�g������
        itr = std::find(Instance->Objects[tag].begin(), Instance->Objects[tag].end(), releaseObj);
        if (itr != Instance->Objects[tag].end())
        {
            //�������I�u�W�F�N�g�𖖔��Ɉړ����A�폜
            std::iter_swap(itr, Instance->Objects[tag].end() - 1);
            delete Instance->Objects[tag].back();
            //�����Ɉړ������R���e�i���폜
            Instance->Objects[tag].erase(Instance->Objects[tag].end() - 1);
        }
    }

    /// <summary>
    /// �S�I�u�W�F�N�g�폜
    /// </summary>
    void GameObjectManager::ReleaseAllObj()
    {
        //��������y���f�B���O�I�u�W�F�N�g��S�č폜
        while (!Instance->PendingObjects.empty())
        {
            delete Instance->PendingObjects.back();
        }
        
        //�S�ẴA�N�e�B�u�I�u�W�F�N�g���폜
        for (auto& tag : ObjectTagAll)
        {
            //��������폜
            while (!Instance->Objects[tag].empty())
            {
                delete Instance->Objects[tag].back();
                Instance->Objects[tag].pop_back();
            }
        }
    }

    /// <summary>
    /// �o�^����Ă���I�u�W�F�N�g�̏���������
    /// </summary>
    void GameObjectManager::Init()
    {
        //�y���f�B���O���̃I�u�W�F�N�g���A�N�e�B�u���X�g�ɒǉ�
        for (auto pending : Instance->PendingObjects)
        {
            ObjectTag tag = pending->GetTag();
            Instance->Objects[tag].emplace_back(pending);
        }
        Instance->PendingObjects.clear();

        for (auto& tag : ObjectTagAll)
        {
            for (int i = 0; i < Instance->Objects[tag].size(); i++)
            {
                Instance->Objects[tag][i]->Initialize();
            }
        }
    }

    /// <summary>
    /// �o�^����Ă���I�u�W�F�N�g�̍X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void GameObjectManager::Update(float deltaTime)
    {
        //�S�ẴA�N�^�[�̍X�V
        for (auto& tag : ObjectTagAll)
        {
            //�Y���^�O�ɂ���S�ẴI�u�W�F�N�g���X�V
            for (int i = 0; i < Instance->Objects[tag].size(); i++)
            {
                Instance->Objects[tag][i]->Update(deltaTime);
            }
        }
        //�y���f�B���O���̃I�u�W�F�N�g���A�N�e�B�u���X�g�ɒǉ�
        for (auto pending : Instance->PendingObjects)
        {
            ObjectTag tag = pending->GetTag();
            Instance->Objects[tag].emplace_back(pending);
        }
        Instance->PendingObjects.clear();

        //�S�ẴA�N�^�[���Ŏ���ł���A�N�^�[��DeadObject�ֈꎞ�ۊ�
        std::vector<GameObjectBase*> DeadObjects;
        for (auto& tag : ObjectTagAll)
        {
            for (int i = 0; i < Instance->Objects[tag].size(); i++)
            {
                if (!Instance->Objects[tag][i]->IsAlive())
                {
                    DeadObjects.emplace_back(Instance->Objects[tag][i]);
                }
            }
        }

        //����ł���I�u�W�F�N�g���폜
        for (auto& DeadObj : DeadObjects)
        {
            delete DeadObj;
        }
        DeadObjects.clear();
    }

    /// <summary>
    /// �`�揈��
    /// </summary>
    void GameObjectManager::Draw()
    {
        for (auto& tag : ObjectTagAll)
        {
            for (int i = 0; i < Instance->Objects[tag].size(); i++)
            {
                //if (Instance->Objects[tag][i]->IsAlive())
                //{
                //    Instance->Objects[tag][i]->Draw();
                //}
                if (Instance->Objects[tag][i]->IsVisible())
                {
                    Instance->Objects[tag][i]->Draw();
                }
            }
        }
    }

    /// <summary>
    /// ���̃I�u�W�F�N�g�Ƃ̓����蔻��
    /// </summary>
    void GameObjectManager::Collision()
    {
        //�v���C���[�ƃI�C���Ƃ̓����蔻��
        for (int oilNum = 0; oilNum < Instance->Objects[ObjectTag::Oil].size(); oilNum++)
        {
            //�I�C���΃v���C���[
            Instance->Objects[ObjectTag::Oil][oilNum]->OnCollisionEnter(Instance->Objects[ObjectTag::Bucket][0]);
        }
        

        ////�v���C���[�ƃX�e�[�W�̓����蔻��
        //for (int bgNum = 0; bgNum < Instance->Objects[ObjectTag::Stage].size(); bgNum++)
        //{
        //    Instance->Objects[ObjectTag::Player][0]->OnCollisionEnter(Instance->Objects[ObjectTag::Stage][bgNum]);
        //}
    }

    /// <summary>
    /// �Ώۂ̃^�O�̐����Ă���ŏ��̃I�u�W�F�N�g
    /// </summary>
    /// <param name="tag">�����������I�u�W�F�N�g�̃^�O</param>
    /// <returns>�Ώۂ̃^�O�̈�ԍŏ��ɓo�^����Ă���I�u�W�F�N�g�̃|�C���^</returns>
    GameObjectBase* GameObjectManager::GetFirstGameObject(ObjectTag tag)
    {
        if (Instance->Objects[tag].size() == 0)
        {
            return nullptr;
        }
        return Instance->Objects[tag][0];
    }
}