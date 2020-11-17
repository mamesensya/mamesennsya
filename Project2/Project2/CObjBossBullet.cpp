#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameHead.h"
#include"CObjBossBullet.h"

using namespace GameL;

CObjBossBullet::CObjBossBullet(float x, float y,float r)
{
	m_x = x + 85;
	m_y = y + 85;
	m_r = r;
}

//�C�j�V�����C�Y
void CObjBossBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;


	//HitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//�A�N�V����
void CObjBossBullet::Action()
{

	CHitBox* Hit = Hits::GetHitBox(this);


	m_vx = cos(3.14 / 180.0f * m_r);
	m_vy = sin(3.14 / 180.0f * m_r);



	m_x += m_vx * m_speed;
	m_y += m_vy * m_speed;

	mx += m_vx * m_speed;
	my += m_vy * m_speed;


	Hit->SetPos(m_x, m_y);

	if (Hit->CheckObjNameHit(OBJ_HERO) != nullptr) {
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//��l���i�l�j�ƐڐG���Ă��邩���ׂ�
	if (Hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜
	}


	if (mx >= 1000.0f || mx <= -1000.0f || my >= 1000.0f || my <= -1000.0f)
	{
		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜
	}

	
	////if (m_r == 0.0f)
	////{
	////	m_vy = -5.0f;
	////	m_vx = 0.0f;
	////}
	////else if (m_r == 90.0f)
	////{
	////	m_vx = -5.0f;
	////	m_vy = 0.0f;
	////}
	////else if (m_r == 180.0f)
	////{
	////	m_vy = +5.0f;
	////	m_vx = 0.0f;
	////}
	////else if (m_r == -90.0f)
	////{
	////	m_vx = +5.0f;
	////	m_vy = 0.0f;
	////}


	////m_x += m_vx;
	////m_y += m_vy;


	//////HitBox�̓��e���X�V
	////CHitBox* hit = Hits::GetHitBox(this);
	////hit->SetPos(m_x + m_scroll_map_x, m_y+m_scroll_map_y);

	//////��l���ƐڐG���Ă��邩�ǂ������ׂ�
	////if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	////{
	////	this->SetStatus(false);//�폜����
	////	Hits::DeleteHitBox(this);//�폜
	////}
	//////��l���i�l�j�ƐڐG���Ă��邩���ׂ�
	////if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	////{
	////	this->SetStatus(false);//�폜����
	////	Hits::DeleteHitBox(this);//�폜
	////}
	////////�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	//////if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	//////{
	//////	this->SetStatus(false);//���g�ɍ폜���߂��o��
	//////	Hits::DeleteHitBox(this);//�e�ۂ����L����HitBox�ɍ폜����B
	//////}

	//////if (mx >= 1000.0f || mx <= -1000.0f || my >= 1000.0f || my <= -1000.0f)
	//////{
	//////	this->SetStatus(false);//�폜����
	//////	Hits::DeleteHitBox(this);//�폜
	//////}

}

//�h���[
void CObjBossBullet::Draw()
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
	dst.m_top = 0.0f + m_y+m_scroll_map_y;
	dst.m_left = 0.0f + m_x + m_scroll_map_x;
	dst.m_right = 32.0f + m_x + m_scroll_map_x;
	dst.m_bottom = 32.0f + m_y+m_scroll_map_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}