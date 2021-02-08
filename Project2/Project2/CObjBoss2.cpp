#include"GameL\DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL\SceneManager.h"
#include"GameL/WinInputs.h"
#include "GameL\Audio.h"

#include"GameHead.h"
#include"CObjBoss2.h"
#include"SceneMain.h"

using namespace GameL;

CObjBoss2::CObjBoss2(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjBoss2::Init()
{
	m_hp = 15.0f;
	m_attack = false;
	pbullet_interval = 0; //ä—í íeÉqÉbÉgÇÃä‘äu
	pbullet_enable = false; //ä—í íeÉ_ÉÅÅ[ÉWóLå¯

	m_hit_up = false;
	m_hit_left = false;
	m_hit_right = false;
	m_hit_down = false;

	//HitBoxí«â¡
	Hits::SetHitBox(this, m_x, m_y, 150, 172, ELEMENT_ENEMY, OBJ_BOSS2, 1);
}

void CObjBoss2::Action()
{
	if (m_x >= (80 * 64) || m_y >= (60 * 64))
	{

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	//éÂêlåˆÇÃç¿ïWéÊìæ

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjUserInterface* UI = (CObjUserInterface*)Objs::GetObj(OBJ_USERINTERFACE);
	int stage = UI->GetS();
	if (stage == 2)
	{
		if (hero != nullptr)
		{
			float hx = hero->GetX();
			float hy = hero->GetY();

			//ìGÇ©ÇÁéÂêlåˆÇÃÉxÉNÉgÉãÇãÅÇﬂÇÈ
			float x = m_x - hx + m_scroll_map_x;
			float y = m_y - hy + m_scroll_map_y;

			m_r = atan2(x, y) * 180.0f / 3.14f;

			if (m_r < 0)
				m_r = 360 - abs(m_r);
		}
	}
	m_x += m_scroll_map_x;
	m_y += m_scroll_map_y;

	m_x -= m_scroll_map_x;
	m_y -= m_scroll_map_y;

	//HitBoxÇÃì‡óeçXêV
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);

	if (stage == 2)
	{
		//trueÇ»ÇÁíeî≠éÀ
		if (m_attack == true)
		{
			//î≠éÀâπñ¬ÇÁÇ∑
			Audio::Start(10);

			CObjBossBullet2* obj_eb = new CObjBossBullet2(m_x-40.0f, m_y-30.0f, -m_r - 90);
			Objs::InsertObj(obj_eb, OBJ_BOSS_BULLET2, 50);

			m_attack = false;
		}
	}
	else if (stage == 4)
	{
		if (m_attack == true)
		{
			bool reflect = true;
			if (m_maelstrom_time == 10)
			{
				if (m_r >= 0.0 && reflect == true)
				{
					//äpìxm_angleÇ≈äpìxíeä€î≠éÀ
					m_r += 10.0;
					CObjBossBullet4* obj_bossbullet = new CObjBossBullet4(m_x-15.0f, m_y-10.0f, -m_r-95.0f);
					Objs::InsertObj(obj_bossbullet, OBJ_BOSS_BULLET4, 50);
					if (m_r >= 360.0)
					{
						reflect = false;
					}
				}
				else if (m_r <= 360 && reflect == false)
				{
					//äpìxm_angleÇ≈äpìxíeä€î≠éÀ
					m_r -= 10.0;
					if (m_r <= 0)
					{
						reflect = true;
					}
				}
				m_maelstrom_time = 0;
			}
			m_maelstrom_time++;

		}
	}
	//íeä€Ç∆ê⁄êGÇµÇƒÇ¢ÇÈÇ©Çí≤Ç◊ÇÈ
	CSceneMain* main = new CSceneMain();
	//ãﬂê⁄çUåÇÇ™ìñÇΩÇ¡ÇƒÇ¢ÇÈÇ©í≤Ç◊ÇÈ
	if (hit->CheckObjNameHit(OBJ_ATTACK) != nullptr)
	{
		Effect* effect = new Effect(m_x, m_y, m_r);
		Objs::InsertObj(effect, OBJ_EFFECT, 20);
		m_hp -= 0.05f;
		if (m_hp <= 0 && stage != 4) {
			//îöî≠âπñ¬ÇÁÇ∑
			Audio::Start(12);

			this->SetStatus(false);//é©êgÇ…çÌèúñΩóﬂÇèoÇ∑
			Hits::DeleteHitBox(this);//íeä€Ç™èäóLÇ∑ÇÈHitBoxÇ…çÌèúÇ∑ÇÈÅB
			Audio::VolumeMaster(-1.0f);

			main->RoundChange();
		}
		else if (m_hp <= 0 && stage == 4)
		{
			Audio::Start(12);
			Audio::VolumeMaster(-1.0f);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Scene::SetScene(new CSceneGameClear);
		}
	}
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		//íeíÖíeâπ
		Audio::Start(13);

		m_hp--;

		if (m_hp <= 0&&stage!=4) {
			//îöî≠âπñ¬ÇÁÇ∑
			Audio::Start(12);
			Audio::VolumeMaster(-1.0f);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			main->RoundChange();
		}
		else if (m_hp <= 0 && stage == 4)
		{
			Audio::Start(12);
			Audio::VolumeMaster(-1.0f);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Scene::SetScene(new CSceneGameClear);
		}
	}
	else if (pbullet_enable == false) {
		if (hit->CheckObjNameHit(OBJ_PENETRATE_BULLET) != nullptr) {
			//íeíÖíeâπ
			Audio::Start(13);

			m_hp--;
			pbullet_enable = true;
			if (m_hp <= 0 && stage != 4) {				
				//îöî≠âπñ¬ÇÁÇ∑
				Audio::Start(12);
				Audio::VolumeMaster(-1.0f);
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				main->RoundChange();
				
			}
			else if (m_hp <= 0 && stage == 4)
			{
				Audio::Start(12);
				Audio::Stop(0);
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				Scene::SetScene(new CSceneGameClear);
			}
		}
	}
	if (pbullet_enable == true) {
		pbullet_interval++;
		if (pbullet_interval > 7) {
			pbullet_interval = 0;
			pbullet_enable = false;
		}
	}

	//çUåÇä‘äu
	if (m_attack == false)
	{
		m_attack_time++;
		if (m_attack_time == 100)
		{
			m_attack = true;
			m_attack_time = 0;
		}
	}
}

void CObjBoss2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//êÿÇËéÊÇËà íu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 300.0f;

	//èoóÕà íu
	dst.m_top = 40.0f + m_y + m_scroll_map_y - 40.0f;
	dst.m_left = 40.0f + m_x + m_scroll_map_x - 35.0f;
	dst.m_right = 180.0f + m_x + m_scroll_map_x - 35.0f;
	dst.m_bottom = 200.0f + m_y + m_scroll_map_y - 34.0f;

	Draw::Draw(9, &src, &dst, c, 0);

	RECT_F src2;
	RECT_F dst2;

	//êÿÇËéÊÇËà íu
	src2.m_top = 0.0f;
	src2.m_left = 0.0f;
	src2.m_right = 300.0f;
	src2.m_bottom = 300.0f;

	//èoóÕà íu
	dst2.m_top = 40.0f + m_y + m_scroll_map_y - 40.0f;
	dst2.m_left = 40.0f + m_x + m_scroll_map_x - 35.0f;
	dst2.m_right = 180.0f + m_x + m_scroll_map_x - 35.0f;
	dst2.m_bottom = 200.0f + m_y + m_scroll_map_y - 34.0f;

	Draw::Draw(8, &src, &dst, c, m_r);
}