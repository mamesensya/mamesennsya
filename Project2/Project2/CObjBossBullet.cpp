#include"GameL/DrawTexture.h"
#include"GameL/HitBoxManager.h"
#include"GameHead.h"
#include"CObjBossBullet.h"
#include"CObjAngleBullet.h"

using namespace GameL;

CObjBossBullet::CObjBossBullet(float x, float y,float r)
{
	//�G�̎��ۂ̍��W���󂯎��
	m_r = r;
	m_x = x + 40;
	m_y = y + 40;
}

//�C�j�V�����C�Y
void CObjBossBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�X�N���[���������̃x�N�g�����擾
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	

	//HitBox�쐬
	Hits::SetHitBox(this, m_x+m_scroll_map_x, m_y+m_scroll_map_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//�A�N�V����
void CObjBossBullet::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	CObjBoss* bb = (CObjBoss*)Objs::GetObj(OBJ_BOSS);
	if(bb!=nullptr)
	count = bb->m_Bcount;

	m_time ++ ;

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
	bbh->BlockHit(&Bx, &By, &m_up, &m_down, &m_reft, &m_right, &m_vx, &m_vy);

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
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	if (m_time == 100)
	{
		if (count == 0) {
			for (float i = 45.0; i != 405.0; i += 90.0) {
				CObjAngleBullet* obj_eb = new CObjAngleBullet(m_x , m_y , i);
				Objs::InsertObj(obj_eb, OBJ_ENEMY_BULLET, 16);
			}
			
		}
		else if(count==1){
		    for (float i = 0.0; i != 360.0; i += 90.0) {
				CObjAngleBullet* obj_eb = new CObjAngleBullet(m_x , m_y , i);
				Objs::InsertObj(obj_eb, OBJ_ENEMY_BULLET, 16);
			}
			
		}
		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜

	}

	
	//��l���ƐڐG���Ă��邩�ǂ������ׂ�
	else if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜
	}
	//��l���i�l�j�ƐڐG���Ă��邩���ׂ�
	else if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		this->SetStatus(false);//�폜����
		Hits::DeleteHitBox(this);//�폜
	}
	////�e�ۂƐڐG���Ă��邩�𒲂ׂ�
	else if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�e�ۂ����L����HitBox�ɍ폜����B
	}
	
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
	dst.m_top = 0.0f+m_y+m_scroll_map_y;
	dst.m_left = 0.0f+m_x+m_scroll_map_x;
	dst.m_right = 32.0f+m_x+m_scroll_map_x;
	dst.m_bottom = 32.0f+m_y+m_scroll_map_y;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}