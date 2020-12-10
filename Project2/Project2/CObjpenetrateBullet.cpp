#include "GameL\SceneObjManager.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "CObjpenetrateBullet.h"
#include "GameL\HitBoxManager.h"

using namespace GameL;

CObjPenetrateBullet::CObjPenetrateBullet(float x, float y, float r) {
	m_x = x+20;
	m_y = y+20;
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

	m_x += m_vx * 6.0f;
	m_y += m_vy * 6.0f;

	
	Hit->SetPos(m_x, m_y);

	int data_base[4] =
	{
		m_up,m_down,m_reft,m_right
	};


	CObjBlock* bbh = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	bbh->BlockHit(&m_x, &m_y, &m_up, &m_down, &m_reft, &m_right, &m_vx, &m_vy);

	

	for (int i = 0; i <= 3; i++)
	{
		/*if ((m_right==true&&m_vx<0)||(m_down==true&&m_vy>0))
		{
			;
		}*/
		if (data_base[i] == true)
		{
			Effect* effect = new Effect(m_x, m_y, m_r);
			Objs::InsertObj(effect, OBJ_EFFECT, 20);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
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