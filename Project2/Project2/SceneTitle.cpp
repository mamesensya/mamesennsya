#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


#include "GameHead.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "objTitle.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"

using namespace GameL;

void SceneTitle::InitScene() {

	Draw::LoadImageW(L"title.png", 1, TEX_SIZE_1024);
	
	CObjTitles* tobj = new CObjTitles();
	Objs::InsertObj(tobj, OBJ_TITLEFONT, 1);
	
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
	Font::StrDraw(L"ì§êÌé‘",208,100 ,128, c);
	Font::StrDraw(L"(C) CopyRight 2020 Team.Inverse", 245,580,20, c);
	
	
}