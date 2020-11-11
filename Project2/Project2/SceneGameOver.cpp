#include "GameHead.h"

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "SceneGameOver.h"

using namespace GameL;

void CSceneGameOver::InitScene() {

};

void CSceneGameOver::Scene() {
	wchar_t str[128];
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"G A M E   O V E R", 230, 300, 20, c);
};