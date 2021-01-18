#include "GameHead.h"
#include "CObjPlayerBullet.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"



using namespace GameL;

CObjPlayerBullet::CObjPlayerBullet(float x, float y, float r,int n) {
	m_x = x+20;
	m_y = y+20;
	m_r = r;
	num = n;
};

void CObjPlayerBullet::Init() {
	m_vx = 0;
	m_vy = 0;

	//�X�N���[���������̃x�N�g�����擾
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();


	m_speed = 6;
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_RED, OBJ_BULLET, 1);
};

void CObjPlayerBullet::Action() {


		CHitBox* Hit = Hits::GetHitBox(this);
		
		//��l�����ł��������X�N���[���̉e�����󂯂�悤�Ƀv���O����
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		float scrollx,scrolly;
		scrollx = block->GetSX();
		scrolly = block->GetSY();
		
		m_newscroll_x = scrollx;
		m_newscroll_y = scrolly;

		m_vx = cos(3.14 / 180.0f * m_r);
		m_vy = sin(3.14 / 180.0f * m_r);

		m_x += m_vx * m_speed;
		m_y += m_vy * m_speed;

		m_x += m_newscroll_x -m_scroll_map_x;
		m_y += m_newscroll_y -m_scroll_map_y;

		Hit->SetPos(m_x, m_y);

		m_x -= scrollx - m_scroll_map_x;
		m_y -= scrolly - m_scroll_map_y;

		int data_base[4] =
		{
			m_up,m_down,m_reft,m_right
		};

		CObjBlock* bbh = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		bbh->BlockHit(&m_x, &m_y, &m_up, &m_down, &m_reft, &m_right, &m_vx, &m_vy);

		if (Hit->CheckObjNameHit(OBJ_ENEMY) != nullptr) {


			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		else if (Hit->CheckObjNameHit(OBJ_ENEMY_BULLET) != nullptr) {
			//�G�̋�

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		else if (Hit->CheckObjNameHit(OBJ_BOSS_BULLET2) != nullptr) {
			//BOSS�ł����e

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		else if (Hit->CheckObjNameHit(OBJ_ENEMY_3BULLET) != nullptr) {
			//�G3��

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		for (int i = 0; i <= 3; i++)
		{
			
			if (data_base[i] == true)
			{
				Effect* effect = new Effect(m_x, m_y, m_r);
				Objs::InsertObj(effect, OBJ_EFFECT, 20);

				this->SetStatus(false);
				Hits::DeleteHitBox(this);
			}
		}	

		
};

void CObjPlayerBullet::Draw() {
	float c[4] = {1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	if (num == 1) {
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 768.0f;
		src.m_bottom = 768.0f;

		dst.m_top = 0.0f + m_y + (m_newscroll_y - m_scroll_map_y);
		dst.m_left = 0.0f + m_x + (m_newscroll_x - m_scroll_map_x);
		dst.m_right = 32.0f + m_x + (m_newscroll_x - m_scroll_map_x);
		dst.m_bottom = 32.0f + m_y + (m_newscroll_y - m_scroll_map_y);

		Draw::Draw(14, &src, &dst, c, 0);
	}
	if (num == 2)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 265.0f;
		src.m_bottom = 265.0f;

		dst.m_top = 0.0f + m_y + (m_newscroll_y - m_scroll_map_y);
		dst.m_left = 0.0f + m_x + (m_newscroll_x - m_scroll_map_x);
		dst.m_right = 32.0f + m_x + (m_newscroll_x - m_scroll_map_x);
		dst.m_bottom = 32.0f + m_y + (m_newscroll_y - m_scroll_map_y);

		Draw::Draw(10, &src, &dst, c, 0);
	}
};