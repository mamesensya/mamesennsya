#include "GameL\HitBoxManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "CObjAttack.h"

using namespace GameL;

//コンストラクタ
CObjAttack::CObjAttack(float x,float y,float r)
{
	m_x = x;
	m_y = y;
	m_r = r;
}

//イニシャライズ
void CObjAttack::Init()
{

	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_CHARA, OBJ_ATTACK, 1);
}

//アクション
void CObjAttack::Action()
{
	CHitBox* Hit = Hits::GetHitBox(this);

	//主人公が向いている向きによって攻撃の向きを変える
	if (m_r == 0.0f)
	{
		//HitBoxの位置更新
		Hit->SetPos(m_x, m_y - 25.0f);
	}
	else if (m_r == 90.0f)
	{
		//HitBoxの位置更新
		Hit->SetPos(m_x - 25.0f, m_y);
	}
	else if (m_r == 180.0f)
	{
		//HitBoxの位置更新
		Hit->SetPos(m_x, m_y + 25.0f);
	}
	else if (m_r == 270.0f)
	{
		//HitBoxの位置更新
		Hit->SetPos(m_x + 25.0f, m_y);
	}
	//主人公の攻撃間隔制御
	m_time++;
	if (m_time == 10)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		m_time = 0;
	}
}

//ドロー
void CObjAttack::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;
	
	//向いている角度によって表示の位置をずらす
	if (m_r == 0.0f)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_y - 25.0f;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 32.0f + 16.0f + m_x;
		dst.m_bottom = 32.0f + 16.0f + m_y - 25.0f;
	}
	else if (m_r == 90.0f)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x-25.0f;
		dst.m_right = 32.0f + 16.0f + m_x-25.0f;
		dst.m_bottom = 32.0f + 16.0f + m_y;
	}
	else if (m_r == 180.0f)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_y+25.0f;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 32.0f + 16.0f + m_x;
		dst.m_bottom = 32.0f + 16.0f + m_y+25.0f;
	}
	else if (m_r == 270.0f)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x+25.0f;
		dst.m_right = 32.0f + 16.0f + m_x+25.0f;
		dst.m_bottom = 32.0f + 16.0f + m_y;
	}
	////表示位置の設定
	//dst.m_top = 0.0f + m_y;
	//dst.m_left = 0.0f + m_x;
	//dst.m_right = 32.0f + 16.0f + m_x;
	//dst.m_bottom = 32.0f + 16.0f + m_y;

	//描画
	Draw::Draw(8, &src, &dst, c, m_r);


}