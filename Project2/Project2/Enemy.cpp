#include"GameL\DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL\SceneManager.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"Enemy.h"

using namespace GameL;

CObjEnemy::CObjEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjEnemy::Init()
{
	m_vx = 0.0f;    //移動方向
	m_vy = 0.0f;
	m_r=0.0f;//向きを決める変数
	m_hp=20;//体力
	count = 0;//向きを固定するカウント
	m_time = 0;
	m_move_time = 0;

	//HitBox追加
	Hits::SetHitBox(this, m_x+35, m_y+40, 55, 55, ELEMENT_ENEMY, OBJ_ENEMY,1 );
}

void CObjEnemy::Action()
{

	//if (m_vx <= 20 || m_vx >= -20 || m_vy <= 20 || m_vy >= -20) {
	//	m_time++;
	//	if (m_time > 200)
	//	{
	//		m_time = 0;
	//		//弾丸発射
	//		CObjBulletEnemy* obj_b = new CObjBulletEnemy(m_x, m_y);//弾丸オブジェクト作成
	//		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 1);
	//	}
	//}

	//ある程度近づくと主人公と並行な位置まで移動
	m_vx = 0.0f;
	m_vy = 0.0f;
	float x = 0;
	float y = 0;

	//主人公の座標取得
	CObjHero* hero=(CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
	
	//敵から主人公のベクトルを求める
	x = m_x - hx;
	y = m_y - hy;
	

	//  300=300-0;
	//  500=500-0;

	//問題点

	//座標取得して比較するとき
	//マイナスとプラスの場合などに対応していない


	//(-x,-y)の時
	if (x <= 0.0f && y <= 0.0f)
	{
		if (x < y)
		{
			if (x >= -50.0f&&count==0)
			{
				//x軸がほぼ平行
				m_r = -90.0f;
				m_vx = +0.1f;
				count = 1;
			}
			if (x < -50.0f)
			{
				//x軸の方が近い　
				m_r = 180.0f;
				m_vy = 1.0f;
				count = 0;
			}
		}
		if (x > y)
		{
			if (y >= -50.0f&&count==0)
			{
				//y軸がほぼ垂直
				m_r = 0.0f;
				m_vy = -0.1f;
				count = 1;
			}
			if (y < -50.0f)
			{
				//y軸の方が近い
				m_r = -90.0f;
				m_vx = 1.0f;
				count = 0;
			}
		}
	}
	//(x,y)の時
	if (x >= 0.0f && y >= 0.0f)
	{
		if (x < y)
		{
			if (x <= 50.0f&&count==0)
			{
				//x軸がほぼ平行
				m_r = 90.0f;
				m_vx = -0.1f;
				count = 1;
			}
			if (x > 50.0f)
			{
				//x軸の方が近い
				m_r = 0.0f;
				m_vy = -1.0f;
				count = 0;
			}
		}
		if (x > y)
		{
			if (y <= 20.0f&&count==0)
			{
				//y軸がほぼ垂直
				m_r = 0.0f;
				m_vy = -0.1f;
				count = 1;
			}
			if (y > 20.0f)
			{
				//y軸の方が近い
				m_r = 90.0f;
				m_vx = -1.0f;
				count = 0;
			}
		}
	}
	//(x,-y)の場合
	if (x >= 0.0f && y <= 0.0f)
	{

	}
	if (x <= 0.0f && y >= 0.0f)
	{

	}
	//(-x,y)の場合
	if (x<=0.0f&&y>=0.0f)
	{

	}
	if (x<=0.0f&&y>=0.0f)
	{

	}


	//X軸もY軸も遠い場合
    //X軸の方が近い場合
	//////////if (((x<=-21) > (y<21)) ||((x>=21)<(y>=21))) {
	//////////	count = 0;
	//////////	if (x > 20.0f) {
	//////////		m_r = 90.0f;
	//////////		m_vx = -1.0f;
	//////////	}
	//////////	else if (x < -20.0f) {
	//////////		m_r = 270.0f;
	//////////		m_vx = +1.0f;
	//////////	}
	//////////}

	////////////X軸がほぼ真横の場合
	//////////else if (x <= 20 && x >= -20 && count == 0) {
	//////////	if (y <= -50) {
	//////////		m_r = 180.0f;
	//////////		m_vy = +0.1f;
	//////////		count = 1;
	//////////	}
	//////////	if (y >= 50) {
	//////////		m_r = 0.0f;
	//////////		m_vy = -0.1f;
	//////////		count = 1;

	//////////	}
	//////////}

	////////////Y軸の方が近い場合
	//////////if (((y <= -21) > (x < -21)) || ((y >= 21) < (x >= 21)) || x == y) {
	//////////	if (y > 20.0f) {
	//////////		count = 0;
	//////////		m_r = 0.0f;
	//////////		m_vy = -1.0f;
	//////////	}
	//////////	else if (y < -20.0f) {
	//////////		m_r = 180.0f;
	//////////		m_vy = +1.0f;
	//////////	}
	//////////}

	////////////Y軸がほぼ真横の場合
	//////////else if (y <= 20 && y >= -20 && count == 0) {
	//////////	if (x <= -50) {
	//////////		m_r = -90.0f;
	//////////		m_vx = +0.1f;
	//////////		count = 1;
	//////////	}
	//////////	if (x >= 50) {
	//////////		m_r = 90.0f;
	//////////		m_vx = -0.1f;
	//////////		count = 1;
	//////////	}
	//////////}
	


	m_x += m_vx;
	m_y += m_vy;


	//HitBoxの内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+35, m_y+40);

	////弾丸と接触しているかを調べる
	//if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	//{
	//	this->SetStatus(false);//自身に削除命令を出す
	//	Hits::DeleteHitBox(this);//弾丸が所有するHitBoxに削除する。
	//}
	m_vx = 0;
	m_vy = 0;
}

void CObjEnemy::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 400.0f;

	//出力位置
	dst.m_top = 0.0f+m_y;
	dst.m_left =0.0f+m_x;
	dst.m_right =128.0f+m_x;
	dst.m_bottom =128.0f+m_y;

	Draw::Draw(1, &src, &dst, c, m_r);
}