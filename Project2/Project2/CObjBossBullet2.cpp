#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameHead.h"
#include"CObjBossBullet2.h"

using namespace GameL;

CObjBossBullet2::CObjBossBullet2(float x, float y, float r)
{
	m_x = x + 85;
	m_y = y + 85;
	m_r = r;
}

//�C�j�V�����C�Y
void CObjBossBullet2::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;


	//HitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 100, 100, ELEMENT_ENEMY, OBJ_BOSS_BULLET2, 1);
}

//�A�N�V����
void CObjBossBullet2::Action()
{

	CHitBox* Hit = Hits::GetHitBox(this);


	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	m_vx = cos(3.14 / 180.0f * m_r);
	m_vy = sin(3.14 / 180.0f * m_r);



	m_x += m_vx * m_speed;
	m_y += m_vy * m_speed;

	mx += m_vx * m_speed;
	my += m_vy * m_speed;


	Hit->SetPos(m_x+m_scroll_map_x, m_y+m_scroll_map_y);

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
}

//�h���[
void CObjBossBullet2::Draw()
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
	dst.m_top = -10.0f + m_y + m_scroll_map_y;
	dst.m_left = -10.0f + m_x + m_scroll_map_x;
	dst.m_right = 110.0f + m_x + m_scroll_map_x;
	dst.m_bottom = 110.0f + m_y + m_scroll_map_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}