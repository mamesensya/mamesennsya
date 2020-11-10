//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjBox.h"

//マップのX軸数
#define MAP_X (100)
//マップのY軸数
#define MAP_Y (10)

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

	//ボックスの当たり判定
	//主人公の位置取得
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float hx = hero->GetX();
	//float hy = hero->GetY();
	////マップの要素にアクセス
	//for (int i = 0; i < MAP_Y; i++)
	//{
	//	for (int j = 0; j < MAP_X; j++)
	//	{
	//		//要素番号を座標に変更
	//		float x = j * 64.0f;
	//		float y = i * 64.0f;

	//		//主人公とボックスの当たり判定
	//		if ((hx+64.0f>x)&&(hx<x+64.0f)&&(hy+64.0f>y)&&(hy<y+64.0f))
	//		{
	//			//当たっている場合
	//			hero->SetX(hx);
	//			hero->SetY(0.0f);
	//		}
	//	}
	//}

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x+16, m_y+16, 64, 64, ELEMENT_ITEM, OBJ_BOX, 1);
}

//アクション
void CObjBox::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公（近接攻撃）と接触したらボックスを削除
	if(hit->CheckObjNameHit(OBJ_ATTACK)!=nullptr)
	{
		//豆箱を削除
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//豆を出現させる
		CObjBean* obj_bean = new CObjBean(m_x, m_y);
		Objs::InsertObj(obj_bean, OBJ_BEAN, 9);
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
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	//描画
	Draw::Draw(15, &src, &dst, c, 0.0f);
}
