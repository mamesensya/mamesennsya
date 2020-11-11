#include "GameHead.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "objTitle.h"


void CObjTitles::Init() {
	for (int i = 0; i < 30; i++) {
		adjustpos[i] = (i % 10) + (i % 10);
		ease[i] = 0.0f;

	}
};

void CObjTitles::Action() {
	for (int i = 0; i < 24; i++) {
		if (phase[i] == 0) {
			if (adjustpos[i] >= 10) {
				phase[i] = 1;
			}
			else {
				adjustpos[i]+=0.5f;
			}
		}else {
			if (adjustpos[i] <= 0) {
				phase[i] = 0;
			}
			else {
				adjustpos[i]-=0.5f;
			}
		}
	}
};

void CObjTitles::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	

	for (int i = 0; i < 24; i++) {
		src.m_top = 0.0f;
		src.m_left = 0.0f + (i * 14.0f);
		src.m_right = src.m_left + 14.0f;
		src.m_bottom = src.m_top + 32.0f;

		dst.m_top = 350.0f + adjustpos[i];
		dst.m_left = 0.0f + (i * 14.0f) + 232.0f;
		dst.m_right = dst.m_left + 14.0f;
		dst.m_bottom = dst.m_top + 32.0f;


		Draw::Draw(15, &src, &dst, c, 0);
	}
};