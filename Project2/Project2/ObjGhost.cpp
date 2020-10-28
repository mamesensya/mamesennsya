//�g�p�w�b�_�[�ӂ�����
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"ObjGhost.h"

//�l�[���X�y�[�X
using namespace GameL;

//CObjGhost::CObjGhost(float x, float y)
//{
//	m_x = x;
//	m_y = y;
//}

void CObjGhost::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_GHOST, 4);

}

void CObjGhost::Action()
{
	//�ړ�����
	m_vx = -1.0f;
	m_vy = 0.0f;

	//�x�N�g���̒��������߂�
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);

	if (r == 0.0f)//0�Ȃ牽�����Ȃ�
		;

	else 
	{
		m_vx = 1.0f / r * m_vx;//���K�����s��
		m_vy = 1.0f / r * m_vy;
	}

	//���x
	m_vx *= 1.0f;
	m_vy *= 1.0f;

	//�x�N�g�������W���Z
	m_x += m_vx;
	m_y += m_vy;

	//���e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���ƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
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
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 45.0f;
	dst.m_bottom = 45.0f;

	//�`��
	Draw::Draw(4, &src, &dst, c,0.0f);
}