#include "GameHead.h"

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "SceneGameOver.h"

using namespace GameL;

void CSceneGameOver::InitScene() {
	Audio::LoadAudio(0, L"BGMGameOver（仮）.wav", SOUND_TYPE::BACK_MUSIC);
	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.8f);//マスターボリュームを0.8下げる
	Audio::Start(0);//音楽スタート

};

void CSceneGameOver::Scene() {
	wchar_t str[128];
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"G A M E   O V E R", 230, 300, 20, c);
};