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
	m_r += 90;

	if (m_r >= 360.0f)
		m_r -= 360.0f;
	if (m_r <= 0)
		m_r += 360.0f;
	

	if ((m_r <= 22.5)&&(m_r>0.0) || (m_r>337.5)&&(m_r<360.0))
	{
		m_x += 30;
	}
	if (m_r <= 67.5 && m_r>22.5)
	{
		m_x += 20;
		m_y -= 20;
	}
	else if (m_r <= 112.5&& m_r > 67.5)
	{
		m_y -= 30;
	}
	else if (m_r <= 157.5 && m_r > 112.5)
	{
		m_y -= 20;
		m_x -= 20;
	}
	else if (m_r <= 202.5 && m_r > 157.5)
	{
		m_x -= 30;
	}
	else if (m_r <=247.5 && m_r >202.5)
	{
		m_x -= 20;
		m_y += 20;
	}
	else if (m_r <=292.5 && m_r > 247.5)
	{
		m_y += 30;
	}
	else if (m_r <=337.5 && m_r > 292.5)
	{
		m_x += 20;
		m_y += 20;
	}



	Hits::SetHitBox(this, m_x, m_y , 25, 25, ELEMENT_ENEMY, OBJ_GHOST_ATTACK, 6);
}

void CObjGhostAttack::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	//CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//m_scroll_map_x = block->GetSX();
	//m_scroll_map_y = block->GetSY();



	


	m_time ++ ;
	if (m_time == 20)
	{
		//���e�X�V
		
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);//��l���ɓ���������j��
			Hits::DeleteHitBox(this);

			Effect* effect = new Effect(m_x, m_y, m_r);
			Objs::InsertObj(effect, OBJ_EFFECT, 20);
		}

		this->SetStatus(false);//��莞�Ԍo�߂����炢������j��
		Hits::DeleteHitBox(this);
		m_time = 0;
		
	}
	
	hit->SetPos(m_x, m_y);


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
	dst.m_top = 30.0f+m_y-30;
	dst.m_left = 0.0f+m_x;
	dst.m_right = 30.0f+m_x;
	dst.m_bottom = 60.0f+m_y-30;

	//�`��
	Draw::Draw(6, &src, &dst, c, m_r);
}