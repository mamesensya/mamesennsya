#include "GameL\SceneObjManager.h"
#include "ObjSaveSys.h"

#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"

using namespace GameL;

void CObjSaveSystem::Init() {

};

void CObjSaveSystem::Action() {
};

void CObjSaveSystem::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,alpha };
	wchar_t str[128];

	if (savemode == 1) {
		if (viewtime < 200) {

			if (drawphase == 0) {
				if (alpha >= 1.0f) drawphase = 1;
				alpha += 0.05f;
			}
			else if (drawphase == 1) {
				if (alpha <= 0.0f) drawphase = 0;
				alpha -= 0.05f;
			}

			viewtime++;
		}else {
			savemode = 0;
			viewtime = 0;
			alpha = 0;
		}

		/*RECT_F src;
		RECT_F dst;

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 400.0f;
		src.m_bottom = src.m_top + 64.0f;

		dst.m_top = 536.0f;
		dst.m_left = 20.0f;
		dst.m_right =  dst.m_left + 400.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(25, &src, &dst, c, 0);*/

		Font::StrDraw(L"Now Saving...", 20, 570, 25, c);
	}
};