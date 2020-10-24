#include"GameL\DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameL\SceneManager.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"Enemy.h"

using namespace GameL;

CObjEnemy::CObjEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjEnemy::Init()
{
	m_vx = 0.0f;    //�ړ�����
	m_vy = 0.0f;
	m_r=0.0f;//���������߂�ϐ�
	m_hp=20;//�̗�
	count = 0;//�������Œ肷��J�E���g
	m_time = 0;
	m_move_time = 0;

	//HitBox�ǉ�
	Hits::SetHitBox(this, m_x+35, m_y+40, 55, 55, ELEMENT_ENEMY, OBJ_ENEMY,1 );
}

void CObjEnemy::Action()
{

	//if (m_vx <= 20 || m_vx >= -20 || m_vy <= 20 || m_vy >= -20) {
	//	m_time++;
	//	if (m_time > 200)
	//	{
	//		m_time = 0;
	//		//�e�۔���
	//		CObjBulletEnemy* obj_b = new CObjBulletEnemy(m_x, m_y);//�e�ۃI�u�W�F�N�g�쐬
	//		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 1);
	//	}
	//}

	//������x�߂Â��Ǝ�l���ƕ��s�Ȉʒu�܂ňړ�
	m_vx = 0.0f;
	m_vy = 0.0f;
	float x = 0;
	float y = 0;

	//��l���̍��W�擾
	CObjHero* hero=(CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
	
	//�G�����l���̃x�N�g�������߂�
	x = m_x - hx;
	y = m_y - hy;
	

	//  300=300-0;
	//  500=500-0;

	//���_

	//���W�擾���Ĕ�r����Ƃ�
	//�}�C�i�X�ƃv���X�̏ꍇ�ȂǂɑΉ����Ă��Ȃ�


	//(-x,-y)�̎�
	if (x <= 0.0f && y <= 0.0f)
	{
		if (x < y)
		{
			if (x >= -50.0f&&count==0)
			{
				//x�����قڕ��s
				m_r = -90.0f;
				m_vx = +0.1f;
				count = 1;
			}
			if (x < -50.0f)
			{
				//x���̕����߂��@
				m_r = 180.0f;
				m_vy = 1.0f;
				count = 0;
			}
		}
		if (x > y)
		{
			if (y >= -50.0f&&count==0)
			{
				//y�����قڐ���
				m_r = 0.0f;
				m_vy = -0.1f;
				count = 1;
			}
			if (y < -50.0f)
			{
				//y���̕����߂�
				m_r = -90.0f;
				m_vx = 1.0f;
				count = 0;
			}
		}
	}
	//(x,y)�̎�
	if (x >= 0.0f && y >= 0.0f)
	{
		if (x < y)
		{
			if (x <= 50.0f&&count==0)
			{
				//x�����قڕ��s
				m_r = 90.0f;
				m_vx = -0.1f;
				count = 1;
			}
			if (x > 50.0f)
			{
				//x���̕����߂�
				m_r = 0.0f;
				m_vy = -1.0f;
				count = 0;
			}
		}
		if (x > y)
		{
			if (y <= 20.0f&&count==0)
			{
				//y�����قڐ���
				m_r = 0.0f;
				m_vy = -0.1f;
				count = 1;
			}
			if (y > 20.0f)
			{
				//y���̕����߂�
				m_r = 90.0f;
				m_vx = -1.0f;
				count = 0;
			}
		}
	}
	//(x,-y)�̏ꍇ
	if (x >= 0.0f && y <= 0.0f)
	{

	}
	if (x <= 0.0f && y >= 0.0f)
	{

	}
	//(-x,y)�̏ꍇ
	if (x<=0.0f&&y>=0.0f)
	{

	}
	if (x<=0.0f&&y>=0.0f)
	{

	}


	//X����Y���������ꍇ
    //X���̕����߂��ꍇ
	//////////if (((x<=-21) > (y<21)) ||((x>=21)<(y>=21))) {
	//////////	count = 0;
	//////////	if (x > 20.0f) {
	//////////		m_r = 90.0f;
	//////////		m_vx = -1.0f;
	//////////	}
	//////////	else if (x < -20.0f) {
	//////////		m_r = 270.0f;
	//////////		m_vx = +1.0f;
	//////////	}
	//////////}

	////////////X�����قڐ^���̏ꍇ
	//////////else if (x <= 20 && x >= -20 && count == 0) {
	//////////	if (y <= -50) {
	//////////		m_r = 180.0f;
	//////////		m_vy = +0.1f;
	//////////		count = 1;
	//////////	}
	//////////	if (y >= 50) {
	//////////		m_r = 0.0f;
	//////////		m_vy = -0.1f;
	//////////		count = 1;

	//////////	}
	//////////}

	////////////Y���̕����߂��ꍇ
	//////////if (((y <= -21) > (x < -21)) || ((y >= 21) < (x >= 21)) || x == y) {
	//////////	if (y > 20.0f) {
	//////////		count = 0;
	//////////		m_r = 0.0f;
	//////////		m_vy = -1.0f;
	//////////	}
	//////////	else if (y < -20.0f) {
	//////////		m_r = 180.0f;
	//////////		m_vy = +1.0f;
	//////////	}
	//////////}

	////////////Y�����قڐ^���̏ꍇ
	//////////else if (y <= 20 && y >= -20 && count == 0) {
	//////////	if (x <= -50) {
	//////////		m_r = -90.0f;
	//////////		m_vx = +0.1f;
	//////////		count = 1;
	//////////	}
	//////////	if (x >= 50) {
	//////////		m_r = 90.0f;
	//////////		m_vx = -0.1f;
	//////////		count = 1;
	//////////	}
	//////////}
	


	m_x += m_vx;
	m_y += m_vy;


	//HitBox�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+35, m_y+40);

	////�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	//if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	//{
	//	this->SetStatus(false);//���g�ɍ폜���߂��o��
	//	Hits::DeleteHitBox(this);//�e�ۂ����L����HitBox�ɍ폜����B
	//}
	m_vx = 0;
	m_vy = 0;
}

void CObjEnemy::Draw()
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
	dst.m_top = 0.0f+m_y;
	dst.m_left =0.0f+m_x;
	dst.m_right =128.0f+m_x;
	dst.m_bottom =128.0f+m_y;

	Draw::Draw(1, &src, &dst, c, m_r);
}