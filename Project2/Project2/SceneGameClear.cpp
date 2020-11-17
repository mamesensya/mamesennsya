#include "GameHead.h"

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "SceneGameClear.h"

using namespace GameL;

void CSceneGameClear::InitScene() {
	Audio::LoadAudio(0, L"BGMGame2（仮）.wav", SOUND_TYPE::BACK_MUSIC);
	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.8f);//マスターボリュームを0.8下げる
	Audio::Start(0);//音楽スタート

};

void CSceneGameClear::Scene() {
	wchar_t str[128];
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"G A M E   C L E A R", 300, 300, 20, c);
};