#include"GameL\DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL\SceneManager.h"
#include"GameL/WinInputs.h"
#include "GameL\Audio.h"

#include"GameHead.h"
#include"CObjBoss.h"
#include"CObjAngleBullet.h"
#include "Objbreakblock.h"
#include"CObjBossBullet2.h"

using namespace GameL;

CObjBoss::CObjBoss(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBoss::Init()
{
	m_vx = 0.0f;    //�ړ�����
	m_vy = 0.0f;
	m_r = 0.0f;//���������߂�ϐ�
	m_hp = 5;//�̗�
	count = 0;//�������Œ肷��J�E���g
	m_time = 0;//�e�۔��ː���ptime
	m_time2 = 0;
	m_move_time = 0;//�ړ��d���ptime

	pbullet_interval = 0; //�ђʒe�q�b�g�̊Ԋu
	pbullet_enable = false; //�ђʒe�_���[�W�L��

	//HitBox�ǉ�
	Hits::SetHitBox(this, m_x , m_y , 120, 120, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

void CObjBoss::Action()
{
	if (m_x >= (80 * 64) || m_y >= (60 * 64))
	{

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	m_time2++;
	m_time++;
	m_oni_time++;
	if (m_time2 > 400)
	{
		m_time2 = 0;
	}
	if (m_time > 300)
	{
		m_time = 0;

	}
	if (m_oni_time > 100)
	{
		m_oni_time = 0;
	}

	//������x�߂Â��Ǝ�l���ƕ��s�Ȉʒu�܂ňړ�

	float x = 0;//��l������G�̃x�N�g��x
	float y = 0;//��l������G�̃x�N�g��y

	//��l���̍��W�擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (hero != nullptr)
	{
		float hx = hero->GetX();
		float hy = hero->GetY();


		//�X�N���[��������������Ă��邩��{���̍��W���o��
		hx = hx - m_scroll_map_x;
		hy = hy - m_scroll_map_y;

		//�G�̍��W�͂��Ƃ��ƃX�N���[���̒l�������Ă��Ȃ�
		//�G�����l���̃x�N�g�������߂�@
		x = m_x - hx;
		y = m_y - hy;

		

		if ((x >= -600.0f && x <= 600.0f) || (y >= -600.0f && y <= 600.0f))
		{
			//��l���̕��Ɍ����v���O�����͒����ς�----------------------------
			//�G�̈ʒu��(-x,-y)�̎�
			if (x <= 0.0f && y <= 0.0f)
			{
				if (x > y)
				{
					if (x >= -60.0f && count == 0)
					{
						//x�����قڐ���
						m_r = 180.0f;
						m_vy = +0.1;
						count = 1;
					}
					if (x < -60.0f && m_move_time == 0)
					{
						//x���̕����߂��@
						m_r = -90.0f;
						m_vx = 0.7f;
					}
				}
				if (x < y)
				{
					if (y >= -60.0f && count == 0)
					{
						//y�����قڕ��s
						m_r = -90.0f;
						m_vx = 0.1f;
						count = 1;
					}
					if (y < -60.0f && m_move_time == 0)
					{
						//y���̕����߂�
						m_r = 180.0f;
						m_vy = 0.7f;
					}
				}
			}
			//(x,y)�̎�
			if (x >= 0.0f && y >= 0.0f)
			{
				if (x < y)
				{
					if (x <= 0.0f && count == 0)
					{
						//x�����قڐ���
						m_r = 0.0f;
						m_vy = -0.1f;
						count = 1;
					}
					if (x > 0.0f && m_move_time == 0)
					{
						//x���̕����߂�
						m_r = 90.0f;
						m_vx = -0.7f;
					}
				}
				if (x > y)
				{
					if (y <= 0.0f && count == 0)
					{
						//y�����قڕ��s
						m_r = 90.0f;
						m_vx = -0.1f;
						count = 1;
					}
					if (y > 0.0f && m_move_time == 0)
					{
						//y���̕����߂�
						m_r = 0.0f;
						m_vy = -0.7f;
					}
				}
			}

			//(x,-y)�̏ꍇ
			if (x >= 0.0f && y <= 0.0f)
			{
				float py = y - y - y;
				if (x < py)
				{
					if (x <= 0.0f && count == 0)
					{
						//x�����قڐ���
						m_r = 180.0f;
						m_vy = -0.1f;
						count = 1;
					}
					if (x > 0.0f && m_move_time == 0)
					{
						//x���̕����߂�
						m_r = 90.0f;
						m_vx = -0.7f;
					}
				}
				if (x > py)
				{
					if (y >= -60.0f && count == 0)
					{
						//y�����قڕ��s
						m_r = 90.0f;
						m_vx = -0.1f;
						count = 1;
					}
					if (y < -60.0f && m_move_time == 0)
					{
						//y���̕����߂�
						m_r = 180.0f;
						m_vy = 0.7f;
					}
				}
			}
			//(-x,y)�̏ꍇ
			if (x <= 0.0f && y >= 0.0f)
			{
				float px = x - x - x;
				if (px < y)
				{
					if (x >= -60.0f && count == 0)
					{
						//x�����قڐ���
						m_r = 0.0f;
						m_vy = -0.1;
						count = 1;
					}
					if (x < -60.0f && m_move_time == 0)
					{
						//x���̕����߂��@
						m_r = -90.0f;
						m_vx = 0.7f;
					}
				}
				if (px > y)
				{
					if (y <= -60.0f && count == 0)
					{
						//y�����قڕ��s
						m_r = -90.0f;
						m_vx = 0.1f;
						count = 1;
					}
					if (y > -60.0f && m_move_time == 0)
					{
						//y���̕����߂�
						m_r = 0.0f;
						m_vy = -0.7f;
					}
				}
			}
			//---------------------

			if (m_time == 300 && count == 1)
			{
				//���ˉ��炷
				Audio::Start(10);
				
				//�G�e�۔��ˁ@�@
				CObjBossBullet* obj_bb = new CObjBossBullet(m_x, m_y, m_r );
				Objs::InsertObj(obj_bb, OBJ_BOSS_BULLET, 16);
				
				if (m_Bcount == 0)
				{
					m_Bcount = 1;
				}
				else if (m_Bcount == 1)
				{
					m_Bcount = 0;
				}
				

			}
		//bool reflect = true;
		//if (m_time == 10)
		//{
		//	if (m_r >= 0.0 && reflect == true)
		//	{
		//		//�p�xm_angle�Ŋp�x�e�۔���
		//		m_r += 5.0;
		//		CObjAngleBullet* obj_a = new CObjAngleBullet(300, 300, m_r);
		//		Objs::InsertObj(obj_a, OBJ_ENEMY_BULLET, 1);
		//		if (m_r >= 360.0)
		//		{
		//			reflect = false;
		//		}
		//	}
		//	else if (m_r <= 360 && reflect == false)
		//	{
		//		//�p�xm_angle�Ŋp�x�e�۔���
		//		m_r -= 5.0;
		//		if (m_r <= 0)
		//		{
		//			reflect = true;
		//		}
		//	}
		//	m_time = 0;
		//}
		//m_time++;

			//�S����
			if (m_oni_time == 50&&m_oni_count<=3)
			{
				if (m_r == 0)
				{
					m_oni_count++;
					CObjGhost* obj_g = new CObjGhost(m_x + m_scroll_map_x, (m_y+172) + m_scroll_map_y);
					Objs::InsertObj(obj_g, OBJ_GHOST, 16);
					
				}
				if (m_r == 90)
				{
					m_oni_count++;
					CObjGhost* obj_g = new CObjGhost((m_x+172) + m_scroll_map_x, m_y + m_scroll_map_y);
					Objs::InsertObj(obj_g, OBJ_GHOST, 16);
					
				}
				if (m_r == 180)
				{
					m_oni_count++;
					CObjGhost* obj_g = new CObjGhost(m_x + m_scroll_map_x, (m_y-172) + m_scroll_map_y);
					Objs::InsertObj(obj_g, OBJ_GHOST, 16);
					
				}
				if (m_r == -90)
				{
					m_oni_count++;
					CObjGhost* obj_g = new CObjGhost((m_x-172) + m_scroll_map_x, m_y + m_scroll_map_y);
					Objs::InsertObj(obj_g, OBJ_GHOST, 16);
					
				}
				
			}


			if (m_time2==400)
			{
				//���ˉ��炷
				Audio::Start(10);

				CObjBossBullet2* obj_eb = new CObjBossBullet2(m_x-80 , m_y-80 , -m_r - 90);
				Objs::InsertObj(obj_eb, OBJ_BOSS_BULLET2, 50);
			}


		
		}
	}

	m_x += m_scroll_map_x;
	m_y += m_scroll_map_y;


	//�u���b�N�Ƃ̓����蔻��
	CObjBlock* eb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	eb->BlockHit(&m_x, &m_y, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy);

	m_x -= m_scroll_map_x;
	m_y -= m_scroll_map_y;


	m_x += m_vx;
	m_y += m_vy;


	//HitBox�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+ m_scroll_map_x, m_y+m_scroll_map_y);
	CSceneMain* main = new CSceneMain();
	
	//�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		//�e���e��
		Audio::Start(13);
		m_hp--;
		if (m_hp <= 0) {
			//�������炷
			Audio::Start(12);

			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//�e�ۂ����L����HitBox�ɍ폜����B
			
			main->RoundChange();
		}
	}
	else if (pbullet_enable == false) {
		if (hit->CheckObjNameHit(OBJ_PENETRATE_BULLET) != nullptr) {
			//�e���e��
			Audio::Start(13);

			m_hp--;
			pbullet_enable = true;

			if (m_hp <= 0) {
				//�������炷
				Audio::Start(12);
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				main->RoundChange();
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
	m_vx = 0;
	m_vy = 0;

	//�ړ��d������
	if (count == 1)
	{
		m_move_time++;
		if (m_move_time == 100)
		{
			m_move_time = 0;
			count = 0;
		}
	}

	
}

void CObjBoss::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 300.0f;

	//�o�͈ʒu�����p����
	if (m_r==0)
	{

		//�o�͈ʒu
		dst.m_top = -20.0f + m_y + m_scroll_map_y - 40.0f;
		dst.m_left = -50.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_right = 250.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_bottom = 280.0f + m_y + m_scroll_map_y - 34.0f;
	}
	if (m_r==90)
	{

		//�o�͈ʒu
		dst.m_top = -60.0f + m_y + m_scroll_map_y - 40.0f;
		dst.m_left = -20.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_right = 280.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_bottom = 240.0f + m_y + m_scroll_map_y - 34.0f;
	}
	if (m_r==180)
	{

		//�o�͈ʒu
		dst.m_top = -100.0f + m_y + m_scroll_map_y - 40.0f;
		dst.m_left = -60.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_right = 240.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_bottom = 200.0f + m_y + m_scroll_map_y - 34.0f;
	}
	if (m_r==-90)
	{

		//�o�͈ʒu
		dst.m_top = -50.0f + m_y + m_scroll_map_y - 40.0f;
		dst.m_left = -100.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_right = 200.0f + m_x + m_scroll_map_x - 35.0f;
		dst.m_bottom = 250.0f + m_y + m_scroll_map_y - 34.0f;
	}
	Draw::Draw(5, &src, &dst, c, m_r);
}