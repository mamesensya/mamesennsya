#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameHead.h"
#include"CObjEnemyBullet.h"

using namespace GameL;


//�V�[�����C���ňʒu�ύX�\
CObjEnemyBullet::CObjEnemyBullet(float x, float y)
{
	m_x = x;//���W��
	m_y = y;//���W��
}

//�C�j�V�����C�Y
void CObjEnemyBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//HitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//�A�N�V����
void CObjEnemyBullet::Action()
{




	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���ƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜
	}

	////�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	//if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	//{
	//	this->SetStatus(false);//���g�ɍ폜���߂��o��
	//	Hits::DeleteHitBox(this);//�e�ۂ����L����HitBox�ɍ폜����B
	//}

}

//�h���[
void CObjEnemyBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	//�\���ʒu
	dst.m_top = 0.0f+m_y;
	dst.m_left = 0.0f+m_x;
	dst.m_right = 32.0f+m_x;
    dst.m_bottom = 32.0f+m_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}