//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "CObjPlayerBullet.h"
#include "CObjpenetrateBullet.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "math.h"

//主人公のHP（体力）
#define HP 5

//使用するネームスペース
using namespace GameL;

bool VectorNormalize(float* vx, float* vy);//ベクトル正規化関数

//コンストラクタ
CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjHero::Init()
{
	m_bullet = 10;
	m_unique_bullet_1 = 3;
	m_unique_bullet_2 = 3;
	m_hero_flag = false;
	m_hp = HP;

	//当たり判定
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//主人公（人）の状態なら動作しない
	if (m_hero_flag == false)
	{
		//ベクトルを0にする
		m_vx = 0;
		m_vy = 0;

		//戦車状態→人状態へ
		if (Input::GetVKey('V') == true)
		{
			if (m_hero_flag == false)
			{
				m_hero_flag = true;

				//主人公（人）を作成
				CObjChara* obj_chara = new CObjChara(m_x+20, m_y+20);
				Objs::InsertObj(obj_chara, OBJ_CHARA, 11);
				//チャタリング防止用
				while (Input::GetVKey('V') == true);
			}
		}

		if (m_r > 360.0f)
			m_r = 0.0f;
		else if (m_r < 0.0f)
			m_r = 360.0f;

		//右方向
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			
			m_r -= 1.0f;
		}
		//左方向
		else if (Input::GetVKey(VK_LEFT) == true)
		{
			
			m_r += 1.0f;
		}
		//上方向
		else if (Input::GetVKey(VK_UP) == true)
		{
			rad = m_r * 3.14 / 180;

			sin_f = sinf(rad);
			cos_f = cosf(rad);

			VectorNormalize(&sin_f, &cos_f);

			m_vx = -sin_f;
			m_vy = -cos_f;
		}
		//下方向
		else if (Input::GetVKey(VK_DOWN) == true)
		{
			rad = m_r * 3.14 / 180;

			sin_f = sinf(rad);
			cos_f = cosf(rad);

			VectorNormalize(&sin_f, &cos_f);

			m_vx = +sin_f;
			m_vy = +cos_f;
		}

		//ベクトルを位置に加算
		m_x += m_vx;
		m_y += m_vy;

		//HitBoxの内容更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x, m_y);

		if (m_bullet_time == true) {
			if (Input::GetVKey('Z') == true && m_bullet > 0)
			{
				CObjPlayerBullet* obj_ab = new CObjPlayerBullet(m_x, m_y, m_r - (m_r * 2) - 90);
				Objs::InsertObj(obj_ab, OBJ_ANGLE_BULLET, 14);
				m_bullet -= 1;
				m_bullet_time = false;
			}
			if (Input::GetVKey('X') == true && m_unique_bullet_1 > 0) {
				CObjPenetrateBullet* obj_pb = new CObjPenetrateBullet(m_x, m_y, m_r - (m_r * 2) - 90);
				Objs::InsertObj(obj_pb, OBJ_PENETRATE_BULLET, 15);
				m_unique_bullet_1 -= 1;
				m_bullet_time = false;
			}
			if (Input::GetVKey('C') == true && m_unique_bullet_2 > 0) {
				for (int i = 0; i < 3; i++) {
					CObjPlayerBullet* obj_db = new CObjPlayerBullet(m_x, m_y, m_r - (m_r * 2) - (60 + (30 * i)));
					Objs::InsertObj(obj_db, OBJ_ANGLE_BULLET, 16);
				}
				m_unique_bullet_2 -= 1;
				m_bullet_time = false;
			}
		}

		//当たり判定を行うオブジェクト情報部
		int data_base[4] =
		{
			OBJ_ENEMY,
			OBJ_ENEMY_BULLET,
			OBJ_ENEMY_3BULLET,
		};
		//敵オブジェクトと接触したら主人公のm_hpが減少
		for (int i = 0; i < 4; i++)
		{
			if (hit->CheckObjNameHit(data_base[i]) != nullptr)
			{
				m_hp -= 1;
			}
		}
		////m_hpが０になると主人公を破棄
		//if (m_hp == 0)
		//{
		//	this->SetStatus(false);//自身に削除命令を出す
		//	Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する

		//	//Scene::SetScene(new CSceneTitle());
		//}

		//攻撃間隔制御
		if (m_bullet_time == false)
		{
			m_time++;
			if (m_time == 30)
			{
				m_bullet_time = true;
				m_time = 0;
			}	
		}
	}
}

//ドロー
void CObjHero::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 22.0f;
	src.m_left = 22.0f;
	src.m_right = 400.0f;
	src.m_bottom = 400.0f;

	//表示位置の設定
	dst.m_top =- 22.0f + m_y;
	dst.m_left = -25.0f + m_x;
	dst.m_right = 32.0f + 64.0f + m_x;
	dst.m_bottom =32.0f + 64.0f + m_y;

	//描画
	Draw::Draw(20, &src, &dst, c, m_r);
}

bool VectorNormalize(float* vx, float* vy)
{
	//ベクトルの長さを求める
	float r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);

	//長さが0かどうか調べる
	if (r == 0.0f)
	{
		//0なら計算失敗
		return false;
	}
	else
	{
		//正規化を行い、vxとvyの参照先の値を変更
		(*vx) = 1.0f / r * (*vx);
		(*vy) = 1.0f / r * (*vy);
	}
	//計算成功
	return true;
}