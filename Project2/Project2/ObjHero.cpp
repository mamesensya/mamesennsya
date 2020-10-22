//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"

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

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_bullet = true;
	m_unique_bullet_1 = true;
	m_unique_bullet_2 = true;
	m_human_flag = false;
	m_hp = HP;
	direct = 1;

	//�����蔻��
	Hits::SetHitBox(this, m_x+10, m_y+20, 72, 72, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	////��ԏ�ԁF�U��
	//if (m_human_flag == false)
	//{
	//	//�ʏ�e
	//	if (Input::GetVKey('C') == true)
	//	{
	//		if (m_bullet == true)
	//		{
	//			//�e�ۃI�u�W�F�N�g�쐬
	//			CObjBullet* obj_b = new CObjBullet(m_x, m_y);//�e�ۃI�u�W�F�N�g�쐬
	//			Objs::InsertObj(obj_b, OBJ_BULLET, 1);//������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//			m_bullet = false;
	//		}
	//		else
	//		{
	//			m_bullet = true;
	//		}
	//	}
	//	//����e�i�P�j
	//	else if (Input::GetVKey('X') == true)
	//	{
	//		if (m_unique_bullet_1 == true)
	//		{
	//			//�e�ۃI�u�W�F�N�g�쐬
	//			CObjBullet* obj_b = new CObjBullet(m_x, m_y);//�e�ۃI�u�W�F�N�g�쐬
	//			Objs::InsertObj(obj_b, OBJ_BULLET, 1);//������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//			m_unique_bullet_1 = false;
	//		}
	//		else
	//		{
	//			m_unique_bullet_1 = true;
	//		}
	//	}
	//	//����e�i�Q�j
	//	else if (Input::GetVKey('Z') == true)
	//	{
	//		if (m_unique_bullet_2 == true)
	//		{
	//			//�e�ۃI�u�W�F�N�g�쐬
	//			CObjBullet* obj_b = new CObjBullet(m_x, m_y);//�e�ۃI�u�W�F�N�g�쐬
	//			Objs::InsertObj(obj_b, OBJ_BULLET, 1);//������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//			m_unique_bullet_2 = false;
	//		}
	//		else
	//		{
	//			m_unique_bullet_2 = true;
	//		}
	//	}
	//}
	////�l��ԁF�U��
	//if (m_human_flag == true)
	//{
	//	//�ʏ�e
	//	if (Input::GetVKey('C') == true)
	//	{
	//		if (m_attack == true)
	//		{

	//			m_attack = false;
	//		}
	//		else
	//		{
	//			m_attack = true;
	//		}
	//	}
	//}
	//�l��ԁ���ԏ�Ԃ�
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
		m_x += SPEED;
		direct = 2;
		//HitBox�̈ʒu���X�V
		hit->SetPos(m_x, m_y + 12);
	}
	//������
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_r = 90.0f;
		m_x -= SPEED;
		direct = 4;
		//HitBox�̈ʒu���X�V
		hit->SetPos(m_x + 20, m_y + 12);
	}
	//�����
	if (Input::GetVKey(VK_UP) == true)
	{
		m_r = 0.0f;
		m_y -= SPEED;
		direct = 1;
		//HitBox�̈ʒu���X�V
		hit->SetPos(m_x + 10, m_y + 20);
	}
	//������
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_r = 180.0f;
		m_y += SPEED;
		direct = 3;
		//HitBox�̈ʒu���X�V
		hit->SetPos(m_x + 10, m_y);
	}
	//�����蔻����s���I�u�W�F�N�g���
	int data_base[Collision_detection] =
	{
		OBJ_ENEMY,
	};

	//�G�I�u�W�F�N�g�ƐڐG�������l����m_hp������
	if (hit->CheckObjNameHit(data_base[Collision_detection]) != nullptr)
	{
		m_hp -= 1;
	}
	//m_hp���O�ɂȂ�Ǝ�l����j��
	if (m_hp <= 0)
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