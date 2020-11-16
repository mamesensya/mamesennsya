#include"GameL\DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL\SceneManager.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"CObjEnemy3.h"

using namespace GameL;

CObjEnemy3::CObjEnemy3(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjEnemy3::Init()
{
	m_vx = 0.0f;    //�ړ�����
	m_vy = 0.0f;
	m_r = 0.0f;//���������߂�ϐ�
	m_hp = 5;//�̗�
	count = 0;//�������Œ肷��J�E���g
	m_time = 0;//�e�۔��ː���ptime
	m_move_time = 0;//�ړ��d���ptime

	pbullet_interval = 0; //�ђʒe�q�b�g�̊Ԋu
	pbullet_enable = false; //�ђʒe�_���[�W�L��

	//HitBox�ǉ�
	Hits::SetHitBox(this, m_x , m_y , 55, 55, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

void CObjEnemy3::Action()
{

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	m_time++;
	if (m_time > 100)
	{
		m_time = 0;

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

		//�G�����l���̃x�N�g�������߂�
		x = m_x - hx+m_scroll_map_x;
		y = m_y - hy+m_scroll_map_y;



		if ((x >= -400.0f && x <= 400.0f) || (y >= -400.0f && y <= 400.0f))
		{

			//(-x,-y)�̎�
			if (x <= 0.0f && y <= 0.0f)
			{
				if (x > y)
				{
					if (x >= -20.0f && count == 0)
					{
						//x�����قڐ���
						m_r = 180.0f;
						m_vy = +0.1;
						count = 1;
					}
					if (x < -20.0f && m_move_time == 0)
					{
						//x���̕����߂��@
						m_r = -90.0f;
						m_vx = 0.7f;
					}
				}
				if (x < y)
				{
					if (y >= -20.0f && count == 0)
					{
						//y�����قڕ��s
						m_r = -90.0f;
						m_vx = 0.1f;
						count = 1;
					}
					if (y < -20.0f && m_move_time == 0)
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
					if (x <= 20.0f && count == 0)
					{
						//x�����قڐ���
						m_r = 0.0f;
						m_vy = -0.1f;
						count = 1;
					}
					if (x > 20.0f && m_move_time == 0)
					{
						//x���̕����߂�
						m_r = 90.0f;
						m_vx = -0.7f;
					}
				}
				if (x > y)
				{
					if (y <= 20.0f && count == 0)
					{
						//y�����قڕ��s
						m_r = 90.0f;
						m_vx = -0.1f;
						count = 1;
					}
					if (y > 20.0f && m_move_time == 0)
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
					if (x <= 20.0f && count == 0)
					{
						//x�����قڐ���
						m_r = 180.0f;
						m_vy = -0.1f;
						count = 1;
					}
					if (x > 20.0f && m_move_time == 0)
					{
						//x���̕����߂�
						m_r = 90.0f;
						m_vx = -0.7f;
					}
				}
				if (x > py)
				{
					if (y >= -20.0f && count == 0)
					{
						//y�����قڕ��s
						m_r = 90.0f;
						m_vx = -0.1f;
						count = 1;
					}
					if (y < -20.0f && m_move_time == 0)
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
					if (x >= -20.0f && count == 0)
					{
						//x�����قڐ���
						m_r = 0.0f;
						m_vy = -0.1;
						count = 1;
					}
					if (x < -20.0f && m_move_time == 0)
					{
						//x���̕����߂��@
						m_r = -90.0f;
						m_vx = 0.7f;
					}
				}
				if (px > y)
				{
					if (y <= 20.0f && count == 0)
					{
						//y�����قڕ��s
						m_r = -90.0f;
						m_vx = 0.1f;
						count = 1;
					}
					if (y > 20.0f && m_move_time == 0)
					{
						//y���̕����߂�
						m_r = 0.0f;
						m_vy = -0.7f;
					}
				}
			}


			if (m_time == 100 && count == 1)
			{
				//�G�e�۔���
				for (int i = 0; i < 3; i++) {
					CObjEnemy3B* obj_eb = new CObjEnemy3B(m_x+m_scroll_map_x , m_y+m_scroll_map_y, m_r - (m_r * 2) - (60 + (30 * i)));
					Objs::InsertObj(obj_eb, OBJ_ENEMY_3BULLET, 16);
				}
			}


		}
	}

	m_x += m_scroll_map_x;
	m_y += m_scroll_map_y;

	//�u���b�N�Ƃ̓����蔻��
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_x, &m_y, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy);


	m_x -= m_scroll_map_x;
	m_y -= m_scroll_map_y;


	m_x += m_vx;
	m_y += m_vy;


	//HitBox�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);

	//�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET) != nullptr)
	{
		m_hp--;
		if (m_hp <= 0) {
			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//�e�ۂ����L����HitBox�ɍ폜����B
		}
	}
	if (pbullet_enable == false) {
		if (hit->CheckObjNameHit(OBJ_PENETRATE_BULLET) != nullptr) {
			m_hp--;
			pbullet_enable = true;
			if (m_hp <= 0) {
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

void CObjEnemy3::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 400.0f;

	//�o�͈ʒu
	dst.m_top = 0.0f + m_y+m_scroll_map_y-40;
	dst.m_left = 0.0f + m_x+ m_scroll_map_x-35;
	dst.m_right = 128.0f + m_x+ m_scroll_map_x-35;
	dst.m_bottom = 128.0f + m_y+m_scroll_map_y-40;

	Draw::Draw(1, &src, &dst, c, m_r);
}