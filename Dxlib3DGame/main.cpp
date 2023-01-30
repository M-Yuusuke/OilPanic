#include "DxLib.h"
#include "Scene/SceneBase/SceneBase.h"
#include "Scene/SceneManager/SceneManager.h"
#include "GameObject/GameObjectBase/GameObjectBase.h"
#include "GameObject/GameObjectManager/GameObjectManager.h"
#include "GameObject/AssetManager/AssetManager.h"
#include "System/Rule/Rule.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �c�w���C�u��������������
	SetUseDirect3DVersion(DX_DIRECT3D_11);
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}
	//�t���X�N���[�����[�h
	ChangeWindowMode(FALSE);
	//�𑜓x�E�J���[�r�b�g���̎w��
	SetGraphMode(1920, 1080, 32);

	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);

	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(TRUE);

	//�Q�[���I�u�W�F�N�g�}�l�[�W���𐶐�
	Calculation::GameObjectManager::CreateInstance();
	//�A�Z�b�g�}�l�[�W���𐶐�
	Calculation::AssetManager::CreateInstance();

	SceneManager* sceneManager = SceneManager::CreateInstance();
	SceneBase* scene = nullptr;
	scene = sceneManager->NextScene(scene);

	//�Q�[�����[�v
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		LONGLONG time = GetNowHiPerformanceCount();
		scene = scene->Update();
		scene->Draw();
		//�t���[�����[�g�Œ�
		while (GetNowHiPerformanceCount() - time < 16667) {}
	}
	Calculation::GameObjectManager::DestroyInstance();
	Calculation::AssetManager::DestroyInstance();
	SceneManager::DestroyInstance();
	sceneManager = nullptr;
	scene = nullptr;
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I��
}