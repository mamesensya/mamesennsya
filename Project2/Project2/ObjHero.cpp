//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "CObjPlayerBullet.h"
#include "CObjpenetrateBullet.h"

#include "GameHead.h"
#include "ObjHero.h"

//主人公のHP（体力）
#define HP 5

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjHero::Init()
{
	m_bullet = true;
	m_unique_bullet_1 = true;
	m_unique_bullet_2 = true;
	m_hero_flag = false;
	m_hp = HP;
	direct = 1;
	m_bullet_time = true;

	//当たり判定
	Hits::SetHitBox(this, m_x, m_x, 72, 72, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//戦車状態→人状態へ
	if (m_hero_flag == false)
	{
		//主人公が人状態に移行
		if (Input::GetVKey('V') == true)
		{
			m_hero_flag = true;
			//チャタリング防止用
			while (Input::GetVKey('V') == true);
		}
	}
	//ヒットボックス
	CHitBox* hit = Hits::GetHitBox(this);
	//右方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_r -= 1.0f;
		direct += 1;
	}
	//左方向
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_r += 1.0f;
		direct -= 1;
	}
	//上方向
	if (Input::GetVKey(VK_UP) == true)
	{
		direct = 1;
	}
	//下方向
	if (Input::GetVKey(VK_DOWN) == true)
	{
		direct = 1;
	}

	m_x = +m_vx;
	m_y = +m_vy;
	
	if(m_bullet_time==true)
	if (Input::GetVKey('Z') == true) 
	{
		CObjPlayerBullet* obj_ab = new CObjPlayerBullet(m_x,m_y,(float)((direct+2)*90));
		Objs::InsertObj(obj_ab, OBJ_ANGLE_BULLET, 14);
		m_bullet_time = false;
	}
	if (m_bullet_time==true)
	if (Input::GetVKey('X') == true) {
		CObjPenetrateBullet* obj_pb = new CObjPenetrateBullet(m_x, m_y, (float)((direct + 2) * 90));
		Objs::InsertObj(obj_pb, OBJ_PENETRATE_BULLET, 15);
		m_bullet_time = false;
	}

	//当たり判定を行うオブジェクト情報部
	int data_base[4] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY_BULLET,
	};

	//敵オブジェクトと接触したら主人公のm_hpが減少
	for (int i = 0; i < 4; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			m_hp -= 1;
		}
	}
	//m_hpが０になると主人公を破棄
	if (m_hp == 0)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する

		//Scene::SetScene(new CSceneTitle());
	}

	if (m_bullet_time == false)
	{
		m_time++;
		if (m_time == 60) 
		{
			m_bullet_time = true;
			m_time = 0;
		}
	}

}

//ドロー
void CObjHero::Draw()
{
	if (m_hero_flag == false)
	{
		//カラー情報
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 300.0f;
		src.m_bottom = 300.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 32.0f + 64.0f + m_x;
		dst.m_bottom = 32.0f + 64.0f + m_y;

		//描画
		Draw::Draw(0, &src, &dst, c, m_r);
	}
}