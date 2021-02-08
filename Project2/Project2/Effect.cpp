#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include"GameL/SceneObjManager.h"

#include"Objbreakblock.h"
#include"Effect.h"

using namespace GameL;

Effect::Effect(float x, float y,float r)
{
	m_x = x;
	m_y = y;
	m_r = r;
}

void Effect:: Init()
{
	out = 0;

	Hits::SetHitBox(this, m_x, m_y, 8, 8, ELEMENT_ENEMY, OBJ_EFFECT, 1);
	
}

void Effect::Action()
{
	if (out > 10)
	{
		out = 0;
	}

	if (out == 10)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	out++;
}

void Effect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//Ø‚èæ‚èˆÊ’u‚Ìİ’è
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 300.0f;
	//•`‰æˆÊ’u‚Ìİ’è
	dst.m_top = 0.0f + m_y ;
	dst.m_left = 0.0f + m_x ;
	dst.m_right = 60.0f + m_x ;
	dst.m_bottom = 45.0f + m_y ;
	SetPrio(80);
	//•`‰æ
	Draw::Draw(12, &src, &dst, c, m_r+90);
}