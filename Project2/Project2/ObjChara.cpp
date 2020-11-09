//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjChara.h"

using namespace GameL;

//�R���X�g���N�^
CObjChara::CObjChara(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjChara::Init()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_hero_flag = hero->m_hero_flag;
	//�����蔻��
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_CHARA, OBJ_CHARA, 1);
}

void CObjChara::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (hero != nullptr)
	{
		//HitBox�̓��e�X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x, m_y);

		//�l��ԁ���ԏ�Ԃ�
		if (m_hero_flag == true)
		{
			//��l���i��ԁj��HitBox�ɓ������Ă���Ƃ��ɐ؂�ւ����ł���
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				//��l�����l��ԂɈڍs
				if (Input::GetVKey('V') == true)
				{
					m_hero_flag = false;

					hero->m_hero_flag = false;

					this->SetStatus(false);//���g�ɍ폜���߂��o��
					Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����

					while (Input::GetVKey('V') == true);
				}
			}
			//�E����
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				m_r = 270.0f;
				m_vx = 1.0f;
			}
			//������
			if (Input::GetVKey(VK_LEFT) == true)
			{
				m_r = 90.0f;
				m_vx = -1.0f;
			}
			//�����
			if (Input::GetVKey(VK_UP) == true)
			{
				m_r = 0.0f;
				m_vy = -1.0f;
			}
			//������
			if (Input::GetVKey(VK_DOWN) == true)
			{
				m_r = 180.0f;
				m_vy = 1.0f;
			}
			//��l���ߐڍU��
			if (Input::GetVKey('Z') == true)
			{
				CObjAttack* obj_at = new CObjAttack(m_x, m_y, m_r);
				Objs::InsertObj(obj_at, OBJ_ATTACK, 15);
				m_attack_time = false;
			}

			//�x�N�g�����ʒu�ɉ��Z
			m_x += +m_vx;
			m_y += m_vy;

			//�x�N�g����0�ɖ߂�
			m_vx = 0;
			m_vy = 0;

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
			////m_hp���O�ɂȂ�Ǝ�l����j��
			//if (m_hp == 0)
			//{
			//	this->SetStatus(false);//���g�ɍ폜���߂��o��
			//	Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����

			//	//Scene::SetScene(new CSceneTitle());
			//}
		}
	}
}

void CObjChara::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 400.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + 16.0f + m_x;
	dst.m_bottom = 32.0f + 16.0f + m_y;

	//�`��
	Draw::Draw(6, &src, &dst, c, m_r);
}