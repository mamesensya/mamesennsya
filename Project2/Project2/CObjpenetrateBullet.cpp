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

	int data_base2[8] =
	{
		OBJ_ENEMY_BULLET,
		OBJ_ENEMY_3BULLET,
		OBJ_BOSS_BULLET,
		OBJ_BOSS_BULLET2,
		OBJ_BOSS_BULLET4,
		OBJ_ENEMY,
		OBJ_BOSS,
		OBJ_BOSS2,
	};


	CObjBlock* bbh = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	bbh->BlockHit(&m_x, &m_y, &m_up, &m_down, &m_reft, &m_right, &m_vx, &m_vy);

	for (int i = 0; i <= 7; i++)
	{
		if (Hit->CheckObjNameHit(data_base2[i]) != nullptr)
		{
			Effect* effect = new Effect(m_x, m_y, m_r);
			Objs::InsertObj(effect, OBJ_EFFECT, 20);

			m_hit = false;
		}

	}
	

	for (int i = 0; i <= 3; i++)
	{

		if (data_base[i] == true)
		{
			Effect* effect = new Effect(m_x, m_y, m_r);
			Objs::InsertObj(effect, OBJ_EFFECT, 20);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
	for (int i = 0; i <= 7; i++)
	{
		if (Hit->CheckObjNameHit(data_base2[i]) != nullptr)
		{
			Effect* effect = new Effect(m_x, m_y, m_r);
			Objs::InsertObj(effect, OBJ_EFFECT, 20);

		if (pbullet_enable == true) 
		{
			pbullet_interval++;
			 if (pbullet_interval > 7) 
			 {
				pbullet_interval = 0;
				pbullet_enable = false;
			}
		}

		}

	}
	
};

void CObjPenetrateBullet::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 265.0f;
	src.m_bottom = 265.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(11, &src, &dst, c, 0);
};