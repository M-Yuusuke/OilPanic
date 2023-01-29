#pragma once
#include "DxLib.h"
#include "../ObjectTag.h"
#include "../Collision/CollisionType.h"
#include "../Collision/CollisionFunction/CollisionFunction.h"
#include "../Collision/LineSegment/LineSegment.h"
#include "../Collision/Capsule/Capsule.h"
#include "../Collision/Sphere/Sphere.h"

namespace Calculation
{
    /// <summary>
    /// �Q�[���I�u�W�F�N�g�̊��N���X
    /// </summary>
    class GameObjectBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        /// <param name="tag">�I�u�W�F�N�g�^�O</param>
        GameObjectBase(ObjectTag tag);

        /// <summary>
        /// �R���X�g���N�^�i�����ʒu�w��j
        /// </summary>
        /// <param name="tag">�I�u�W�F�N�g�^�O</param>
        /// <param name="pos">�I�u�W�F�N�g�̏������W</param>
        GameObjectBase(ObjectTag tag, VECTOR pos);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        virtual ~GameObjectBase();

        /// <summary>
        /// �����������i�������z�֐��j
        /// </summary>
        virtual void Initialize() {}

        /// <summary>
        /// �X�V�����i�������z�֐��j
        /// </summary>
        /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
        virtual void Update(float deltaTime) = 0;

        /// <summary>
        /// �`�揈���i���z�֐��j
        /// </summary>
        virtual void Draw() {}

        /// <summary>
        /// �ʒu�擾
        /// </summary>
        /// <returns>�Ώۂ̃I�u�W�F�N�g�̃|�W�V����</returns>
        const VECTOR& GetPos()const { return pos; }

        /// <summary>
        /// �ʒu���Z�b�g
        /// </summary>
        /// <param name="vec">�Z�b�g�������|�W�V����</param>
        void SetPos(const VECTOR vec) { pos = vec; }

        /// <summary>
        /// ����Ԃ̎擾
        /// </summary>
        /// <returns></returns>
        bool IsVisible()const { return visible; }

        /// <summary>
        /// ����Ԃ̃Z�b�g
        /// </summary>
        /// <param name="visible"></param>
        void SetVisible(bool visible) { visible = visible; }

        /// <summary>
        /// �Q�[���I�u�W�F�N�g�������Ă��邩
        /// </summary>
        /// <returns>�Q�[���I�u�W�F�N�g�������Ă����true�A����ł����false</returns>
        bool IsAlive() const { return alive; }

        /// <summary>
        /// �Q�[���I�u�W�F�N�g�̐������Z�b�g
        /// </summary>
        /// <param name="alive">�����Ă��邩�ǂ����̃t���O</param>
        void SetAlive(bool alive) { alive = alive; }

        /// <summary>
        /// �I�u�W�F�N�g�^�O�̎擾
        /// </summary>
        /// <returns>�I�u�W�F�N�g�^�O</returns>
        ObjectTag GetTag()const { return tag; }

        //�����蔻��֘A
        
        /// <summary>
        /// ���̃I�u�W�F�N�g�ƏՓ˂����Ƃ��̃��A�N�V����
        /// </summary>
        /// <param name="other"></param>
        virtual void OnCollisionEnter(GameObjectBase* other) {}
        
        /// <summary>
        /// ���̃I�u�W�F�N�g�Ƃ̓����蔻��
        /// </summary>
        /// <param name="other">�������Ă���I�u�W�F�N�g�̃|�C���^</param>
        virtual void Collsion(GameObjectBase* other) {}

        /// <summary>
        /// ���̃I�u�W�F�N�g�������Ă��铖���蔻��̎�ނ��擾
        /// </summary>
        /// <returns>�����蔻��̎��</returns>
        CollisionType GetCollisionType() const { return collisionType; }

        /// <summary>
        /// �����蔻��������擾
        /// </summary>
        /// <returns>LineSegment�̃C���X�^���X</returns>
        LineSegment GetCollisionLine() const { return collisionLine; }

        /// <summary>
        /// �����蔻�苅���擾
        /// </summary>
        /// <returns>Sphere�̃C���X�^���X</returns>
        Sphere GetCollisionSphere() const { return collisionSphere; }

        /// <summary>
        /// �����蔻��J�v�Z�����擾
        /// </summary>
        /// <returns>Capsule�̃C���X�^���X</returns>
        Capsule GetCollisionCapsule() const { return collisionCapsule; }

        /// <summary>
        /// �����蔻�胂�f���̎擾
        /// </summary>
        /// <returns>collisionModel</returns>
        int GetCollisionModel() const { return collisionModel; }

    protected:
        /// <summary>
        /// �����蔻��ʒu�̍X�V
        /// </summary>
        void CollisionUpdate();

        /// <summary>
        /// �����蔻��̕`��
        /// </summary>
        void DrawCollider();

        //�I�u�W�F�N�g�̎�ނ𔻕ʂ��邽�߂̃^�O
        ObjectTag tag;
        //���ݍ��W
        VECTOR pos;
        //���f���n���h��
        int modelHandle;
        //�������邩
        bool visible;
        //�����Ă��邩
        bool alive;

        //�����蔻��֘A

        //�����蔻��̎��
        CollisionType collisionType;
        //�����蔻��֐��N���X�̃C���X�^���X
        CollisionFunction collisionFunction;
        //�����̓����蔻��N���X�̃C���X�^���X
        LineSegment collisionLine;
        //���̂̓����蔻��N���X�̃C���X�^���X
        Sphere collisionSphere;
        //�J�v�Z���̓����蔻��N���X�̃C���X�^���X
        Capsule collisionCapsule;
        //���b�V���̓����蔻��
        int collisionModel;
    };
}


