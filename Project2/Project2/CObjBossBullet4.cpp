#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjBossBullet4.h"

using namespace GameL;

CObjBossBullet4::CObjBossBullet4(float x, float y, float r)
{
	m_x = x + 85;
	m_y = y + 85;
	m_r = r;
}

void CObjBossBullet4::Init()
{
	//スクロール情報をもらう
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	//HitBox作成
	Hits::SetHitBox(this, m_x+m_scroll_map_x, m_y+m_scroll_map_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

void CObjBossBullet4::Action()
{
	CHitBox* Hit = Hits::GetHitBox(this);

	//スクロール情報をもらう
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	m_vx = cos(3.14 / 180.0f * m_r);
	m_vy = sin(3.14 / 180.0f * m_r);

	m_x += m_vx * m_speed;
	m_y += m_vy * m_speed;

	mx += m_vx * m_speed;
	my += m_vy * m_speed;

	
	Hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);

	CObjBlock* bbh = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	bbh->BlockHit(&m_x, &m_y, &m_up, &m_down, &m_reft, &m_right, &m_vx, &m_vy);

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

	//主人公と接触しているか調べる
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
	//貫通弾と接触しているかを調べる
	if (Hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//弾丸が所有するHitBoxに削除する。
	}
	//範囲外に出ると弾を削除
	if (mx >= 500.0f || mx <= -500.0f || my >= 500.0f || my <= -500.0f)
	{
		this->SetStatus(false);//削除命令
		Hits::DeleteHitBox(this);//削除
	}
}

void CObjBossBullet4::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	//表示位置
	dst.m_top = 0.0f + m_y + m_scroll_map_y;
	dst.m_left = 0.0f + m_x + m_scroll_map_x;
	dst.m_right = 32.0f + m_x + m_scroll_map_x;
	dst.m_bottom = 32.0f + m_y + m_scroll_map_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}