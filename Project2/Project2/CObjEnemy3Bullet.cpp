#include "GameHead.h"
#include "CObjEnemy3Bullet.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"



using namespace GameL;

CObjEnemy3B::CObjEnemy3B(float x, float y, float r) {
	m_x = x + 10 ;
	m_y = y + 10 ;
	m_r = r;
};

void CObjEnemy3B::Init() {
	m_vx = 0;
	m_vy = 0;
	mx=0;
	my = 0;


	m_speed = 2;
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_3BULLET, 1);
};

void CObjEnemy3B::Action() {

	CHitBox* Hit = Hits::GetHitBox(this);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	CObjEnemy3* Ebs = (CObjEnemy3*)Objs::GetObj(OBJ_ENEMY);
	float Bx = Ebs->GetX();
	float By = Ebs->GetY();

	m_vx = cos(3.14 / 180.0f * m_r);
	m_vy = sin(3.14 / 180.0f * m_r);

	

	m_x += m_vx * m_speed;
	m_y += m_vy * m_speed;

	
	
	m_x += m_vx;
	m_y += m_vy;

	mx += m_vx;
	my += m_vy;

	Bx += mx+m_scroll_map_x;
	By += my+m_scroll_map_y;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);



	CObjBlock* bbh = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	bbh->BlockHit(&Bx, &By, &m_up, &m_down, &m_reft, &m_right, &m_vx, &m_vy);

	int data_base[4] =
	{
		m_up,m_down,m_reft,m_right
	};

	for (int i = 0; i <= 3; i++)
	{
		if (data_base[i] == true)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	if (Hit->CheckObjNameHit(OBJ_HERO) != nullptr) {
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//主人公（人）と接触しているか調べる
	if (Hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		this->SetStatus(false);//削除命令
		Hits::DeleteHitBox(this);//削除
	}


	if (mx >= 500.0f || mx <= -500.0f || my >= 500.0f || my <= -500.0f)
	{
		this->SetStatus(false);//削除命令
		Hits::DeleteHitBox(this);//削除
		mx = 0;
		my = 0;
	}
};

void CObjEnemy3B::Draw() {
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	dst.m_top = 0.0f + m_y+m_scroll_map_y;
	dst.m_left = 0.0f + m_x+m_scroll_map_x;
	dst.m_right = 32.0f + m_x+m_scroll_map_x;
	dst.m_bottom = 32.0f + m_y+m_scroll_map_y;

	Draw::Draw(2, &src, &dst, c, 0);
};