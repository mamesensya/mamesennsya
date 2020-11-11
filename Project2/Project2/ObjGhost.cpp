//�g�p�w�b�_�[�ӂ�����
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"ObjGhost.h"
#include"OBJGhostAttack.h"

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
	m_scroll_map = 0;

	//�����蔻��
	Hits::SetHitBox(this, m_x+5, m_y+5, 30, 30, ELEMENT_ENEMY, OBJ_GHOST, 4);

}

void CObjGhost::Action()
{

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map = block->GetS();

	if (m_time == 50) {
		m_time = 0;
	}

	if (n ==50.0f)
	{
		n = 0.0f;
	}

	if (c == 350)
	{
		c = 0;
	}
	c++;

	//���e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + 5+m_scroll_map, m_y + 5);


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
		x = m_x - hx + m_scroll_map;
		y = m_y - hy;

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

		//�S�Ǝ�l���Ŋp�x���
		CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
		
		//��l�������݂��Ă���ꍇ�p�x�v�Z
		if (obj != nullptr)
		{
			float sx = obj->GetX() - m_x;
			float sy = obj->GetY() - m_y;
			float ar = atan2(-sy, sx) * 180.0f / 3.14f;

			if (ar < 0)
				ar = 360 - abs(ar);

			//���݌����Ă�������Ŋp�x���
			float br = atan2(-m_vy, m_vx) * 180.0f / 3.14f;

			if (br < 0)
				br = 360 - abs(br);

			//�������ꂽ��ړ���������l���ɂ���
			if (ar - br > 20)
			{
				m_vx = cos(3.14 / 180 * ar);
				m_vy = cos(3.14 / 180 * ar);
			}

			r = 3.14 / 180.0f;//�p�x1
			if (ar < br)//�ړ�������+1
			{
				m_vx = m_vx * cos(r) - m_vy * sin(r);
				m_vy = m_vy * cos(r) - m_vx * sin(r);
			}
			else//�ړ�������-1
			{
				m_vx = m_vx * cos(-r) - m_vy * sin(-r);
				m_vy = m_vy * cos(-r) - m_vy * sin(-r);
			}
			
		}


		m_vx *= 1.5f;
		m_vy *= 1.5f;

		if ((x >= -400.0f && x <= 400.0f) || (y >= -400.0f && y <= 400.0f))
		{
			//���߂Â��Ă����瓦����
			if ((x >= -(25.0f + distance) && x <= 75.0f + distance) && (y >= -(25.0f + distance) && y <= 75.0f + distance)||m_time!=0)
			{
				//�x�N�g����^�t�ɂ���
				m_vx = m_vx - m_vx - m_vx;
				m_vy = m_vy - m_vy - m_vy;
				if (m_time < 50) {
					m_x += m_vx;
					m_y += m_vy;
					m_time++;
				}
			}
			//��l���ɐڋ߂�����Î~
			else if ((x >= -(30.0f + distance) && x <= 80.0f + distance) && (y >= -(30.0f + distance) && y <= 80.0f + distance)||n!=0)
			{
				n+=1.0f;
				if (n != 0.0f||100 < c < 350)//�U����b���d��(��������)
				{
					m_x += m_vx*0;
					m_y += m_vy*0;
					

				}

				if (c == 100)
				{
					CObjGhostAttack* objAttack = new CObjGhostAttack(m_x, m_y);
					Objs::InsertObj(objAttack, OBJ_GHOST_ATTACK, 6);

				}
			}

			if (m_time == 0) 
			{
				if (n == 0.0f)
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
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
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
	dst.m_top = 0.0f +m_y;
	dst.m_left = 0.0f + m_x + m_scroll_map;
	dst.m_right = 45.0f + m_x + m_scroll_map;
	dst.m_bottom = 45.0f+m_y;

	//�`��
	Draw::Draw(4, &src, &dst, c,0.0f);
}