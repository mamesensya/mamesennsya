#include "GameHead.h"
#include "ObjUserInterface.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"

using namespace GameL;


void CObjUserInterface::Init() {

};

void CObjUserInterface::Action() {

};

void CObjUserInterface::Draw() {

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	int viewhp = hero->GetHP();
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 32.0f;
	src.m_bottom = src.m_top + 32.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = dst.m_left + 300.0f;
	dst.m_bottom = dst.m_top + 48.0f;

	

	Draw::Draw(26, &src, &dst, c, 0);
	Font::StrDraw(L"�̗�", 20, 10, 20, c);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 32.0f ;
	src.m_bottom = src.m_top + 32.0f;
	for (int i = 0; i < viewhp; i++) {
		dst.m_top = 8.0f ;
		dst.m_left = 100.0f + (32.0f * i);
		dst.m_right = dst.m_left + 32.0f ;
		dst.m_bottom = dst.m_top + 32.0f;

		Draw::Draw(23, &src, &dst, c, 0);
	}
};