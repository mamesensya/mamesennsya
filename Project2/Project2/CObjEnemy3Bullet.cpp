#include "GameHead.h"
#include "CObjEnemy3.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneManager.h"



using namespace GameL;

CObjEnemy3B::CObjEnemy3B(float x, float y, float r) {
	m_x = x + 32;
	m_y = y + 32;
	m_r = r;
};

void CObjEnemy3B::Init() {
	m_vx = 0;
	m_vy = 0;

	m_speed = 7;
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_3BULLET, 1);
};

void CObjEnemy3B::Action() {

	CHitBox* Hit = Hits::GetHitBox(this);

	m_vx = cos(3.14 / 180.0f * m_r);
	m_vy = sin(3.14 / 180.0f * m_r);

	m_x += m_vx * m_speed;
	m_y += m_vy * m_speed;

	Hit->SetPos(m_x, m_y);

	if (Hit->CheckObjNameHit(OBJ_HERO) != nullptr) {
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
};

void CObjEnemy3B::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 768.0f;
	src.m_bottom = 768.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(14, &src, &dst, c, 0);
};