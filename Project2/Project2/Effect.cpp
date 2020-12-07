#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include"GameL/SceneObjManager.h"

#include"Objbreakblock.h"
#include"Effect.h"

using namespace GameL;

Effect::Effect(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Effect:: Init()
{

}

void Effect::Action()
{
	/*out++;

	if (out == 10)
	{
		this->SetStatus(false);
	}
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();*/

	
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
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 80.0f ;
	dst.m_bottom = 60.0f ;

	//•`‰æ
	Draw::Draw(20, &src, &dst, c, 0.0f);
}