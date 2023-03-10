#include <vector>
#include "GameObjectManager.h"
#include "../Objects/CharacterBase/CharacterBase.h"
using namespace std;
namespace Calculation
{
    GameObjectManager* GameObjectManager::Instance = nullptr;

    /// <summary>
    /// このクラスのインスタンス生成
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
    /// このクラスのインスタンス破棄
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
    /// ゲームオブジェクトの登録
    /// </summary>
    /// <param name="newObj">登録するオブジェクトのポインタ</param>
    void GameObjectManager::Entry(GameObjectBase* newObj)
    {
        Instance->PendingObjects.push_back(newObj);
    }

    /// <summary>
    /// ゲームオブジェクトの削除
    /// </summary>
    /// <param name="releaseObj">削除するオブジェクトのポインタ</param>
    void GameObjectManager::Release(GameObjectBase* releaseObj)
    {
        //ペンディングオブジェクト内から検索
        auto itr = std::find(Instance->PendingObjects.begin(), Instance->PendingObjects.end(), releaseObj);
        if (itr != Instance->PendingObjects.end())
        {
            //見つけたオブジェクトを最後尾に移動してデータを消す
            std::iter_swap(itr, Instance->PendingObjects.end() - 1);
            Instance->PendingObjects.pop_back();

            return;
        }

        //解放するオブジェクトのタグを得る
        ObjectTag tag = releaseObj->GetTag();

        //アクティブオブジェクト内から削除オブジェクトを検索
        itr = std::find(Instance->Objects[tag].begin(), Instance->Objects[tag].end(), releaseObj);
        if (itr != Instance->Objects[tag].end())
        {
            //見つけたオブジェクトを末尾に移動し、削除
            std::iter_swap(itr, Instance->Objects[tag].end() - 1);
            delete Instance->Objects[tag].back();
            //末尾に移動したコンテナを削除
            Instance->Objects[tag].erase(Instance->Objects[tag].end() - 1);
        }
    }

    /// <summary>
    /// 全オブジェクト削除
    /// </summary>
    void GameObjectManager::ReleaseAllObj()
    {
        //末尾からペンディングオブジェクトを全て削除
        while (!Instance->PendingObjects.empty())
        {
            delete Instance->PendingObjects.back();
        }
        
        //全てのアクティブオブジェクトを削除
        for (auto& tag : ObjectTagAll)
        {
            //末尾から削除
            while (!Instance->Objects[tag].empty())
            {
                delete Instance->Objects[tag].back();
                Instance->Objects[tag].pop_back();
            }
        }
    }

    /// <summary>
    /// 登録されているオブジェクトの初期化処理
    /// </summary>
    void GameObjectManager::Init()
    {
        //ペンディング中のオブジェクトをアクティブリストに追加
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
    /// 登録されているオブジェクトの更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void GameObjectManager::Update(float deltaTime)
    {
        //全てのアクターの更新
        for (auto& tag : ObjectTagAll)
        {
            //該当タグにある全てのオブジェクトを更新
            for (int i = 0; i < Instance->Objects[tag].size(); i++)
            {
                Instance->Objects[tag][i]->Update(deltaTime);
            }
        }
        //ペンディング中のオブジェクトをアクティブリストに追加
        for (auto pending : Instance->PendingObjects)
        {
            ObjectTag tag = pending->GetTag();
            Instance->Objects[tag].emplace_back(pending);
        }
        Instance->PendingObjects.clear();

        //全てのアクター内で死んでいるアクターをDeadObjectへ一時保管
        std::vector<GameObjectBase*> deadObjects;
        for (auto& tag : ObjectTagAll)
        {
            for (auto obj : Instance->Objects[tag])
            {
                if (!obj->IsAlive())
                {
                    deadObjects.emplace_back(obj);
                }
            }
            Instance->Objects[tag].erase(remove_if(begin(Instance->Objects[tag]), end(Instance->Objects[tag]),
                [](GameObjectBase* g) {return !g->IsAlive(); }), cend(Instance->Objects[tag]));
        }
        // 死んでいるGameObjectをここでdelete
        while (!deadObjects.empty())
        {
            delete deadObjects.back();
            deadObjects.pop_back();
        }
    }

    /// <summary>
    /// 描画処理
    /// </summary>
    void GameObjectManager::Draw()
    {
        for (auto& tag : ObjectTagAll)
        {
            for (int i = 0; i < Instance->Objects[tag].size(); i++)
            {
                //描画対象だけ描画
                if (Instance->Objects[tag][i]->IsVisible())
                {
                    Instance->Objects[tag][i]->Draw();
                }
            }
        }
    }

    /// <summary>
    /// 他のオブジェクトとの当たり判定
    /// </summary>
    void GameObjectManager::Collision()
    {
        //バケツとオイルとの当たり判定
        for (int oilNum = 0; oilNum < Instance->Objects[ObjectTag::Oil].size(); oilNum++)
        {
            Instance->Objects[ObjectTag::Bucket][0]->OnCollisionEnter(Instance->Objects[ObjectTag::Oil][oilNum]);
        }
        for (int playerOilNum = 0; playerOilNum < Instance->Objects[ObjectTag::PlayerOil].size(); playerOilNum++)
        {
            //プレイヤーが汲み取ったオイルとお手伝いさんとの当たり判定
            Instance->Objects[ObjectTag::PlayerOil][playerOilNum]->OnCollisionEnter(Instance->Objects[ObjectTag::Helper][0]);
            //お客とプレイヤーが汲み取ったオイルとの当たり判定
            Instance->Objects[ObjectTag::PlayerOil][playerOilNum]->OnCollisionEnter(Instance->Objects[ObjectTag::Customer][0]);
        }
    }

    /// <summary>
    /// 対象のタグの生きている最初のオブジェクト
    /// </summary>
    /// <param name="tag">検索したいオブジェクトのタグ</param>
    /// <returns>対象のタグの一番最初に登録されているオブジェクトのポインタ</returns>
    GameObjectBase* GameObjectManager::GetFirstGameObject(ObjectTag tag)
    {
        if (Instance->Objects[tag].size() == 0)
        {
            return nullptr;
        }
        return Instance->Objects[tag][0];
    }
}