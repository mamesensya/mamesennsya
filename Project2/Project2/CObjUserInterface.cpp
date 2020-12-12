#include "GameHead.h"
#include "ObjUserInterface.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include <time.h>
using namespace GameL;



void CObjUserInterface::Init() {
};

void CObjUserInterface::Action() {

};

void CObjUserInterface::Draw() {

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	clock_t timeset; timeset = clock();

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChara* human = (CObjChara*)Objs::GetObj(OBJ_CHARA);
	
	if (hero != nullptr) {
		viewhp = hero->GetHP();
		bullet[0] = hero->GetBullet();
		bullet[1] = hero->GetUBulletA();
		bullet[2] = hero->GetUBulletB();
		state = hero->GetHeroState();
		
	}
	if (human != nullptr) {viewhpB = human->GetHP();}
	

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 32.0f;
	src.m_bottom = src.m_top + 32.0f;
	
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = dst.m_left + 300.0f;
	dst.m_bottom = dst.m_top + 48.0f;

	Draw::Draw(26, &src, &dst, c, 0);

	dst.m_top = 64.0f;
	dst.m_left = 0.0f;
	dst.m_right = dst.m_left + 300.0f;
	dst.m_bottom = dst.m_top + 32.0f;

	Draw::Draw(26, &src, &dst, c, 0);

	wchar_t str[128];
	swprintf_s(str, L"écÇËìGÇÃêîÅF%d", setenemyMax);
	Font::StrDraw(str, 20, 70, 20, c);

	Font::StrDraw(L"ëÃóÕ", 20, 10, 20, c);
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 32.0f;
	src.m_bottom = src.m_top + 32.0f;
	if (state == false) {
		for (int i = 0; i < 5; i++) {
			dst.m_top = 8.0f;
			dst.m_left = 100.0f + (32.0f * i);
			dst.m_right = dst.m_left + 32.0f;
			dst.m_bottom = dst.m_top + 32.0f;
			c[0] = 0.0f, c[1] = 0.0f, c[2] = 0.0f;
			Draw::Draw(23, &src, &dst, c, 0);
		}

		for (int i = 0; i < viewhp; i++) {
			dst.m_top = 8.0f;
			dst.m_left = 100.0f + (32.0f * i);
			dst.m_right = dst.m_left + 32.0f;
			dst.m_bottom = dst.m_top + 32.0f;

			c[0] = 1.0f, c[1] = 1.0f, c[2] = 1.0f;
			Draw::Draw(23, &src, &dst, c, 0);
		}

	}else {
		for (int i = 0; i < 2; i++) {
			dst.m_top = 8.0f;
			dst.m_left = 100.0f + (32.0f * i);
			dst.m_right = dst.m_left + 32.0f;
			dst.m_bottom = dst.m_top + 32.0f;
			c[0] = 0.0f, c[1] = 0.0f, c[2] = 0.0f;
			Draw::Draw(23, &src, &dst, c, 0);
		}
		for (int i = 0; i < viewhpB; i++) {
			dst.m_top = 8.0f;
			dst.m_left = 100.0f + (32.0f * i);
			dst.m_right = dst.m_left + 32.0f;
			dst.m_bottom = dst.m_top + 32.0f;

			c[0] = 1.0f, c[1] = 1.0f, c[2] = 1.0f;
			Draw::Draw(24, &src, &dst, c, 0);
		}

	}
	

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


		c[0] = 0.0f, c[1] = 0.0f, c[2] = 0.0f;
		if (bullet[0] > 0) c[3] = 1.0f; else c[3] = 0.2f;
		swprintf_s(str, L"x%d", bullet[0]);
		Font::StrDraw(str, 655, 344, 20, c);
		Font::StrDraw(L"í èÌíeî≠éÀ", 655, 364, 20, c);

		if (bullet[1] > 0) c[3] = 1.0f; else c[3] = 0.2f;
		swprintf_s(str, L"x%d", bullet[1]);
		Font::StrDraw(str, 655, 404, 20, c);
		Font::StrDraw(L"ä—í íeî≠éÀ", 655, 424, 20, c);

		if (bullet[2] > 0) c[3] = 1.0f; else c[3] = 0.2f;
		swprintf_s(str, L"x%d", bullet[2]);
		Font::StrDraw(str, 655, 464, 20, c);
		Font::StrDraw(L"ÇRï˚å¸î≠éÀ", 655, 484, 20, c);

		c[3] = 1.0f;
		Font::StrDraw(L"ç~ÇËÇÈ", 655, 544, 20, c);



	}
	else {

		c[3] = 0.5f;
		if (human!=nullptr)flug = human -> m_hit_tank;

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
		Font::StrDraw(L"çUåÇ", 655, 484, 20, c);

		if (flug == false) c[3] = 0.2f; else c[3] = 1.0f;
		Font::StrDraw(L"èÊÇÈ", 655, 544, 20, c);
	}

	c[0] = 1.0f; c[1] = 1.0f; c[2] = 1.0f; c[3] = 1.0f;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 32.0f;
	src.m_bottom = src.m_top + 32.0f;

	dst.m_top = 0.0f;
	dst.m_left = 650.0f;
	dst.m_right = dst.m_left + 250.0f;
	dst.m_bottom = dst.m_top + 48.0f;

	Draw::Draw(26, &src, &dst, c, 0);

	swprintf_s(str, L"ÉXÉeÅ[ÉW%d", playstage);
	Font::StrDraw(str, 680, 15, 20, c);

	c[0] = 1.0f; c[1] = 1.0f; c[2] = 1.0f; c[3] = 1.0f;

	//344 - 404 - 464
	if (getflugs) {
		if (waitcount <= 200) {
			if (state){
			swprintf_s(uistr[0], L"Å@í èÌíe+%d", getguns[0]);
			swprintf_s(uistr[1], L"Å@ä—í íe+%d", getguns[1]);
			swprintf_s(uistr[2], L"ÇRï˚å¸íe+%d", getguns[2]);
			for (int i = 0; i < 3; i++) {
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 32.0f;
				src.m_bottom = src.m_top + 32.0f;

				dst.m_top = 344.0f + (60 * i);
				dst.m_left = 655.0f;
				dst.m_right = dst.m_left + 150.0f;
				dst.m_bottom = dst.m_top + 20.0f;

				Draw::Draw(26, &src, &dst, c, 0);

				Font::StrDraw(uistr[i], 655, 344 + (60 * i), 20, c);
			};
		}else {
			for (int i = 0; i < 3; i++) {
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 32.0f;
				src.m_bottom = src.m_top + 32.0f;

				dst.m_top = 344.0f + (60 * i);
				dst.m_left = 700.0f;
				dst.m_right = dst.m_left + 50.0f;
				dst.m_bottom = dst.m_top + 20.0f;

				Draw::Draw(26, &src, &dst, c, 0);

				swprintf_s(uistr[i], L"+%d", getguns[i]);
				Font::StrDraw(uistr[i], 700, 344 + (60 * i), 20, c);
			}
		}
		waitcount++;
	}else {
		waitcount = 0;
		getflugs = false;
	}
	}
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 32.0f;
	src.m_bottom = src.m_top + 32.0f;

	switch (stagestate) {
	case 0:

		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = dst.m_left + 800.0f;
		dst.m_bottom = dst.m_top + faders[0];
		Draw::Draw(29, &src, &dst, c, 0.0f);
		dst.m_top = 600.0f;
		dst.m_left = 0.0f;
		dst.m_right = dst.m_left + 800.0f;
		dst.m_bottom = dst.m_top - faders[0];
		Draw::Draw(29, &src, &dst, c, 0.0f);
		if (faders[0] > 0) {
			faders[0] = faders[0] - ease;
			ease+=0.5;
		}
		else {
			faders[0] = 0;
			faders[1] = 0;
			stagestate++;
		};
		break;
	case 2:
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = dst.m_left + 800.0f;
		dst.m_bottom = dst.m_top + faders[0];
		Draw::Draw(29, &src, &dst, c, 0.0f);
		dst.m_top = 600.0f;
		dst.m_left = 0.0f;
		dst.m_right = dst.m_left + 800.0f;
		dst.m_bottom = dst.m_top - faders[0];
		Draw::Draw(29, &src, &dst, c, 0.0f);
		if (faders[0] < 300) {
			faders[0] = faders[0] + ease;
			ease += 0.5;
		}
		else {
			faders[0] = 0;
			faders[1] = 0;
			stagestate = 0;
			Scene::SetScene(new CSceneMain());
		};
		break;
		break;
	case 3:
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = dst.m_left + 800.0f;
		dst.m_bottom = dst.m_top + faders[0];
		Draw::Draw(29, &src, &dst, c, 0.0f);
		dst.m_top = 600.0f;
		dst.m_left = 0.0f;
		dst.m_right = dst.m_left + 800.0f;
		dst.m_bottom = dst.m_top - faders[0];
		Draw::Draw(29, &src, &dst, c, 0.0f);
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = dst.m_left + faders[1];
		dst.m_bottom = dst.m_top + 600.0f;
		Draw::Draw(29, &src, &dst, c, 0.0f);
		dst.m_top = 0.0f;
		dst.m_left = 800.0f;
		dst.m_right = dst.m_left - faders[1];
		dst.m_bottom = dst.m_top + 600.0f;
		Draw::Draw(29, &src, &dst, c, 0.0f);
		if (faders[0] < 300) faders[0] = faders[0] + ease;
		if (faders[1] < 400) faders[1] = faders[1] + ease;
		if ((faders[0] + faders[1]) > 700)Scene::SetScene(new CSceneGameOver());
		ease += 0.5;
		break;
	default:
		break;
	};

};