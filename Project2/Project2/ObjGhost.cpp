//�g�p�w�b�_�[�ӂ�����
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"ObjGhost.h"
#include"OBJGhostAttack.h"
#include"Objbreakblock.h"

//�l�[���X�y�[�X
using namespace GameL;

CObjGhost::CObjGhost(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjGhost::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_r = 0.0f;



	//�����蔻��
	Hits::SetHitBox(this, m_x, m_y, 30, 30, ELEMENT_ENEMY, OBJ_GHOST, 4);

}

/// <summary>
/// �S���d�Ȃ�Ȃ��悤�ɂ�����
/// ���̏ꍇ
/// �����蔻��������Ă���
/// </summary>

void CObjGhost::Action()
{

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();


	if (m_time == 50) {
		m_time = 0;
	}

	if (n == 200.0f)
	{
		n = 0.0f;
	}

	if (c == 350)
	{
		c = 0;
	}



	m_x += m_scroll_map_x;
	m_y += m_scroll_map_y;


	//�u���b�N�Ƃ̓����蔻��
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_x, &m_y, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy);

	m_x -= m_scroll_map_x;
	m_y -= m_scroll_map_y;



	//���e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);


	//�x�N�g�������߂�
	float x = 0;
	float y = 0;

	//��l���̍��W�擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (hero != nullptr)
	{
		float hx = hero->GetX();
		float hy = hero->GetY();
		float distance = 50.0f;

		//�G�����l���̃x�N�g�������߂�
		x = m_x - hx + m_scroll_map_x;
		y = m_y - hy + m_scroll_map_y;


		


		//�x�N�g���̒��������߂�
		float r = 0.0f;
		r = x * x + y * y;
		r = sqrt(r);

		


		if (r == 0.0f)//0�Ȃ牽�����Ȃ�
			;

		else
		{
			m_vx = -1.0f / r * x;//���K�����s��
			m_vy = -1.0f / r * y;
		}
		m_r = atan2(x, y) * 180.0f / 3.14f;

		if (m_r < 0)
			m_r = 360 - abs(m_r);


		m_vx *= 1.5f;
		m_vy *= 1.5f;

		

		if ((x >= -400.0f && x <= 400.0f) || (y >= -400.0f && y <= 400.0f))
		{

			float sw = 0.0;

			if (hit->CheckObjNameHit(OBJ_GHOST) != nullptr)
			{

				sw = m_vx;
				m_vx = m_vy;
				sw = m_vy;

			}
			//���߂Â��Ă����瓦����

			else if ((x >= -35.0f) && x <= 70.0f  && (y >= -35.0f) && y <= 70.0f || m_time != 0)
			{
				//�x�N�g����^�t�ɂ���
				m_vx = m_vx - m_vx - m_vx;
				m_vy = m_vy - m_vy - m_vy;
				m_r = m_r - m_r - m_r;
				if (m_time < 50) {
					m_x += m_vx;
					m_y += m_vy;
					m_time++;
				}
				

			}
			//��l���ɐڋ߂�����Î~
			else if ((x >= -50.0f  && x <= 90.0) && (y >= -50.0f) && y <= 90.0f  || n != 0)
			{

				n += 1.0f;
				if (n == 100.0)
				{
					if (m_time == 0) {
						//�U������
						CObjGhostAttack* objAttack = new CObjGhostAttack(m_x + m_scroll_map_x, m_y + m_scroll_map_y, m_r);
						Objs::InsertObj(objAttack, OBJ_GHOST_ATTACK, 6);

					}
				}
			}
			
			if (m_time == 0||sw!=0.0)
			{
				if (n == 0.0f||sw!=0.0)
				{
					m_x += m_vx;
					m_y += m_vy;
				}
			}

		}
	}
	//�ړ�����������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//��l���e�ƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		Effect* effect = new Effect(m_x, m_y);
		Objs::InsertObj(effect, OBJ_EFFECT, 20);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjbreakblock* Bblock = (CObjbreakblock*)Objs::GetObj(OBJ_BREAK_BLOCK);
		Bblock->Enemycount--;
		CObjBoss* Boss = (CObjBoss*)Objs::GetObj(OBJ_BOSS);
		Boss->m_oni_count--;
	}
	
}

void CObjGhost::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y + m_scroll_map_y - 5.0f;
	dst.m_left = 0.0f + m_x + m_scroll_map_x - 5.0f;
	dst.m_right = 45.0f + m_x + m_scroll_map_x - 5.0f;
	dst.m_bottom = 45.0f + m_y + m_scroll_map_y - 5.0f;

	//�`��
	Draw::Draw(4, &src, &dst, c, m_r);
}