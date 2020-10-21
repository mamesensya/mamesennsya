//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjHero.h"

//�����蔻��̃I�u�W�F�N�g��񕔂̐�
#define Collision_detection 1
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
	m_uniquebullet_1 = true;
	m_uniquebullet_2 = true;
	//m_stop_flag = true;
	m_human = false;
	m_hp = HP;

	//�����蔻��
	Hits::SetHitBox(this, m_x, m_y, 92, 92, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	////��ԏ�ԁF�U��
	//if (m_human == false)
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
	//		if (m_uniquebullet_1 == true)
	//		{
	//			//�e�ۃI�u�W�F�N�g�쐬
	//			CObjBullet* obj_b = new CObjBullet(m_x, m_y);//�e�ۃI�u�W�F�N�g�쐬
	//			Objs::InsertObj(obj_b, OBJ_BULLET, 1);//������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//			m_uniquebullet_1 = false;
	//		}
	//		else
	//		{
	//			m_uniquebullet_1 = true;
	//		}
	//	}
	//	//����e�i�Q�j
	//	else if (Input::GetVKey('Z') == true)
	//	{
	//		if (m_uniquebullet_2 == true)
	//		{
	//			//�e�ۃI�u�W�F�N�g�쐬
	//			CObjBullet* obj_b = new CObjBullet(m_x, m_y);//�e�ۃI�u�W�F�N�g�쐬
	//			Objs::InsertObj(obj_b, OBJ_BULLET, 1);//������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//			m_uniquebullet_2 = false;
	//		}
	//		else
	//		{
	//			m_uniquebullet_2 = true;
	//		}
	//	}
	//}
	////�l��ԁF�U��
	//if (m_human == true)
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
	//��ԏ�ԁ��l��Ԃ�
	if (m_human == false)
	{
		//��l�����l��ԂɈڍs
		if (Input::GetVKey('V') == true)
		{
			if (m_flag == true)
			{
				//��l���i�l�j
				m_human = true;
				//�O���t�B�b�N�̔j��

				//�O���t�B�b�N�ǂݍ���
				Draw::LoadImageW(L"��l��_�l.png", 0, TEX_SIZE_512);

			}
			else
			{
				m_flag = true;
			}
		}
	}
	//�l��ԁ���ԏ�Ԃ�
	else if (m_human == true)
	{
		//��l�����l��ԂɈڍs
		if (Input::GetVKey('V') == true)
		{
			if (m_flag == true)
			{
				//��l���i�l�j
				m_human = false;
				//�O���t�B�b�N�̔j��

				//�O���t�B�b�N�ǂݍ���
				Draw::LoadImageW(L"��l��_���.png", 0, TEX_SIZE_512);

			}
			else
			{
				m_flag = true;
			}
		}
	}
	//�E����
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_r = 270.0f;
		m_x += SPEED;
	}
	//������
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_r = 90.0f;
		m_x -= SPEED;
	}
	//�����
	if (Input::GetVKey(VK_UP) == true)
	{
		m_r = 0.0f;
		m_y -= SPEED;
	}
	//������
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_r = 180.0f;
		m_y += SPEED;
	}

	//HitBox�̈ʒu���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�����蔻����s���I�u�W�F�N�g���
	int data_base[Collision_detection] =
	{

	};

	//�G�I�u�W�F�N�g�ƐڐG�������l����m_hp������
	if (hit->CheckObjNameHit(data_base[Collision_detection]) != nullptr)
	{
		m_hp -= 1;
	}
	//m_hp���O�ɂȂ�Ǝ�l����j��
	if (m_hp >= 0)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����
	}
}

//�h���[
void CObjHero::Draw()
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