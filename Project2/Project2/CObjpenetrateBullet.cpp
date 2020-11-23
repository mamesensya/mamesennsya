#include "GameL\SceneObjManager.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "CObjpenetrateBullet.h"
#include "GameL\HitBoxManager.h"

using namespace GameL;

CObjPenetrateBullet::CObjPenetrateBullet(float x, float y, float r) {
	m_x = x+32;
	m_y = y+32;
	m_r = r;
};

void CObjPenetrateBullet::Init() {
	m_vx = 0;
	m_vy = 0;
	interval = 0;
	intervalEnable = false;
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_RED, OBJ_PENETRATE_BULLET, 1);
};

void CObjPenetrateBullet::Action() {
	CHitBox* Hit = Hits::GetHitBox(this);
	
	m_vx = cos(3.14 / 180.0f * m_r);
	m_vy = sin(3.14 / 180.0f * m_r);

	m_x += m_vx * 7.0f;
	m_y += m_vy * 7.0f;

	
	Hit->SetPos(m_x, m_y);

	CObjBlock* bbh = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	bbh->Block_BulletHit(&m_x, &m_y, &m_hit, &m_vx, &m_vy);
	if (m_hit == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	
};

void CObjPenetrateBullet::Draw() {
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