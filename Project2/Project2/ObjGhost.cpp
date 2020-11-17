//使用ヘッダーふぁいる
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"ObjGhost.h"
#include"OBJGhostAttack.h"

//ネームスペース
using namespace GameL;

CObjGhost::CObjGhost(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjGhost::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;

	//当たり判定
	Hits::SetHitBox(this, m_x, m_y, 30, 30, ELEMENT_ENEMY, OBJ_GHOST, 4);

}

void CObjGhost::Action()
{

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();


	if (m_time == 50) {
		m_time = 0;
	}

	if (n ==50.0f)
	{
		n = 0.0f;
	}

	if (c == 350)
	{
		c = 0;
	}
	c++;

	//内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+m_scroll_map_x, m_y +m_scroll_map_y);


	//ベクトルを求める
	float x = 0;
	float y = 0;

	//主人公の座標取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (hero != nullptr)
	{
		float hx = hero->GetX();
		float hy = hero->GetY();
		float distance = 50.0f;

		//敵から主人公のベクトルを求める
		x = m_x - hx + m_scroll_map_x;
		y = m_y - hy+m_scroll_map_y;

		//ベクトルの長さを求める
		float r = 0.0f;
		r = x * x + y * y;
		r = sqrt(r);

		if (r == 0.0f)//0なら何もしない
			;

		else
		{
			m_vx = -1.0f / r * x;//正規化を行う
			m_vy = -1.0f / r * y;
		}

		//鬼と主人公で角度取り
		CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
		
		//主人公が存在している場合角度計算
		if (obj != nullptr)
		{
			float sx = obj->GetX() - m_x;
			float sy = obj->GetY() - m_y;
			float ar = atan2(-sy, sx) * 180.0f / 3.14f;

			if (ar < 0)
				ar = 360 - abs(ar);

			//現在向いている方向で角度取り
			float br = atan2(-m_vy, m_vx) * 180.0f / 3.14f;

			if (br < 0)
				br = 360 - abs(br);

			//かけ離れたら移動方向を主人公にする
			if (ar - br > 20)
			{
				m_vx = cos(3.14 / 180 * ar);
				m_vy = cos(3.14 / 180 * ar);
			}

			r = 3.14 / 180.0f;//角度1
			if (ar < br)//移動方向に+1
			{
				m_vx = m_vx * cos(r) - m_vy * sin(r);
				m_vy = m_vy * cos(r) - m_vx * sin(r);
			}
			else//移動方向に-1
			{
				m_vx = m_vx * cos(-r) - m_vy * sin(-r);
				m_vy = m_vy * cos(-r) - m_vy * sin(-r);
			}
			
		}


		m_vx *= 1.5f;
		m_vy *= 1.5f;

		if ((x >= -400.0f && x <= 400.0f) || (y >= -400.0f && y <= 400.0f))
		{
			//より近づいてきたら逃げる

			if ((x >= -(25.0f + distance) && x <= 75.0f + distance) && (y >= -(25.0f + distance) && y <= 75.0f + distance)||m_time!=0)
			{
				//ベクトルを真逆にする
				m_vx = m_vx - m_vx - m_vx;
				m_vy = m_vy - m_vy - m_vy;
				if (m_time < 50) {
					m_x += m_vx;
					m_y += m_vy;
					m_time++;
				}
				
			}
			//主人公に接近したら静止
			else if ((x >= -(30.0f + distance) && x <= 80.0f + distance) && (y >= -(30.0f + distance) && y <= 80.0f + distance)||n!=0)
			{
				n+=1.0f;
				if (c == 50)
				{
					CObjGhostAttack* objAttack = new CObjGhostAttack(m_x, m_y);
					Objs::InsertObj(objAttack, OBJ_GHOST_ATTACK, 6);
				}
				if (weit == false) {
					weit = true;
					waittimer = 0;
				}
				
			}
			if (m_time == 0) 
			{
				if (n == 0.0f)
				{
					m_x += m_vx;
					m_y += m_vy;
				}
			}
			if (weit == true) {
				if (waittimer < 150) {
					m_vx = 0.0f;
					m_vy = 0.0f;
					waittimer++;
				}
				weit == false;

			}
		}
	}
		//移動方向初期化
		m_vx = 0.0f;
		m_vy = 0.0f;

	//主人公弾と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

void CObjGhost::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	//表示位置の設定
	dst.m_top = 0.0f +m_y+m_scroll_map_y-5.0f;
	dst.m_left = 0.0f + m_x + m_scroll_map_x-5.0f;
	dst.m_right = 45.0f + m_x + m_scroll_map_x-5.0f;
	dst.m_bottom = 45.0f+m_y+m_scroll_map_y-5.0f;

	//描画
	Draw::Draw(4, &src, &dst, c,0.0f);
}