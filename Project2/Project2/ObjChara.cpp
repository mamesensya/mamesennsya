//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjChara.h"

using namespace GameL;

//コンストラクタ
CObjChara::CObjChara(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjChara::Init()
{
	m_hp = 5;

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//ヒーローからフラグ情報をもらって代入
	m_hero_flag = hero->m_hero_flag;
	//当たり判定
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_CHARA, OBJ_CHARA, 1);
}

void CObjChara::Action()
{
	//主人公の情報を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//主人公が存在しないなら動作しない
	if (hero != nullptr)
	{
		//HitBoxの内容更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x, m_y);

		//人状態→戦車状態へ
		if (m_hero_flag == true)
		{
			//主人公（戦車）のHitBoxに当たっているときに切り替えができる
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				//主人公が人状態に移行
				if (Input::GetVKey('V') == true)
				{
					m_hero_flag = false;

					hero->m_hero_flag = false;

					this->SetStatus(false);//自身に削除命令を出す
					Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する
					//チャタリング防止用
					while (Input::GetVKey('V') == true);
				}
			}
			//右方向
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				m_r = 270.0f;
				m_vx = 1.0f;
			}
			//左方向
			if (Input::GetVKey(VK_LEFT) == true)
			{
				m_r = 90.0f;
				m_vx = -1.0f;
			}
			//上方向
			if (Input::GetVKey(VK_UP) == true)
			{
				m_r = 0.0f;
				m_vy = -1.0f;
			}
			//下方向
			if (Input::GetVKey(VK_DOWN) == true)
			{
				m_r = 180.0f;
				m_vy = 1.0f;
			}

			//主人公近接攻撃
			if (m_attack == true)
			{
				if (Input::GetVKey('Z') == true)
				{
					CObjAttack* obj_at = new CObjAttack(m_x, m_y, m_r);
					Objs::InsertObj(obj_at, OBJ_ATTACK, 15);
					m_attack = false;
				}
			}
			//ベクトルを位置に加算
			m_x += +m_vx;
			m_y += m_vy;

			//ベクトルを0に戻す
			m_vx = 0;
			m_vy = 0;

			//当たり判定を行うオブジェクト情報部
			int data_base[4] =
			{
				OBJ_ENEMY,
				OBJ_ENEMY_BULLET,
				OBJ_ENEMY_3BULLET,
			};

			//敵オブジェクトと接触したら主人公のm_hpが減少
			if (m_hit == true)
			{
				for (int i = 0; i < 4; i++)
				{
					if (hit->CheckObjNameHit(data_base[i]) != nullptr)
					{
						m_hp -= 1;
						m_hit = false;
					}
				}
			}
			////m_hpが０になると主人公を破棄
			//if (m_hp == 0)
			//{
			//	this->SetStatus(false);//自身に削除命令を出す
			//	Hits::DeleteHitBox(this);//主人公が所有するHitBoxを削除する

			//	//Scene::SetScene(new CSceneTitle());
			//}

			//攻撃間隔制御用
			if (m_attack == false)
			{
				m_attack_time++;
				if (m_attack_time == 60)
				{
					m_attack = true;
					m_attack_time = 0;
				}
			}
			//被弾間隔制御用
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
}

void CObjChara::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 400.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + 16.0f + m_x;
	dst.m_bottom = 32.0f + 16.0f + m_y;

	//描画
	Draw::Draw(21, &src, &dst, c, m_r);
}