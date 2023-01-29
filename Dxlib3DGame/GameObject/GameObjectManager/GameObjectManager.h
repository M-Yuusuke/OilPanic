#pragma once
#include <vector>
#include <unordered_map>
#include "../GameObjectBase/GameObjectBase.h"
#include "../ObjectTag.h" 

namespace Calculation
{
    class GameObjectManager final
    {
    public:
        /// <summary>
        /// ���̃N���X�̃C���X�^���X����
        /// </summary>
        static GameObjectManager* CreateInstance();

        /// <summary>
        /// ���̃N���X�̃C���X�^���X�j��
        /// </summary>
        static void DestroyInstance();

        /// <summary>
        /// �Q�[���I�u�W�F�N�g�̓o�^
        /// </summary>
        /// <param name="newObj">�o�^����I�u�W�F�N�g�̃|�C���^</param>
        static void Entry(GameObjectBase* newObj);
        
        /// <summary>
        /// �Q�[���I�u�W�F�N�g�̍폜
        /// </summary>
        /// <param name="releaseObj">�폜����I�u�W�F�N�g�̃|�C���^</param>
        static void Release(GameObjectBase* releaseObj);

        /// <summary>
        /// �S�I�u�W�F�N�g�폜
        /// </summary>
        static void ReleaseAllObj();

        /// <summary>
        /// �o�^����Ă���I�u�W�F�N�g�̏���������
        /// </summary>
        static void Init();

        /// <summary>
        /// �o�^����Ă���I�u�W�F�N�g�̍X�V����
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        static void Update(float deltaTime);

        /// <summary>
        /// �`�揈��
        /// </summary>
        static void Draw();

        //�����蔻��

        /// <summary>
        /// ���̃I�u�W�F�N�g�Ƃ̓����蔻��
        /// </summary>
        static void Collision();

        /// <summary>
        /// �Ώۂ̃^�O�̐����Ă���ŏ��̃I�u�W�F�N�g
        /// </summary>
        /// <param name="tag">�����������I�u�W�F�N�g�̃^�O</param>
        /// <returns>�Ώۂ̃^�O�̈�ԍŏ��ɓo�^����Ă���I�u�W�F�N�g�̃|�C���^</returns>
        static GameObjectBase* GetFirstGameObject(ObjectTag tag);

        /// <summary>
        /// �Ώۂ̃^�O�̐����Ă���I�u�W�F�N�g�̑���
        /// </summary>
        /// <param name="tag">�����������I�u�W�F�N�g�̃^�O</param>
        /// <returns>�Ώۂ̃^�O�̑���</returns>
        static int GetObjectSize(ObjectTag tag) { return (int)Instance->Objects[tag].size(); }

    private:
        GameObjectManager() {}
        ~GameObjectManager() { ReleaseAllObj(); }
        //�}�l�[�W���[�̃C���X�^���X
        static GameObjectManager* Instance;

        //�ꎞ�ҋ@�I�u�W�F�N�g
        std::vector<GameObjectBase*> PendingObjects;
        //Objects�@[�^�O][�I�u�W�F�N�g��]
        std::unordered_map<ObjectTag, std::vector<GameObjectBase*>> Objects;
    };
}


