#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include"Objblock.h"
#include"Effect.h"
#include "CObjPlayerBullet.h"

using namespace GameL;

Effect::Effect(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Init()
{

}

void Action()
{
	/*CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();*/
}

void Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 300.0f;
	//描画位置の設定
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 80.0f ;
	dst.m_bottom = 60.0f ;

	//描画
	Draw::Draw(19, &src, &dst, c, 0.0f);
}