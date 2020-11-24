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
	CObjChara* human = (CObjChara*)Objs::GetObj(OBJ_CHARA);

	int viewhp = hero->GetHP();

	int bullet[3] = {
		hero->GetBullet(),
		hero->GetUBulletA(),
		hero->GetUBulletB()
	};
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
	Font::StrDraw(L"‘Ì—Í", 20, 10, 20, c);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 32.0f ;
	src.m_bottom = src.m_top + 32.0f;
	for (int i = 0; i < 5; i++) {
		dst.m_top = 8.0f;
		dst.m_left = 100.0f + (32.0f * i);
		dst.m_right = dst.m_left + 32.0f;
		dst.m_bottom = dst.m_top + 32.0f;
		c[0] = 0.0f, c[1] = 0.0f, c[2] = 0.0f;
		Draw::Draw(23, &src, &dst, c, 0);
	}
	for (int i = 0; i < viewhp; i++) {
		dst.m_top = 8.0f ;
		dst.m_left = 100.0f + (32.0f * i);
		dst.m_right = dst.m_left + 32.0f ;
		dst.m_bottom = dst.m_top + 32.0f;

		c[0] = 1.0f, c[1] = 1.0f, c[2] = 1.0f;
		Draw::Draw(23, &src, &dst, c, 0);
	}
	bool state = hero->GetHeroState();
	
	if (state == false) {
		c[3] = 0.5f;

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 48.0f;
		src.m_bottom = src.m_top + 48.0f;

		for (int i = 0; i < 4; i++) {
			if (i < 3) {
				if (bullet[i] > 0) c[3] = 0.5f; else c[3] = 0.2f;
			}
			else {
				c[3] = 0.5f;
			}
			dst.m_top = 350.0f + (60.0f * i);
			dst.m_left = 600.0f;
			dst.m_right = 48.0f + dst.m_left;
			dst.m_bottom = 48.0f + dst.m_top;


			c[0] = 1.0f, c[1] = 1.0f, c[2] = 1.0f;
			Draw::Draw(27, &src, &dst, c, 0);

			src.m_left = i * 48.0f;
			src.m_right = src.m_left + 48.0f;

			dst.m_top = 350.0f + (60.0f * i);
			dst.m_left = 600.0f;
			dst.m_right = 48.0f + dst.m_left;
			dst.m_bottom = 48.0f + dst.m_top;

			if (i < 3) {
				if (bullet[i] > 0) c[3] = 1.0f; else c[3] = 0.5f;
			}
			else {
				c[3] = 1.0f;
			}
			Draw::Draw(28, &src, &dst, c, 0);
		}
		wchar_t str[128];

		c[0] = 0.0f, c[1] = 0.0f, c[2] = 0.0f;
		if (bullet[0] > 0) c[3] = 1.0f; else c[3] = 0.2f;
		swprintf_s(str, L"x%d", bullet[0]);
		Font::StrDraw(str, 655, 344, 20, c);
		Font::StrDraw(L"’Êí’e”­ŽË", 655, 364, 20, c);

		if (bullet[1] > 0) c[3] = 1.0f; else c[3] = 0.2f;
		swprintf_s(str, L"x%d", bullet[1]);
		Font::StrDraw(str, 655, 404, 20, c);
		Font::StrDraw(L"ŠÑ’Ê’e”­ŽË", 655, 424, 20, c);

		if (bullet[2] > 0) c[3] = 1.0f; else c[3] = 0.2f;
		swprintf_s(str, L"x%d", bullet[2]);
		Font::StrDraw(str, 655, 464, 20, c);
		Font::StrDraw(L"‚R•ûŒü”­ŽË", 655, 484, 20, c);

		c[3] = 1.0f;
		Font::StrDraw(L"~‚è‚é", 655, 544, 20, c);

	

	}else {

		c[3] = 0.5f;
		flug = human->m_hit_tank;

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 48.0f;
		src.m_bottom = src.m_top + 48.0f;

		for (int i = 0; i < 2; i++) {
			c[3] = 0.5f;
			if (i == 1) {
				if (flug == true)c[3] = 0.5f; else c[3] = 0.2f;
			}

			dst.m_top = 470.0f + (60.0f * i);
			dst.m_left = 600.0f;
			dst.m_right = 48.0f + dst.m_left;
			dst.m_bottom = 48.0f + dst.m_top;


			Draw::Draw(27, &src, &dst, c, 0);

			src.m_left = i * 144.0f;
			src.m_right = src.m_left + 48.0f;

			dst.m_top = 470.0f + (60.0f * i);
			dst.m_left = 600.0f;
			dst.m_right = 48.0f + dst.m_left;
			dst.m_bottom = 48.0f + dst.m_top;

			c[3] = 1.0f;
			if (i == 1) {
				if (flug == true)c[3] = 1.0f; else c[3] = 0.5f;
			}

			Draw::Draw(28, &src, &dst, c, 0);
		}
		c[0] = 0.0f, c[1] = 0.0f, c[2] = 0.0f, c[3] = 1.0f;
		Font::StrDraw(L"UŒ‚", 655, 484, 20, c);

		if (flug == false) c[3] = 0.2f; else c[3] = 1.0f;
		Font::StrDraw(L"æ‚é", 655, 544, 20, c);
	}
};