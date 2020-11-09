//使用ヘッダーふぁいる
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"ObjGhost.h"
#include"OBJGhostAttack.h"
#include"ObjHero.h"

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
	Hits::SetHitBox(this, m_x+5, m_y+5, 30, 30, ELEMENT_ENEMY, OBJ_GHOST, 4);

}

void CObjGhost::Action()
{
	if (m_time == 130) {
		m_time = 0;
	}

	//内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + 5, m_y + 5);


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

		x = m_x - hx;
		y = m_y - hy;

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
		m_vx *= 5.0f;
		m_vy *= 5.0f;

		if ((x >= -400.0f && x <= 400.0f) || (y >= -400.0f && y <= 400.0f))
		{
			if ((x >= -(25.0f + distance) && x <= 75.0f + distance) && (y >= -(25.0f + distance) && y <= 75.0f + distance)||m_time!=0)
			{
				//ベクトルを真逆にする
				m_vx = m_vx - m_vx - m_vx;
				m_vy = m_vy - m_vy - m_vy;
				if (m_time < 130) {
					m_x += m_vx;
					m_y += m_vy;
					m_time++;
				}
				
			}
			//主人公に接近したら静止(近接格闘は後に実装)
			else if ((x >= -(30.0f + distance) && x <= 80.0f + distance) && (y >= -(30.0f + distance) && y <= 80.0f + distance))
			{
				m_vx = 0.0f;
				m_vy = 0.0f;
				for (;;n++)
				{
					if (n == 30)
					{
						CObjGhostAttack* objAttack = new CObjGhostAttack(m_x, m_y);
						Objs::InsertObj(objAttack, OBJ_GHOST_ATTACK, 6);
						
						
						n = 0;
						break;
					}
					
				}

			}
			if (m_time == 0) {
				m_x += m_vx;
				m_y += m_vy;
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
	dst.m_top = 0.0f +m_y;
	dst.m_left = 0.0f +m_x;
	dst.m_right = 45.0f+m_x;
	dst.m_bottom = 45.0f+m_y;

	//描画
	Draw::Draw(4, &src, &dst, c,0.0f);
}