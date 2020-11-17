#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameHead.h"
#include"CObjBossBullet.h"

using namespace GameL;

CObjBossBullet::CObjBossBullet(float x, float y,float r)
{
	m_x = x + 85;
	m_y = y + 85;
	m_r = r;
}

//イニシャライズ
void CObjBossBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;


	//HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//アクション
void CObjBossBullet::Action()
{

	CHitBox* Hit = Hits::GetHitBox(this);


	m_vx = cos(3.14 / 180.0f * m_r);
	m_vy = sin(3.14 / 180.0f * m_r);



	m_x += m_vx * m_speed;
	m_y += m_vy * m_speed;

	mx += m_vx * m_speed;
	my += m_vy * m_speed;


	Hit->SetPos(m_x, m_y);

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


	if (mx >= 1000.0f || mx <= -1000.0f || my >= 1000.0f || my <= -1000.0f)
	{
		this->SetStatus(false);//削除命令
		Hits::DeleteHitBox(this);//削除
	}

	
	////if (m_r == 0.0f)
	////{
	////	m_vy = -5.0f;
	////	m_vx = 0.0f;
	////}
	////else if (m_r == 90.0f)
	////{
	////	m_vx = -5.0f;
	////	m_vy = 0.0f;
	////}
	////else if (m_r == 180.0f)
	////{
	////	m_vy = +5.0f;
	////	m_vx = 0.0f;
	////}
	////else if (m_r == -90.0f)
	////{
	////	m_vx = +5.0f;
	////	m_vy = 0.0f;
	////}


	////m_x += m_vx;
	////m_y += m_vy;


	//////HitBoxの内容を更新
	////CHitBox* hit = Hits::GetHitBox(this);
	////hit->SetPos(m_x + m_scroll_map_x, m_y+m_scroll_map_y);

	//////主人公と接触しているかどうか調べる
	////if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	////{
	////	this->SetStatus(false);//削除命令
	////	Hits::DeleteHitBox(this);//削除
	////}
	//////主人公（人）と接触しているか調べる
	////if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	////{
	////	this->SetStatus(false);//削除命令
	////	Hits::DeleteHitBox(this);//削除
	////}
	////////弾丸と接触しているかを調べる
	//////if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	//////{
	//////	this->SetStatus(false);//自身に削除命令を出す
	//////	Hits::DeleteHitBox(this);//弾丸が所有するHitBoxに削除する。
	//////}

	//////if (mx >= 1000.0f || mx <= -1000.0f || my >= 1000.0f || my <= -1000.0f)
	//////{
	//////	this->SetStatus(false);//削除命令
	//////	Hits::DeleteHitBox(this);//削除
	//////}

}

//ドロー
void CObjBossBullet::Draw()
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
	dst.m_top = 0.0f + m_y+m_scroll_map_y;
	dst.m_left = 0.0f + m_x + m_scroll_map_x;
	dst.m_right = 32.0f + m_x + m_scroll_map_x;
	dst.m_bottom = 32.0f + m_y+m_scroll_map_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}