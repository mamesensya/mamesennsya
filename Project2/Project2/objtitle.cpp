#include "GameHead.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "objTitle.h"

void CObjTitles::Init() {
	
};

void CObjTitles::Action() {
	
};

void CObjTitles::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	/*src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 14.0f;
	src.m_bottom = 32.0f;

	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = dst.m_left + 14.0f;
	dst.m_bottom = dst.m_top + 32.0f;


	Draw::Draw(15, &src, &dst, c, 0);*/
	for (int i = 0; i < 24; i++) {
		src.m_top = 0.0f;
		src.m_left = 0.0f + (i * 14.0f);
		src.m_right = src.m_left + 14.0f;
		src.m_bottom = 32.0f;

		dst.m_top =300.0f + adjustpos[i];
		dst.m_left = 0.0f + (i * 14.0f) + 232.0f;
		dst.m_right = dst.m_left + 14.0f;
		dst.m_bottom = dst.m_top + 32.0f;


		Draw::Draw(15, &src, &dst, c, 0);
	}
};