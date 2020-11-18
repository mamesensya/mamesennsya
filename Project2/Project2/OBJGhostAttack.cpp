//�g�p�w�b�_�[�ӂ�����
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"OBJGhostAttack.h"


CObjGhostAttack::CObjGhostAttack(float x, float y,float r)
{
	
	m_x = x;
	m_y = y;
	m_r = r;
	
	
}

void CObjGhostAttack::Init()
{

	Hits::SetHitBox(this, m_x, m_y , 25, 25, ELEMENT_ENEMY, OBJ_GHOST_ATTACK, 6);
}

void CObjGhostAttack::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();



	if ((m_r < 45 && m_r>0) || m_r > 315)
	{
		m_x = m_x + 30;
	}
	if (m_r > 45 && m_r < 135)
	{
		m_y = m_y - 30;
	}
	if (m_r > 135 && m_r < 225)
	{
		m_x = m_x - 30;
	}
	if (m_r > 225 && m_r < 315)
	{
		m_y = m_y + 30;
	}


	m_time ++ ;
	if (m_time == 20)
	{
		//���e�X�V
		
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);//��l���ɓ���������j��
			Hits::DeleteHitBox(this);
		}

		this->SetStatus(false);//��莞�Ԍo�߂����炢������j��
		Hits::DeleteHitBox(this);
		m_time = 0;
		
	}
	
	hit->SetPos(m_x + m_scroll_map_x, m_y +m_scroll_map_y);

	if ((m_r < 45 && m_r>0) || m_r > 315)
	{
		m_x = m_x - 30;
	}
	if (m_r > 45 && m_r < 135)
	{
		m_y = m_y + 30;
	}
	if (m_r > 135 && m_r < 225)
	{
		m_x = m_x + 30;
	}
	if (m_r > 225 && m_r < 315)
	{
		m_y = m_y - 30;
	}
}

void CObjGhostAttack::Draw()
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
	dst.m_top = 35.0f + m_y+m_scroll_map_y-30;
	dst.m_left = 0.0f + m_x+m_scroll_map_x;
	dst.m_right = 30.0f + m_x+m_scroll_map_x;
	dst.m_bottom = 30.0f + m_y+30+m_scroll_map_y-30;

	//�`��
	Draw::Draw(6, &src, &dst, c, m_r);
}