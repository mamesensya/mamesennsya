//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "Objbreakblock.h"
#include"ObjUserInterface.h"
#include"ObjHero.h"



//使用するネームスペース
using namespace GameL;




//コンストラクタ
CObjbreakblock::CObjbreakblock(float x, float y )
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjbreakblock::Init()
{
	
}

//アクション
void CObjbreakblock::Action()
{

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	CObjUserInterface* count = (CObjUserInterface*)Objs::GetObj(OBJ_USERINTERFACE);
	int Enemycount = count->GetEM();
	

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();
	

	CHitBox* hit = Hits::GetHitBox(this);



		//敵を全員倒したらしたら壁を削除
		if (Enemycount==0)
		{
			//壁を削除
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			
		}

		if (m_x >= (80 * 64) || m_y >= (60 * 64))
		{

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	
}

//ドロー
void CObjbreakblock::Draw()
{
	float c[4] = { 1.0f,4.0f,2.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;
	//描画位置の設定
	dst.m_top = 0.0f + m_y + m_scroll_map_y;
	dst.m_left = 0.0f + m_x + m_scroll_map_x;
	dst.m_right = 64.0f + m_x + m_scroll_map_x;
	dst.m_bottom = 64.0f + m_y + m_scroll_map_y;

	//描画
	Draw::Draw(17, &src, &dst, c, 0.0f);
}





