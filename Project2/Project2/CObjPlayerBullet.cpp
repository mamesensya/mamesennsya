#include "GameHead.h"
#include "CObjPlayerBullet.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneManager.h"



using namespace GameL;

CObjPlayerBullet::CObjPlayerBullet(float x, float y, float r) {
	m_x = x;
	m_y = y;
	m_r = r;
};

void CObjPlayerBullet::Init() {
	int x;
	int y;
	int r;
	m_vx = 0;
	m_vy = 0;

	
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_RED, OBJ_ANGLE_BULLET, 1);
};

void CObjPlayerBullet::Action() {

		CHitBox* Hit = Hits::GetHitBox(this);
		
		m_vx = cos(3.14 / 180.0f * m_r);
		m_vy = sin(3.14 / 180.0f * m_r);

		m_x += m_vx * m_speed;
		m_y += m_vy * m_speed;

		Hit->SetPos(m_x, m_y);

		if (Hit->CheckObjNameHit(OBJ_ENEMY) != nullptr) {
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
};

void CObjPlayerBullet::Draw() {
	float c[4] = {1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f+m_y;
	dst.m_left = 0.0f+m_x;
	dst.m_right = 64.0f+m_x;
	dst.m_bottom = 64.0f+m_y;

	Draw::Draw(14, &src, &dst, c, m_r);
};