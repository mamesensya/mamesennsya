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
	
	
	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_BREAK_BLOCK,  1);
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


	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);

	

		//敵を全員倒したらしたら壁を削除
		if (Enemycount==0)
		{
			//壁を削除
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
//BlockHit関数
//引数1 float* x        :判定を行うobjectのX位置
//引数2 float* y        :判定を行うobjectのY位置
//引数3 bool* up        :上下左右判定の上部分に当たっているかどうかを返す
//引数4 bool* down      :下部分に当たっているかを返す
//引数5 bool* left      :左部分に当たっているかを返す
//引数6 bool* right     :右部分に当たっているかを返す
//引数7 float* vx       :左右判定時の反発による移動方向・力の値を変えて返す
//引数8 float* vy       :上下判定時による移動方向・力の値を変えて返す
void CObjbreakblock::BBlockHit(
	float* x, float* y, bool* up, bool* down,
	bool* left, bool* right, float* vx, float* vy
)
{
	

	*up = false;
	*down = false;
	*left = false;
	*right = false;


	//上下左右の判定

	//vectorのさくせい
	float rvx = (*x + (-m_scroll_map_x) -m_x) ;
	float rvy = (*y + (-m_scroll_map_y)-m_y) ;

	//長さを求める
	float len = sqrt(rvx * rvx + rvy * rvy);

	float r = atan2(rvy, rvx);
	r = r * 180.0f / 3.14f;


	if (r < 0.0f)
		r = abs(r);
	else
		r = 360.0f - abs(r);

	if (len < 88.0f)
	{


		//角度で上下左右を判定
		if ((r < 45 && r>0) || r > 315)
		{
			//右
			*right = true;
			*x = m_x + 64.0f + (m_scroll_map_x);
			*vx = -(*vx) * 0.1f;


		}
		if (r > 45 && r < 135)
		{
			//上
			*down = true;
			*y = m_y - 64.0f + (m_scroll_map_y);
			*vy = -(*vy) * 0.1f;



		}
		if (r > 135 && r < 225)
		{
			//左
			*left = true;
			*x = m_x - 64.0f + (m_scroll_map_x);
			*vx = -(*vx) * 0.1f;					
		}
		if (r > 225 && r < 315)
		{
			//下
			*up = true;
			*y = m_y + 64.0f + (m_scroll_map_y);
			*vy = -(*vy) * 0.1f;


		}
    }
}




