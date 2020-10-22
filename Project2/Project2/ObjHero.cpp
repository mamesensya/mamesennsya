//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjHero.h"

//当たり判定のオブジェクト情報部の数
#define Collision_detection 4
//主人公のHP（体力）
#define HP 5
//主人公のスピード
#define SPEED 1.0f

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_bullet = true;
	m_unique_bullet_1 = true;
	m_unique_bullet_2 = true;
	m_human_flag = false;
	m_hp = HP;
	direct = 1;

	//当たり判定
	Hits::SetHitBox(this, m_x+10, m_y+20, 72, 72, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	////戦車状態：攻撃
	//if (m_human_flag == false)
	//{
	//	//通常弾
	//	if (Input::GetVKey('C') == true)
	//	{
	//		if (m_bullet == true)
	//		{
	//			//弾丸オブジェクト作成
	//			CObjBullet* obj_b = new CObjBullet(m_x, m_y);//弾丸オブジェクト作成
	//			Objs::InsertObj(obj_b, OBJ_BULLET, 1);//作った弾丸オブジェクトをオブジェクトマネージャーに登録

	//			m_bullet = false;
	//		}
	//		else
	//		{
	//			m_bullet = true;
	//		}
	//	}
	//	//特殊弾（１）
	//	else if (Input::GetVKey('X') == true)
	//	{
	//		if (m_unique_bullet_1 == true)
	//		{
	//			//弾丸オブジェクト作成
	//			CObjBullet* obj_b = new CObjBullet(m_x, m_y);//弾丸オブジェクト作成
	//			Objs::InsertObj(obj_b, OBJ_BULLET, 1);//作った弾丸オブジェクトをオブジェクトマネージャーに登録

	//			m_unique_bullet_1 = false;
	//		}
	//		else
	//		{
	//			m_unique_bullet_1 = true;
	//		}
	//	}
	//	//特殊弾（２）
	//	else if (Input::GetVKey('Z') == true)
	//	{
	//		if (m_unique_bullet_2 == true)
	//		{
	//			//弾丸オブジェクト作成
	//			CObjBullet* obj_b = new CObjBullet(m_x, m_y);//弾丸オブジェクト作成
	//			Objs::InsertObj(obj_b, OBJ_BULLET, 1);//作った弾丸オブジェクトをオブジェクトマネージャーに登録

	//			m_unique_bullet_2 = false;
	//		}
	//		else
	//		{
	//			m_unique_bullet_2 = true;
	//		}
	//	}
	//}
	////人状態：攻撃
	//if (m_human_flag == true)
	//{
	//	//通常弾
	//	if (Input::GetVKey('C') == true)
	//	{
	//		if (m_attack == true)
	//		{

	//			m_attack = false;
	//		}
	//		else
	//		{
	//			m_attack = true;
	//		}
	//	}
	//}
	//人状態→戦車状態へ
	if (m_human_flag == true)
	{
		//主人公が戦車状態に移行
		if (Input::GetVKey('V') == true)
		{
			m_human_flag = false;
			//チャタリング防止用
			while (Input::GetVKey('V') == true);
		}
	}
	//戦車状態→人状態へ
	else if (m_human_flag == false)
	{
		//主人公が人状態に移行
		if (Input::GetVKey('V') == true)
		{
			m_human_flag = true;
			//チャタリング防止用
			while (Input::GetVKey('V') == true);
		}
	}
	//ヒットボックス
	CHitBox* hit = Hits::GetHitBox(this);
	//右方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_r = 270.0f;
		m_x += SPEED;
		direct = 2;
		//HitBoxの位置情報更新
		hit->SetPos(m_x, m_y + 12);
	}
	//左方向
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_r = 90.0f;
		m_x -= SPEED;
		direct = 4;
		//HitBoxの位置情報更新
		hit->SetPos(m_x + 20, m_y + 12);
	}
	//上方向
	if (Input::GetVKey(VK_UP) == true)
	{
		m_r = 0.0f;
		m_y -= SPEED;
		direct = 1;
		//HitBoxの位置情報更新
		hit->SetPos(m_x + 10, m_y + 20);
	}
	//下方向
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_r = 180.0f;
		m_y += SPEED;
		direct = 3;
		//HitBoxの位置情報更新
		hit->SetPos(m_x + 10, m_y);
	}
	//当たり判定を行うオブジェクト情報部
	int data_base[Collision_detection] =
	{
		OBJ_ENEMY,
	};

	//敵オブジェクトと接触したら主人公のm_hpが減少
	if (hit->CheckObjNameHit(data_base[Collision_detection]) != nullptr)
	{
		m_hp -= 1;
	}
	//m_hpが０になると主人公を破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する

		//Scene::SetScene(new CSceneTitle());
	}
}

//ドロー
void CObjHero::Draw()
{
	//主人公（戦車）のグラフィック
	if (m_human_flag == false)
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
	//主人公（人）のグラフィック
	if(m_human_flag == true)
	{

	}
}