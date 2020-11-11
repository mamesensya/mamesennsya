//�g�p�w�b�_�[�ӂ�����
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"OBJGhostAttack.h"


CObjGhostAttack::CObjGhostAttack(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjGhostAttack::Init()
{
	m_scroll_map = 0;
	Hits::SetHitBox(this, m_x+10, m_y+30 , 10, 30, ELEMENT_ENEMY, OBJ_GHOST_ATTACK, 6);
}

void CObjGhostAttack::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map = block->GetS();

	m_time ++ ;
	if (m_time == 50)
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
	
	hit->SetPos(m_x +10+ m_scroll_map, m_y +30);
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
	dst.m_top = 35.0f + m_y;
	dst.m_left = 0.0f + m_x+m_scroll_map;
	dst.m_right = 30.0f + m_x+m_scroll_map;
	dst.m_bottom = 30.0f + m_y+30;

	//�`��
	Draw::Draw(6, &src, &dst, c, 0.0f);
}