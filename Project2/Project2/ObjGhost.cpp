//使用ヘッダーふぁいる
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"ObjGhost.h"

//ネームスペース
using namespace GameL;

//CObjGhost::CObjGhost(float x, float y)
//{
//	m_x = x;
//	m_y = y;
//}

void CObjGhost::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_GHOST, 4);

}

void CObjGhost::Action()
{
	//移動方向
	m_vx = -1.0f;
	m_vy = 0.0f;

	//ベクトルの長さを求める
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);

	if (r == 0.0f)//0なら何もしない
		;

	else 
	{
		m_vx = 1.0f / r * m_vx;//正規化を行う
		m_vy = 1.0f / r * m_vy;
	}

	//速度
	m_vx *= 1.0f;
	m_vy *= 1.0f;

	//ベクトルを座標加算
	m_x += m_vx;
	m_y += m_vy;

	//内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
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
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 45.0f;
	dst.m_bottom = 45.0f;

	//描画
	Draw::Draw(4, &src, &dst, c,0.0f);
}