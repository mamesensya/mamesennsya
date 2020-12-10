//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "CObjPlayerBullet.h"
#include "CObjpenetrateBullet.h"
#include "GameL\Audio.h"
#include"Objbreakblock.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "math.h"

//主人公のHP（体力）
#define HP 5

//使用するネームスペース
using namespace GameL;

//角度をラジアンに変える
inline void sin_cos(float r,float *sin,float *cos) 
{ 
	float rad = r * 3.14 / 180;

	*sin = sinf(rad);
	*cos = cosf(rad);
}

//弾をたくさん持っていると主人公の速度が変化
inline void VectorChange(int bullet, float* sin, float* cos)
{
	if (bullet >= 40)
	{
		*sin *= 0.1f;
		*cos *= 0.1f;
	}
	else if (bullet >= 30)
	{
		*sin *= 0.5f;
		*cos *= 0.5f;
	}
}

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
	bullet = m_bullet + m_unique_bullet_1 + m_unique_bullet_2;

	//当たり判定
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//m_time++;
	//if (m_time == 21.0f)
	//{
	//	m_time = 0;
	//}


	//HitBoxの内容更新
	CHitBox* hit = Hits::GetHitBox(this);

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
				CObjChara* obj_chara = new CObjChara(m_x, m_y);
				Objs::InsertObj(obj_chara, OBJ_CHARA, 11);
				//チャタリング防止用
				while (Input::GetVKey('V') == true);
			}
		}

		//角度を0～360°以内の数字に抑える
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
		if (Input::GetVKey(VK_UP) == true)
		{
			//角度をラジアンに変換してsin cosの計算
			sin_cos(m_r, &sin_f, &cos_f);
			//ベクトルの正規化
			VectorNormalize(&sin_f, &cos_f);
			//弾の所持数に応じて速度変更
			VectorChange(bullet, &sin_f, &cos_f);

			m_vx = -sin_f*3;
			m_vy = -cos_f*3;
		}
		//下方向
		else if (Input::GetVKey(VK_DOWN) == true)
		{
			//角度をラジアンに変換してsin cosの計算
			sin_cos(m_r, &sin_f, &cos_f);
			//ベクトルの正規化
			VectorNormalize(&sin_f, &cos_f);
			//弾の所持数に応じて速度変更
			VectorChange(bullet, &sin_f, &cos_f);

			m_vx = +sin_f*3;
			m_vy = +cos_f*3;
		}

		//ブロックとの当たり判定
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_x, &m_y, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy);

		


		//ベクトルを位置に加算
		m_x += m_vx;
		m_y += m_vy;

		m_scroll = pb->GetSX();
		m_scroll2 = pb->GetSY();
		//スクロールが左上x500y500以上　右下x-5000y-2500以下なら初期値に戻す
		if (m_scroll >= 500 || m_scroll <= -5000 || m_scroll2 >= 500 || m_scroll2 <= -2000)
		{
			m_scroll = 0;
			m_scroll2 = 0;
			pb->SetSX(m_scroll);
			pb->SetSY(m_scroll2);
		}
		hit->SetPos(m_x, m_y);

		if (m_attack == true) {
			if (Input::GetVKey('Z') == true && m_bullet > 0)
			{
				//発射音鳴らす
				Audio::Start(10);

				CObjPlayerBullet* obj_ab = new CObjPlayerBullet(m_x, m_y, m_r - (m_r * 2) - 90);
				Objs::InsertObj(obj_ab, OBJ_BULLET, 14);
				m_bullet -= 1;
				bullet -= 1;
				m_attack = false;
			}
			if (Input::GetVKey('X') == true && m_unique_bullet_1 > 0) {
				//発射音鳴らす
				Audio::Start(10);

				CObjPenetrateBullet* obj_pb = new CObjPenetrateBullet(m_x, m_y, m_r - (m_r * 2) - 90);
				Objs::InsertObj(obj_pb, OBJ_BULLET, 15);
				m_unique_bullet_1 -= 1;
				bullet -= 1;
				m_attack = false;
			}
			if (Input::GetVKey('C') == true && m_unique_bullet_2 > 0) {
				//発射音鳴らす
				Audio::Start(10);
				
				for (int i = 0; i < 3; i++) {
					CObjPlayerBullet* obj_db = new CObjPlayerBullet(m_x, m_y, m_r - (m_r * 2) - (60 + (30 * i)));
					Objs::InsertObj(obj_db, OBJ_BULLET, 16);
				}
				m_unique_bullet_2 -= 1;
				bullet -= 1;
				m_attack = false;
			}
		}

		if (Input::GetVKey('Q') == true) {
			CObjSaveSystem* savesys = new CObjSaveSystem();
			int state = savesys->GetState();
			if (state == 0) {
				savesys->SetState(1);
				Objs::InsertObj(savesys, OBJ_SAVE, 17);
			};
		};

		//当たり判定を行うオブジェクト情報部
		int data_base[10] =
		{
			OBJ_ENEMY,
			OBJ_ENEMY_BULLET,
			OBJ_ENEMY3,
			OBJ_ENEMY_3BULLET,
			OBJ_BOSS,
			OBJ_BOSS_BULLET,
			OBJ_GHOST,
			OBJ_GHOST_ATTACK,
			OBJ_BOSS2,
			OBJ_BOSS_BULLET2,
		};
		//敵オブジェクトと接触したら主人公のm_hpが減少
		if (m_hit == true)
		{
			for (int i = 0; i < 10; i++)
			{
				if (hit->CheckObjNameHit(data_base[i]) != nullptr)
				{
					//弾着弾音
					Audio::Start(14);

					m_hp -= 1;
					m_hit = false;
				}
			}
		}
		//m_hpが０になると主人公を破棄
		if (m_hp <= 0)
		{
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する

			Scene::SetScene(new CSceneGameOver());
		}

		//攻撃間隔制御
		if (m_attack == false)
		{
			m_attack_time++;
			if (m_attack_time == 30)
			{
				m_attack = true;
				m_attack_time = 0;
			}	
		}
		//被弾間隔制御
		if (m_hit == false)
		{
			m_hit_time++;
			if (m_hit_time == 60)
			{
				m_hit = true;
				m_hit_time = 0;
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
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 300.0f;

	//表示位置の設定
	dst.m_top = -10.0f+ m_y;
	dst.m_left = -10.0f+ m_x;
	dst.m_right = 70.0f + m_x;
	dst.m_bottom =  70.0f + m_y;

	//描画
	Draw::Draw(19, &src, &dst, c, m_r);
}

//ベクトルの正規化関数
//float vx		m_vx：x軸ベクトル
//float vy		m_vy：y軸ベクトル
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