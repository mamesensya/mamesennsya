#include "GameHead.h"
#include "CObjMinimap.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"

using namespace GameL;

CObjMinimap::CObjMinimap(int map[60][80]) {
	memcpy(mapdata, map, sizeof(int) * (60 * 80));
};

void CObjMinimap::Init() {
};

void CObjMinimap::Action() {
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	
	src_x = (int)block->GetSX() - block->GetSX() - block->GetSX();
	src_y = (int)block->GetSY() - block->GetSY() - block->GetSY();

	if (hero != nullptr) {
		px = ((hero->GetX() +src_x) + 32.0f) / 64;
		py = ((hero->GetY() +src_y) + 32.0f) / 64 ;

		if (px > 5 && px < 50) scroll_x = px-6;
		if (py > 5 && py < 70) scroll_y = py-6;
	}
};

void CObjMinimap::Draw() {
	//material number is 29 / minimap size 12math x 12 math (math size 20)

	RECT_F src;
	RECT_F dst;
	float c[4] = { 1.0f,1.0f,1.0f,0.5f };
	

	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 32.0f;
	src.m_bottom = 32.0f;

	dst.m_top    = 80.0f + 0.0f;
	dst.m_left   = 560.0f;
	dst.m_right  = dst.m_left + 240.0f;
	dst.m_bottom = dst.m_top  + 240.0f;

	Draw::Draw(29, &src, &dst, c, 0);
	
	for (p=0; p < 24; p++) {

		for (s=0; s < 24; s++) {
			dst.m_top    = 80.0f+ p * 10.0f;
			dst.m_left   = 560.0f + s * 10.0f;
			dst.m_right  = dst.m_left + 10.0f;
			dst.m_bottom = dst.m_top + 10.0f;

			if (mapdata[scroll_y + p][scroll_x + s] == 1) {
				c[0] = 1.0f; c[1] = 1.0f; c[2] = 1.0f; c[3] = 0.5f;
				Draw::Draw(31, &src, &dst, c, 0);
			}
			if (mapdata[scroll_y + p][scroll_x + s] == 3) {
				c[0] = 0.0f; c[1] = 1.0f; c[2] = 0.0f; c[3] = 0.5f;
				Draw::Draw(31, &src, &dst, c, 0);
			}
			if (mapdata[scroll_y + p][scroll_x + s] == 2) {
				c[0] = 1.0f; c[1] = 1.0f; c[2] = 0.0f; c[3] = 0.5f;
				Draw::Draw(31, &src, &dst, c, 0);
			}

		}

	}

};