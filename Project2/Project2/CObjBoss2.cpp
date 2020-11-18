#include"GameL\DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL\SceneManager.h"
#include"GameL/WinInputs.h"
#include "GameL\Audio.h"

#include"GameHead.h"
#include"CObjBoss2.h"

using namespace GameL;

CObjBoss2::CObjBoss2(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjBoss2::Init()
{
	m_hp = 20;
	m_attack = false;
	pbullet_interval = 0; //�ђʒe�q�b�g�̊Ԋu
	pbullet_enable = false; //�ђʒe�_���[�W�L��

	//HitBox�ǉ�
	Hits::SetHitBox(this, m_x, m_y, 172, 172, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

void CObjBoss2::Action()
{
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	//��l���̍��W�擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (hero != nullptr)
	{
		float hx = hero->GetX();
		float hy = hero->GetY();

		//�G�����l���̃x�N�g�������߂�
		float x = m_x - hx + m_scroll_map_x;
		float y = m_y - hy + m_scroll_map_y;

		m_r = atan2(x, y) * 180.0f / 3.14f;

		if (m_r < 0)
			m_r = 360 - abs(m_r);
	}

	m_x += m_scroll_map_x;
	m_y += m_scroll_map_y;

	m_x -= m_scroll_map_x;
	m_y -= m_scroll_map_y;

	//HitBox�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);

	//true�Ȃ�e����
	if (m_attack == true)
	{
		//���ˉ��炷
		Audio::Start(10);

		CObjBossBullet2* obj_eb = new CObjBossBullet2(m_x + m_scroll_map_x, m_y + m_scroll_map_y, -m_r-90);
		Objs::InsertObj(obj_eb, OBJ_BOSS_BULLET2, 16);

		m_attack = false;
	}

	//�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET) != nullptr)
	{
		m_hp--;
		if (m_hp <= 0) {
			//�������炷
			Audio::Start(12);

			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//�e�ۂ����L����HitBox�ɍ폜����B
		}
	}
	if (pbullet_enable == false) {
		if (hit->CheckObjNameHit(OBJ_PENETRATE_BULLET) != nullptr) {
			m_hp--;
			pbullet_enable = true;
			if (m_hp <= 0) {
				//�������炷
				Audio::Start(12);

				this->SetStatus(false);
				Hits::DeleteHitBox(this);
			}
		}
	}
	else if (pbullet_enable == true) {
		pbullet_interval++;
		if (pbullet_interval > 7) {
			pbullet_interval = 0;
			pbullet_enable = false;
		}
	}


	if (m_attack == false)
	{
		m_attack_time++;
		if (m_attack_time == 200)
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

	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 230.0f;
	src.m_bottom = 400.0f;

	//�o�͈ʒu
	dst.m_top = 40.0f + m_y + m_scroll_map_y - 40.0f;
	dst.m_left = 40.0f + m_x + m_scroll_map_x - 35.0f;
	dst.m_right = 180.0f + m_x + m_scroll_map_x - 35.0f;
	dst.m_bottom = 200.0f + m_y + m_scroll_map_y - 34.0f;

	Draw::Draw(7, &src, &dst, c, m_r);
}