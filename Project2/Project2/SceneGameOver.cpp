#include "GameHead.h"

#include "GameL\SceneObjManager.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "SceneGameOver.h"

using namespace GameL;

void CSceneGameOver::InitScene() {
	Audio::LoadAudio(0, L"BGMGameOver（仮）.wav", SOUND_TYPE::BACK_MUSIC);
	//バックミュージックスタート
	float v = Audio::VolumeMaster(0.8f);
	v = Audio::VolumeMaster((1.0 - v));

	Audio::Start(0);//音楽スタート

};

void CSceneGameOver::Scene() {
	wchar_t str[128];
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"G A M E   O V E R", 230, 300, 20, c);

	//エンターキーでタイトルに移行
	if (Input::GetVKey(VK_RETURN) == true)
	{
		CSceneMain* main = new CSceneMain();
		main->SetStage(0);

		Scene::SetScene(new SceneTitle);
		//チャタリング防止用
		while (Input::GetVKey(VK_RETURN) == true);
	}
};