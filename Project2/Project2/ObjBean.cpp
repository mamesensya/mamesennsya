//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjBean.h"
#include "time.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
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
	if (hero != nullptr)
	{
		float hx = hero->GetX();
		float hy = hero->GetY();
	}
	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_BEAN, 1);
}

//アクション
void CObjBean::Action()
{
	//弾の取得数をランダムで指定
	srand(time(NULL));
	int r = (rand() % (7 - 4 + 1)) + 4;

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//主人公と接触したら豆を取得
	if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//発射音鳴らす
		Audio::Start(11);

		//豆を削除
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		//主人公の持っている弾の数を増加させる
		hero->GetBullet(r);
		hero->GetUniqueBullet1(2);
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

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(14, &src, &dst, c, 0);
}