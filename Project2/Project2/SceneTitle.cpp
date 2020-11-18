#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


#include "GameHead.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "objTitle.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"


using namespace GameL;

void SceneTitle::InitScene() {

	Draw::LoadImageW(L"title.png", 15, TEX_SIZE_1024);
	
	CObjTitles* tobj = new CObjTitles();
	Objs::InsertObj(tobj, OBJ_TITLEFONT, 100);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"BGMTitle（仮）.wav", SOUND_TYPE::BACK_MUSIC);
	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.8f);//マスターボリュームを0.8下げる
	Audio::Start(0);//音楽スタート
};

void SceneTitle::Scene() {
	if (Input::GetVKey('Z') == true) {
		if (keyover == false) {
			Scene::SetScene(new CSceneMain);
			keyover = true;
		}
	}
	else {
		keyover = false;
	}
	float c[4] = {1.0f,1.0f,1.0f,1.0f};
	Font::StrDraw(L"豆戦車",208,100 ,128, c);
	Font::StrDraw(L"(C) CopyRight 2020 Team.Inverse", 245,580,20, c);
	

	

}