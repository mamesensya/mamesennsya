#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameHead.h"
#include"CObjEnemyBullet.h"

using namespace GameL;

CObjEnemyBullet::CObjEnemyBullet(float x, float y,float r)
{
	m_x = x+45;
	m_y = y+50;
	m_r = r;
}

//イニシャライズ
void CObjEnemyBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//アクション
void CObjEnemyBullet::Action()
{
	//float mr = 0.0f;
	////敵戦車のグラフィックの向きを取得
	//CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	//mr = enemy->GetR();


	if (m_r == 0.0f)
	{
		m_vy = -5.0f;
		m_vx = 0.0f;
	}
	else if (m_r == 90.0f)
	{
		m_vx = -5.0f;
		m_vy = 0.0f;
	}
	else if (m_r == 180.0f)
	{
		m_vy = +5.0f;
		m_vx = 0.0f;
	}
	else if (m_r == -90.0f)
	{
		m_vx = +5.0f;
		m_vy = 0.0f;
	}


	m_x += m_vx;
	m_y += m_vy;


	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//削除命令
		Hits::DeleteHitBox(this);//削除
	}

	////弾丸と接触しているかを調べる
	//if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	//{
	//	this->SetStatus(false);//自身に削除命令を出す
	//	Hits::DeleteHitBox(this);//弾丸が所有するHitBoxに削除する。
	//}

	if (m_x >= 1000.0f||m_x<=-1000.0f || m_y >= 1000.0f||m_y>=1000.0f)
	{
		this->SetStatus(false);//削除命令
		Hits::DeleteHitBox(this);//削除
	}

}

//ドロー
void CObjEnemyBullet::Draw()
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
	dst.m_top = 0.0f+m_y;
	dst.m_left = 0.0f+m_x;
	dst.m_right = 32.0f+m_x;
    dst.m_bottom = 32.0f+m_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}