#include"GameL\DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL\SceneManager.h"
#include"GameL/WinInputs.h"
#include "GameL\Audio.h"

#include"GameHead.h"
#include"CObjBoss.h"
#include"CObjAngleBullet.h"
#include "Objbreakblock.h"
#include"CObjBossBullet2.h"

using namespace GameL;

CObjBoss::CObjBoss(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBoss::Init()
{
	m_vx = 0.0f;    //移動方向
	m_vy = 0.0f;
	m_r = 0.0f;//向きを決める変数
	m_hp = 5;//体力
	count = 0;//向きを固定するカウント
	m_time = 0;//弾丸発射制御用time
	m_time2 = 0;
	m_move_time = 0;//移動硬直用time

	pbullet_interval = 0; //貫通弾ヒットの間隔
	pbullet_enable = false; //貫通弾ダメージ有効

	//HitBox追加
	Hits::SetHitBox(this, m_x , m_y , 120, 120, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

void CObjBoss::Action()
{
	if (m_x >= (80 * 64) || m_y >= (60 * 64))
	{

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	m_time2++;
	m_time++;
	m_oni_time++;
	if (m_time2 > 400)
	{
		m_time2 = 0;
	}
	if (m_time > 300)
	{
		m_time = 0;

	}
	if (m_oni_time > 100)
	{
		m_oni_time = 0;
	}

	//ある程度近づくと主人公と並行な位置まで移動

	float x = 0;//主人公から敵のベクトルx
	float y = 0;//主人公から敵のベクトルy

	//主人公の座標取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (hero != nullptr)
	{
		float hx = hero->GetX();
		float hy = hero->GetY();


		//スクロールをした分ずれているから本当の座標を出す
		hx = hx - m_scroll_map_x;
		hy = hy - m_scroll_map_y;

		//敵の座標はもともとスクロールの値が入っていない
		//敵から主人公のベクトルを求める　
		x = m_x - hx;
		y = m_y - hy;

		

		if ((x >= -600.0f && x <= 600.0f) || (y >= -600.0f && y <= 600.0f))
		{
			//主人公の方に向くプログラムは調整済み----------------------------
			//敵の位置が(-x,-y)の時
			if (x <= 0.0f && y <= 0.0f)
			{
				if (x > y)
				{
					if (x >= -60.0f && count == 0)
					{
						//x軸がほぼ垂直
						m_r = 180.0f;
						m_vy = +0.1;
						count = 1;
					}
					if (x < -60.0f && m_move_time == 0)
					{
						//x軸の方が近い　
						m_r = -90.0f;
						m_vx = 0.7f;
					}
				}
				if (x < y)
				{
					if (y >= -60.0f && count == 0)
					{
						//y軸がほぼ平行
						m_r = -90.0f;
						m_vx = 0.1f;
						count = 1;
					}
					if (y < -60.0f && m_move_time == 0)
					{
						//y軸の方が近い
						m_r = 180.0f;
						m_vy = 0.7f;
					}
				}
			}
			//(x,y)の時
			if (x >= 0.0f && y >= 0.0f)
			{
				if (x < y)
				{
					if (x <= 0.0f && count == 0)
					{
						//x軸がほぼ垂直
						m_r = 0.0f;
						m_vy = -0.1f;
						count = 1;
					}
					if (x > 0.0f && m_move_time == 0)
					{
						//x軸の方が近い
						m_r = 90.0f;
						m_vx = -0.7f;
					}
				}
				if (x > y)
				{
					if (y <= 0.0f && count == 0)
					{
						//y軸がほぼ平行
						m_r = 90.0f;
						m_vx = -0.1f;
						count = 1;
					}
					if (y > 0.0f && m_move_time == 0)
					{
						//y軸の方が近い
						m_r = 0.0f;
						m_vy = -0.7f;
					}
				}
			}

			//(x,-y)の場合
			if (x >= 0.0f && y <= 0.0f)
			{
				float py = y - y - y;
				if (x < py)
				{
					if (x <= 0.0f && count == 0)
					{
						//x軸がほぼ垂直
						m_r = 180.0f;
						m_vy = -0.1f;
						count = 1;
					}
					if (x > 0.0f && m_move_time == 0)
					{
						//x軸の方が近い
						m_r = 90.0f;
						m_vx = -0.7f;
					}
				}
				if (x > py)
				{
					if (y >= -60.0f && count == 0)
					{
						//y軸がほぼ平行
						m_r = 90.0f;
						m_vx = -0.1f;
						count = 1;
					}
					if (y < -60.0f && m_move_time == 0)
					{
						//y軸の方が近い
						m_r = 180.0f;
						m_vy = 0.7f;
					}
				}
			}
			//(-x,y)の場合
			if (x <= 0.0f && y >= 0.0f)
			{
				float px = x - x - x;
				if (px < y)
				{
					if (x >= -60.0f && count == 0)
					{
						//x軸がほぼ垂直
						m_r = 0.0f;
						m_vy = -0.1;
						count = 1;
					}
					if (x < -60.0f && m_move_time == 0)
					{
						//x軸の方が近い　
						m_r = -90.0f;
						m_vx = 0.7f;
					}
				}
				if (px > y)
				{
					if (y <= -60.0f && count == 0)
					{
						//y軸がほぼ平行
						m_r = -90.0f;
						m_vx = 0.1f;
						count = 1;
					}
					if (y > -60.0f && m_move_time == 0)
					{
						//y軸の方が近い
						m_r = 0.0f;
						m_vy = -0.7f;
					}
				}
			}
			//---------------------

			if (m_time == 300 && count == 1)
			{
				//発射音鳴らす
				Audio::Start(10);
				
				//敵弾丸発射　　
				CObjBossBullet* obj_bb = new CObjBossBullet(m_x, m_y, m_r );
				Objs::InsertObj(obj_bb, OBJ_BOSS_BULLET, 16);
				
				if (m_Bcount == 0)
				{
					m_Bcount = 1;
				}
				else if (m_Bcount == 1)
				{
					m_Bcount = 0;
				}
				

			}
		//bool reflect = true;
		//if (m_time == 10)
		//{
		//	if (m_r >= 0.0 && reflect == true)
		//	{
		//		//角度m_angleで角度弾丸発射
		//		m_r += 5.0;
		//		CObjAngleBullet* obj_a = new CObjAngleBullet(300, 300, m_r);
		//		Objs::InsertObj(obj_a, OBJ_ENEMY_BULLET, 1);
		//		if (m_r >= 360.0)
		//		{
		//			reflect = false;
		//		}
		//	}
		//	else if (m_r <= 360 && reflect == false)
		//	{
		//		//角度m_angleで角度弾丸発射
		//		m_r -= 5.0;
		//		if (m_r <= 0)
		//		{
		//			reflect = true;
		//		}
		//	}
		//	m_time = 0;
		//}
		//m_time++;

			//鬼召喚
			if (m_oni_time == 50&&m_oni_count<=3)
			{
				if (m_r == 0)
				{
					m_oni_count++;
					CObjGhost* obj_g = new CObjGhost(m_x + m_scroll_map_x, (m_y+172) + m_scroll_map_y);
					Objs::InsertObj(obj_g, OBJ_GHOST, 16);
					
				}
				if (m_r == 90)
				{
					m_oni_count++;
					CObjGhost* obj_g = new CObjGhost((m_x+172) + m_scroll_map_x, m_y + m_scroll_map_y);
					Objs::InsertObj(obj_g, OBJ_GHOST, 16);
					
				}
				if (m_r == 180)
				{
					m_oni_count++;
					CObjGhost* obj_g = new CObjGhost(m_x + m_scroll_map_x, (m_y-172) + m_scroll_map_y);
					Objs::InsertObj(obj_g, OBJ_GHOST, 16);
					
				}
				if (m_r == -90)
				{
					m_oni_count++;
					CObjGhost* obj_g = new CObjGhost((m_x-172) + m_scroll_map_x, m_y + m_scroll_map_y);
					Objs::InsertObj(obj_g, OBJ_GHOST, 16);
					
				}
				
			}


			if (m_time2==400)
			{
				//発射音鳴らす
				Audio::Start(10);

				CObjBossBullet2* obj_eb = new CObjBossBullet2(m_x-80 , m_y-80 , -m_r - 90);
				Objs::InsertObj(obj_eb, OBJ_BOSS_BULLET2, 50);
			}


		
		}
	}

	m_x += m_scroll_map_x;
	m_y += m_scroll_map_y;


	//ブロックとの当たり判定
	CObjBlock* eb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	eb->BlockHit(&m_x, &m_y, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy);

	m_x -= m_scroll_map_x;
	m_y -= m_scroll_map_y;


	m_x += m_vx;
	m_y += m_vy;


	//HitBoxの内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+ m_scroll_map_x, m_y+m_scroll_map_y);
	CSceneMain* main = new CSceneMain();
	
	//弾丸と接触しているかを調べる
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		//弾着弾音
		Audio::Start(13);
		m_hp--;
		if (m_hp <= 0) {
			//爆発音鳴らす
			Audio::Start(12);

			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//弾丸が所有するHitBoxに削除する。
			
			main->RoundChange();
		}
	}
	else if (pbullet_enable == false) {
		if (hit->CheckObjNameHit(OBJ_PENETRATE_BULLET) != nullptr) {
			//弾着弾音
			Audio::Start(13);

			m_hp--;
			pbullet_enable = true;

			if (m_hp <= 0) {
				//爆発音鳴らす
				Audio::Start(12);
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				main->RoundChange();
			}
		}
	}
	else if (pbullet_enable == true) {
		pbullet_interval++;
		if (pbullet_interval > 7) {
			pbullet_interval = 0;
			pbullet_enable = false;
		}
	}
	m_vx = 0;
	m_vy = 0;

	//移動硬直制御
	if (count == 1)
	{
		m_move_time++;
		if (m_move_time == 100)
		{
			m_move_time = 0;
			count = 0;
		}
	}

	
}

void CObjBoss::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 300.0f;

	//出力位置調整用条件
	if (m_r==0)
	{

		//出力位置
		dst.m_top = -20.0f + m_y + m_scroll_map_y - 40.0f;
		dst.m_left = -50.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_right = 250.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_bottom = 280.0f + m_y + m_scroll_map_y - 34.0f;
	}
	if (m_r==90)
	{

		//出力位置
		dst.m_top = -60.0f + m_y + m_scroll_map_y - 40.0f;
		dst.m_left = -20.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_right = 280.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_bottom = 240.0f + m_y + m_scroll_map_y - 34.0f;
	}
	if (m_r==180)
	{

		//出力位置
		dst.m_top = -100.0f + m_y + m_scroll_map_y - 40.0f;
		dst.m_left = -60.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_right = 240.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_bottom = 200.0f + m_y + m_scroll_map_y - 34.0f;
	}
	if (m_r==-90)
	{

		//出力位置
		dst.m_top = -50.0f + m_y + m_scroll_map_y - 40.0f;
		dst.m_left = -100.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_right = 200.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_bottom = 250.0f + m_y + m_scroll_map_y - 34.0f;
	}
	Draw::Draw(5, &src, &dst, c, m_r);
}