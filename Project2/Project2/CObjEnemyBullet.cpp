#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameHead.h"
#include"CObjEnemyBullet.h"

using namespace GameL;

CObjEnemyBullet::CObjEnemyBullet(float x, float y,float r)
{
	m_x = x+10;
	m_y = y+10;
	m_r = r;
}

//イニシャライズ
void CObjEnemyBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	mx = 0;
	my = 0;

	//HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//アクション
void CObjEnemyBullet::Action()
{

	//スクロールした分のベクトルを取得
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	CObjEnemy* Ebs = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	float Bx = Ebs->GetX();
	float By = Ebs->GetY();



	if (m_r == 0.0f)
	{
		m_vy = -1.5f;
		m_vx = 0.0f;
	}
	else if (m_r == 90.0f)
	{
		m_vx = -1.5f;
		m_vy = 0.0f;
	}
	else if (m_r == 180.0f)
	{
		m_vy = +1.5f;
		m_vx = 0.0f;
	}
	else if (m_r == -90.0f)
	{
		m_vx = +1.5f;
		m_vy = 0.0f;
	}

	
	m_x += m_vx;
	m_y += m_vy;

	mx += m_vx;
	my += m_vy;

	Bx += mx;
	By += my;

	
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


	//主人公と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//削除命令
		Hits::DeleteHitBox(this);//削除
	}
	//主人公（人）と接触しているか調べる
	if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
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

	if (mx >= 500.0f||mx<=-500.0f || my >= 500.0f||my<=-500.0f)
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
	dst.m_top = 0.0f+m_y+m_scroll_map_y;
	dst.m_left = 0.0f +m_x+m_scroll_map_x ;
	dst.m_right = 32.0f+m_x +m_scroll_map_x;
    dst.m_bottom = 32.0f+m_y+m_scroll_map_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}