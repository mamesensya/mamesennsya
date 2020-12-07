//使用ヘッダーふぁいる
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"ObjGhost.h"
#include"OBJGhostAttack.h"
#include"Objbreakblock.h"

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
	m_r = 0.0f;



	//当たり判定
	Hits::SetHitBox(this, m_x, m_y, 30, 30, ELEMENT_ENEMY, OBJ_GHOST, 4);

}

/// <summary>
/// 鬼が重ならないようにしたい
/// その場合
/// 当たり判定を持ってきて
/// </summary>

void CObjGhost::Action()
{

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();


	if (m_time == 50) {
		m_time = 0;
	}

	if (n == 200.0f)
	{
		n = 0.0f;
	}

	if (c == 350)
	{
		c = 0;
	}



	m_x += m_scroll_map_x;
	m_y += m_scroll_map_y;


	//ブロックとの当たり判定
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_x, &m_y, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy);

	m_x -= m_scroll_map_x;
	m_y -= m_scroll_map_y;



	//内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);


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
		y = m_y - hy + m_scroll_map_y;


		


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
		m_r = atan2(x, y) * 180.0f / 3.14f;

		if (m_r < 0)
			m_r = 360 - abs(m_r);


		m_vx *= 1.5f;
		m_vy *= 1.5f;

		

		if ((x >= -400.0f && x <= 400.0f) || (y >= -400.0f && y <= 400.0f))
		{

			float sw = 0.0;

			if (hit->CheckObjNameHit(OBJ_GHOST) != nullptr)
			{

				sw = m_vx;
				m_vx = m_vy;
				sw = m_vy;

			}
			//より近づいてきたら逃げる

			else if ((x >= -35.0f) && x <= 70.0f  && (y >= -35.0f) && y <= 70.0f || m_time != 0)
			{
				//ベクトルを真逆にする
				m_vx = m_vx - m_vx - m_vx;
				m_vy = m_vy - m_vy - m_vy;
				m_r = m_r - m_r - m_r;
				if (m_time < 50) {
					m_x += m_vx;
					m_y += m_vy;
					m_time++;
				}
				

			}
			//主人公に接近したら静止
			else if ((x >= -50.0f  && x <= 90.0) && (y >= -50.0f) && y <= 90.0f  || n != 0)
			{

				n += 1.0f;
				if (n == 100.0)
				{
					if (m_time == 0) {
						//攻撃命令
						CObjGhostAttack* objAttack = new CObjGhostAttack(m_x + m_scroll_map_x, m_y + m_scroll_map_y, m_r);
						Objs::InsertObj(objAttack, OBJ_GHOST_ATTACK, 6);

					}
				}
			}
			
			if (m_time == 0||sw!=0.0)
			{
				if (n == 0.0f||sw!=0.0)
				{
					m_x += m_vx;
					m_y += m_vy;
				}
			}

		}
	}
	//移動方向初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//主人公弾と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		Effect* effect = new Effect(m_x, m_y);
		Objs::InsertObj(effect, OBJ_EFFECT, 20);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjbreakblock* Bblock = (CObjbreakblock*)Objs::GetObj(OBJ_BREAK_BLOCK);
		Bblock->Enemycount--;
		CObjBoss* Boss = (CObjBoss*)Objs::GetObj(OBJ_BOSS);
		Boss->m_oni_count--;
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
	dst.m_top = 0.0f + m_y + m_scroll_map_y - 5.0f;
	dst.m_left = 0.0f + m_x + m_scroll_map_x - 5.0f;
	dst.m_right = 45.0f + m_x + m_scroll_map_x - 5.0f;
	dst.m_bottom = 45.0f + m_y + m_scroll_map_y - 5.0f;

	//描画
	Draw::Draw(4, &src, &dst, c, m_r);
}