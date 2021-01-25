#include "GameHead.h"

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\WinInputs.h"
#include "SceneGameClear.h"

using namespace GameL;

void CSceneGameClear::InitScene() {
	Audio::LoadAudio(0, L"BGMGame2（仮）.wav", SOUND_TYPE::BACK_MUSIC);
	//バックミュージックスタート
	float v = Audio::VolumeMaster(0.8f);
	v = Audio::VolumeMaster((1.0 - v));
	Audio::Start(0);//音楽スタート

};

void CSceneGameClear::Scene() 
{
	wchar_t str[128];

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"G A M E   C L E A R", 300, 300, 20, c);

	//エンターキーでタイトルに移行
	if (Input::GetVKey(VK_RETURN) == true)
	{
		CSceneMain* main = new CSceneMain();
		main->SetStage();

		Scene::SetScene(new SceneTitle);
		//チャタリング防止用
		while (Input::GetVKey(VK_RETURN) == true);
	}
};