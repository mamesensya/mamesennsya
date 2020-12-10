#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameHead.h"
#include"CObjEnemyBullet.h"

using namespace GameL;

CObjEnemyBullet::CObjEnemyBullet(float x, float y,float r)
{
	m_x = x+10;
	m_y = y+10;
	m_r = r;
}

//�C�j�V�����C�Y
void CObjEnemyBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	mx = 0;
	my = 0;

	//�X�N���[���������̃x�N�g�����擾
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	//HitBox�쐬
	Hits::SetHitBox(this, m_x+m_scroll_map_x, m_y+m_scroll_map_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//�A�N�V����
void CObjEnemyBullet::Action()
{

	CHitBox* hit = Hits::GetHitBox(this);

	CObjEnemy* bb = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	////�G�̍��W�擾
	//float Bx = bb->GetX();
	//float By = bb->GetY();

	//�X�N���[���������̃x�N�g�����擾
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();




	//�ړ��x�N�g��
	if (m_r == 0.0f)
	{
		m_vy = -1.5f;
		m_vx = 0.0f;
	}
	else if (m_r == 90.0f)
	{
		m_vx = -1.5f;
		m_vy = 0.0f;
	}
	else if (m_r == 180.0f)
	{
		m_vy = +1.5f;
		m_vx = 0.0f;
	}
	else if (m_r == -90.0f)
	{
		m_vx = +1.5f;
		m_vy = 0.0f;
	}

	//�ړ��x�N�g�������W�ɒǉ�
	m_x += m_vx;
	m_y += m_vy;

	//��苗�������ƒe���폜����ϐ��Ƀx�N�g���ǉ�
	mx += m_vx;
	my += m_vy;

	//HitBox�̓��e���X�V
	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);

	m_x += m_scroll_map_x;
	m_y += m_scroll_map_y;

	//�u���b�N�ƒe�̓����蔻��@�֐��ɒl��n��
	CObjBlock* bbh = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	bbh->BlockHit(&m_x, &m_y, &m_up, &m_down, &m_reft, &m_right, &m_vx, &m_vy);

	m_x -= m_scroll_map_x;
	m_y -= m_scroll_map_y;

	//��r����f�[�^�z��
	int data_base[4] =
	{
		m_up,m_down,m_reft,m_right
	};

	//for���ŉ񂵂Ă��ׂĊm�F�@��ł�true�Ȃ�e���폜
	for (int i = 0; i <= 3; i++)
	{
		if (data_base[i] == true)
		{
			Effect* effect = new Effect(m_x, m_y,m_r);
			Objs::InsertObj(effect, OBJ_EFFECT, 20);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}


	//��l���ƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		Effect* effect = new Effect(m_x, m_y,m_r);
		Objs::InsertObj(effect, OBJ_EFFECT, 20);

		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜
	}
	//��l���i�l�j�ƐڐG���Ă��邩���ׂ�
	if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		Effect* effect = new Effect(m_x, m_y,m_r);
		Objs::InsertObj(effect, OBJ_EFFECT, 20);

		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜
	}
	////�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	//if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	//{
	//	this->SetStatus(false);//���g�ɍ폜���߂��o��
	//	Hits::DeleteHitBox(this);//�e�ۂ����L����HitBox�ɍ폜����B
	//}

	if (mx >= 500.0f||mx<=-500.0f || my >= 500.0f||my<=-500.0f)
	{
		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜
	}

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
	dst.m_top = 0.0f+m_y+m_scroll_map_y;
	dst.m_left = 0.0f +m_x+m_scroll_map_x ;
	dst.m_right = 32.0f+m_x +m_scroll_map_x;
    dst.m_bottom = 32.0f+m_y+m_scroll_map_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}