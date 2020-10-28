//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "CObjPlayerBullet.h"
#include "CObjpenetrateBullet.h"

#include "GameHead.h"
#include "ObjHero.h"

//��l����HP�i�̗́j
#define HP 5

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
	m_hero_flag = false;
	m_hp = HP;
	direct = 1;
	m_bullet_time = true;

	//�����蔻��
	Hits::SetHitBox(this, m_x, m_x, 72, 72, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//��ԏ�ԁ��l��Ԃ�
	if (m_hero_flag == false)
	{
		//��l�����l��ԂɈڍs
		if (Input::GetVKey('V') == true)
		{
			m_hero_flag = true;
			//�`���^�����O�h�~�p
			while (Input::GetVKey('V') == true);
		}
	}
	//�q�b�g�{�b�N�X
	CHitBox* hit = Hits::GetHitBox(this);
	//�E����
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_r -= 1.0f;
		direct += 1;
	}
	//������
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_r += 1.0f;
		direct -= 1;
	}
	//�����
	if (Input::GetVKey(VK_UP) == true)
	{
		direct = 1;
	}
	//������
	if (Input::GetVKey(VK_DOWN) == true)
	{
		direct = 1;
	}

	m_x = +m_vx;
	m_y = +m_vy;
	
	if(m_bullet_time==true)
	if (Input::GetVKey('Z') == true) 
	{
		CObjPlayerBullet* obj_ab = new CObjPlayerBullet(m_x,m_y,(float)((direct+2)*90));
		Objs::InsertObj(obj_ab, OBJ_ANGLE_BULLET, 14);
		m_bullet_time = false;
	}
	if (m_bullet_time==true)
	if (Input::GetVKey('X') == true) {
		CObjPenetrateBullet* obj_pb = new CObjPenetrateBullet(m_x, m_y, (float)((direct + 2) * 90));
		Objs::InsertObj(obj_pb, OBJ_PENETRATE_BULLET, 15);
		m_bullet_time = false;
	}

	//�����蔻����s���I�u�W�F�N�g���
	int data_base[4] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY_BULLET,
	};

	//�G�I�u�W�F�N�g�ƐڐG�������l����m_hp������
	for (int i = 0; i < 4; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			m_hp -= 1;
		}
	}
	//m_hp���O�ɂȂ�Ǝ�l����j��
	if (m_hp == 0)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����

		//Scene::SetScene(new CSceneTitle());
	}

	if (m_bullet_time == false)
	{
		m_time++;
		if (m_time == 60) 
		{
			m_bullet_time = true;
			m_time = 0;
		}
	}

}

//�h���[
void CObjHero::Draw()
{
	if (m_hero_flag == false)
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
}