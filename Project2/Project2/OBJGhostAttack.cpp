//使用ヘッダーふぁいる
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"OBJGhostAttack.h"


CObjGhostAttack::CObjGhostAttack(float x, float y,float r)
{
	
	m_x = x;
	m_y = y;
	m_r = r;
	
	
}

void CObjGhostAttack::Init()
{

	Hits::SetHitBox(this, m_x, m_y , 25, 25, ELEMENT_ENEMY, OBJ_GHOST_ATTACK, 6);
}

void CObjGhostAttack::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();



	if ((m_r < 45 && m_r>0) || m_r > 315)
	{
		m_x = m_x + 30;
	}
	if (m_r > 45 && m_r < 135)
	{
		m_y = m_y - 30;
	}
	if (m_r > 135 && m_r < 225)
	{
		m_x = m_x - 30;
	}
	if (m_r > 225 && m_r < 315)
	{
		m_y = m_y + 30;
	}


	m_time ++ ;
	if (m_time == 20)
	{
		//内容更新
		
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);//主人公に当たったら破棄
			Hits::DeleteHitBox(this);
		}

		this->SetStatus(false);//一定時間経過したらいったん破棄
		Hits::DeleteHitBox(this);
		m_time = 0;
		
	}
	
	hit->SetPos(m_x + m_scroll_map_x, m_y +m_scroll_map_y);

	if ((m_r < 45 && m_r>0) || m_r > 315)
	{
		m_x = m_x - 30;
	}
	if (m_r > 45 && m_r < 135)
	{
		m_y = m_y + 30;
	}
	if (m_r > 135 && m_r < 225)
	{
		m_x = m_x + 30;
	}
	if (m_r > 225 && m_r < 315)
	{
		m_y = m_y - 30;
	}
}

void CObjGhostAttack::Draw()
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
	dst.m_top = 35.0f + m_y+m_scroll_map_y-30;
	dst.m_left = 0.0f + m_x+m_scroll_map_x;
	dst.m_right = 30.0f + m_x+m_scroll_map_x;
	dst.m_bottom = 30.0f + m_y+30+m_scroll_map_y-30;

	//描画
	Draw::Draw(6, &src, &dst, c, m_r);
}