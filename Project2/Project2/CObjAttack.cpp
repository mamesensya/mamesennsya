#include "GameL\HitBoxManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "CObjAttack.h"

using namespace GameL;

//�R���X�g���N�^
CObjAttack::CObjAttack(float x,float y,float r)
{
	m_x = x;
	m_y = y;
	m_r = r;
}

//�C�j�V�����C�Y
void CObjAttack::Init()
{

	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_CHARA, OBJ_ATTACK, 1);
}

//�A�N�V����
void CObjAttack::Action()
{
	CHitBox* Hit = Hits::GetHitBox(this);

	//��l���������Ă�������ɂ���čU���̌�����ς���
	if (m_r == 0.0f)
	{
		//HitBox�̈ʒu�X�V
		Hit->SetPos(m_x, m_y - 25.0f);
	}
	else if (m_r == 90.0f)
	{
		//HitBox�̈ʒu�X�V
		Hit->SetPos(m_x - 25.0f, m_y);
	}
	else if (m_r == 180.0f)
	{
		//HitBox�̈ʒu�X�V
		Hit->SetPos(m_x, m_y + 25.0f);
	}
	else if (m_r == 270.0f)
	{
		//HitBox�̈ʒu�X�V
		Hit->SetPos(m_x + 25.0f, m_y);
	}
	//��l���̍U���Ԋu����
	m_time++;
	if (m_time == 10)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		m_time = 0;
	}
}

//�h���[
void CObjAttack::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;
	
	//�����Ă���p�x�ɂ���ĕ\���̈ʒu�����炷
	if (m_r == 0.0f)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y - 25.0f;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 32.0f + 16.0f + m_x;
		dst.m_bottom = 32.0f + 16.0f + m_y - 25.0f;
	}
	else if (m_r == 90.0f)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x-25.0f;
		dst.m_right = 32.0f + 16.0f + m_x-25.0f;
		dst.m_bottom = 32.0f + 16.0f + m_y;
	}
	else if (m_r == 180.0f)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y+25.0f;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 32.0f + 16.0f + m_x;
		dst.m_bottom = 32.0f + 16.0f + m_y+25.0f;
	}
	else if (m_r == 270.0f)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x+25.0f;
		dst.m_right = 32.0f + 16.0f + m_x+25.0f;
		dst.m_bottom = 32.0f + 16.0f + m_y;
	}
	////�\���ʒu�̐ݒ�
	//dst.m_top = 0.0f + m_y;
	//dst.m_left = 0.0f + m_x;
	//dst.m_right = 32.0f + 16.0f + m_x;
	//dst.m_bottom = 32.0f + 16.0f + m_y;

	//�`��
	Draw::Draw(8, &src, &dst, c, m_r);


}