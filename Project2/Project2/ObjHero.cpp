//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "CObjPlayerBullet.h"

#include "GameHead.h"
#include "ObjHero.h"

//�����蔻��̃I�u�W�F�N�g��񕔂̐�
#define Collision_detection 4
//��l����HP�i�̗́j
#define HP 5
//��l���̃X�s�[�h
#define SPEED 1.0f

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_bullet = true;
	m_unique_bullet_1 = true;
	m_unique_bullet_2 = true;
	m_human_flag = false;
	m_hp = HP;
	direct = 1;
	m_vx = 0;

	//�����蔻��
	Hits::SetHitBox(this, m_x+10, m_y+20, 72, 72, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	if (m_human_flag == true)
	{
		//��l������ԏ�ԂɈڍs
		if (Input::GetVKey('V') == true)
		{
			m_human_flag = false;
			//�`���^�����O�h�~�p
			while (Input::GetVKey('V') == true);
		}
	}
	//��ԏ�ԁ��l��Ԃ�
	else if (m_human_flag == false)
	{
		//��l�����l��ԂɈڍs
		if (Input::GetVKey('V') == true)
		{
			m_human_flag = true;
			//�`���^�����O�h�~�p
			while (Input::GetVKey('V') == true);
		}
	}
	//�q�b�g�{�b�N�X
	CHitBox* hit = Hits::GetHitBox(this);
	//�E����
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_r = 270.0f;
		m_vx += 1;
		direct = 2;
		//HitBox�̈ʒu���X�V
		hit->SetPos(m_x, m_y + 12);
	}
	//������
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_r = 90.0f;
		m_vx -= 1;
		direct = 4;
		//HitBox�̈ʒu���X�V
		hit->SetPos(m_x + 20, m_y + 12);
	}
	//�����
	if (Input::GetVKey(VK_UP) == true)
	{
		m_r = 0.0f;
		m_vy -= 1;
		direct = 1;
		//HitBox�̈ʒu���X�V
		hit->SetPos(m_x + 10, m_y + 20);
	}
	//������
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_r = 180.0f;
		m_vy += 1;
		direct = 3;
		//HitBox�̈ʒu���X�V
		hit->SetPos(m_x + 10, m_y);
	}
	m_x = +m_vx;
	m_y = +m_vy;

	if (Input::GetVKey('Z') == true) {
		CObjPlayerBullet* obj_ab = new CObjPlayerBullet(m_x,m_y,(float)((direct-1)*90));
		Objs::InsertObj(obj_ab, OBJ_ANGLE_BULLET, 20);
	}

	//�����蔻����s���I�u�W�F�N�g���
	int data_base[4] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY_BULLET,
	};

	//�G�I�u�W�F�N�g�ƐڐG�������l����m_hp������
	if (hit->CheckObjNameHit(OBJ_ENEMY_BULLET) != nullptr)
	{
		m_hp -= 1;
	}
	//m_hp���O�ɂȂ�Ǝ�l����j��
	if (m_hp == 0)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����

		//Scene::SetScene(new CSceneTitle());
	}
}

//�h���[
void CObjHero::Draw()
{
	//��l���i��ԁj�̃O���t�B�b�N
	if (m_human_flag == false)
	{
		//�J���[���
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		RECT_F src;//�`�挳�؂���ʒu
		RECT_F dst;//�`���\���ʒu

		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 300.0f;
		src.m_bottom = 300.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 32.0f + 64.0f + m_x;
		dst.m_bottom = 32.0f + 64.0f + m_y;

		//�`��
		Draw::Draw(0, &src, &dst, c, m_r);
	}
	//��l���i�l�j�̃O���t�B�b�N
	if(m_human_flag == true)
	{

	}
}