//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjBox.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBox::CObjBox(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBox::Init()
{

	

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_BOX, 1);
}

//アクション
void CObjBox::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	/*CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hvx = hero->GetVX();*/

	//// 主人公と接触しているかどうか調べる
	//	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	//	{
	//		hvx = hvx - hvx - hvx;
	//		hero->SetVX(hvx);
	//	}

	
	hit->SetPos(m_x+m_scroll_map_x, m_y+m_scroll_map_y);

	//主人公（近接攻撃）と接触したらボックスを削除
	if(hit->CheckObjNameHit(OBJ_ATTACK)!=nullptr)
	{
		//豆箱を削除
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//豆を出現させる
		CObjBean* obj_bean = new CObjBean(m_x+m_scroll_map_x, m_y+m_scroll_map_y);
		Objs::InsertObj(obj_bean, OBJ_BEAN, 9);
	}

	if (m_x >= (80 * 64) || m_y >= (60 * 64))
	{

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//ドロー
void CObjBox::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 240.0f;
	src.m_bottom = 240.0f;
	//描画位置の設定
	dst.m_top = 0.0f + m_y+m_scroll_map_y;
	dst.m_left = 0.0f + m_x+m_scroll_map_x;
	dst.m_right = 64.0f + m_x+m_scroll_map_x;
	dst.m_bottom = 64.0f + m_y+m_scroll_map_y;

	//描画
	Draw::Draw(15, &src, &dst, c, 0.0f);
}
