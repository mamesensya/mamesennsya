//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjBean.h"
#include "ObjBox.h"

//使用するネームスペース
using namespace GameL;

CObjBean::CObjBean(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBean::Init()
{
	//ボックスの当たり判定
	//主人公の位置取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	CObjBox* box = (CObjBox*)Objs::GetObj(OBJ_BOX);
	m_x = box->GetX();
	m_y = box->GetY();


	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_BOX, 1);
}

//アクション
void CObjBean::Action()
{		
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公（近接攻撃）と接触したらボックスを削除
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		//主人公の持っている弾の数を増加させる
		hero->GetBullet(3);
		hero->GetUniqueBullet1(3);
		hero->GetUniqueBullet2(3);
	}
}

//ドロー
void CObjBean::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 768.0f;
	src.m_bottom = 768.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 32.0f;
	dst.m_bottom = 32.0f;

	Draw::Draw(14, &src, &dst, c, 0);
}