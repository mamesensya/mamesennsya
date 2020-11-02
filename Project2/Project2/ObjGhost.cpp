//�g�p�w�b�_�[�ӂ�����
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"ObjGhost.h"

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

	//�����蔻��
	Hits::SetHitBox(this, m_x+5, m_y+5, 30, 30, ELEMENT_ENEMY, OBJ_GHOST, 4);

}

void CObjGhost::Action()
{
	//�x�N�g�������߂�
	float x = 0;
	float y = 0;

	//��l���̍��W�擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (hero != nullptr)
	{
		float hx = hero->GetX();
		float hy = hero->GetY();

		x = m_x - hx;
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
		m_vx *= 5.0f;
		m_vy *= 5.0f;

		//��l���ɐڋ߂�����Î~(�ߐڊi���͌�Ɏ���)
		if ((x >= -30.0f && x <= 80.0f) && (y >= -30.0f && y <= 80.0f))
		{
			m_vx = 0.0f;
			m_vy = 0.0f;

			if ((x >= -30.0f && x <= 80.0f) && (y >= -30.0f && y <= 80.0f) > (x >= -29.9f && x <= 79.9f) && (y >= -29.9f && y <= 79.9f))
			{
				m_vx *= -1.0f;
				m_vy *= -1.0f;

				/*for (; m_time < 80; m_time++)
				{

				}*/
			}
		}

		if ((x >= -400.0f && x <= 400.0f) || (y >= -400.0f && y <= 400.0f))
		{
			m_x += m_vx;
			m_y += m_vy;


		}

		

	}

	//�ړ�����
	m_vx = 0.0f;
	m_vy = 0.0f;



	//���e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+5, m_y+5);

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
	dst.m_left = 0.0f +m_x;
	dst.m_right = 45.0f+m_x;
	dst.m_bottom = 45.0f+m_y;

	//�`��
	Draw::Draw(4, &src, &dst, c,0.0f);
}