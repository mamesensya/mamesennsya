//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjChara.h"

using namespace GameL;

//�R���X�g���N�^
CObjChara::CObjChara(float x, float y)
{
	m_x = x + 20.0f;
	m_y = y + 20.0f;
}

void CObjChara::Init()
{
	m_hp = 2;

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//�q�[���[����t���O����������đ��
	m_hero_flag = hero->m_hero_flag;
	//�����蔻��
	Hits::SetHitBox(this, m_x, m_y, 48, 48, ELEMENT_CHARA, OBJ_CHARA, 1);
}

void CObjChara::Action()
{
	//��l���̏����擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l�������݂��Ȃ��Ȃ瓮�삵�Ȃ�
	if (hero != nullptr)
	{
		//HitBox�̓��e�X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x, m_y);

		//�l��ԁ���ԏ�Ԃ�
		if (m_hero_flag == true)
		{
			
			//�E����
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				m_r = 270.0f;
				m_vx = 1.0f*3;
			}
			//������
			if (Input::GetVKey(VK_LEFT) == true)
			{
				m_r = 90.0f;
				m_vx = -1.0f*3;
			}
			//�����
			if (Input::GetVKey(VK_UP) == true)
			{
				m_r = 0.0f;
				m_vy = -1.0f*3;
			}
			//������
			if (Input::GetVKey(VK_DOWN) == true)
			{
				m_r = 180.0f;
				m_vy = 1.0f*3;
			}

			//��l���ߐڍU��
			if (m_attack == true)
			{
				if (Input::GetVKey('Z') == true)
				{
					CObjAttack* obj_at = new CObjAttack(m_x, m_y, m_r);
					Objs::InsertObj(obj_at, OBJ_ATTACK, 15);
					m_attack = false;
				}
			}
			if (Input::GetVKey('W') == true) {
				Scene::SetScene(new CSceneMain());
			}
			//�x�N�g�����ʒu�ɉ��Z
			m_x += +m_vx;
			m_y += m_vy;

			//�x�N�g����0�ɖ߂�
			m_vx = 0;
			m_vy = 0;

			//�u���b�N�Ƃ̓����蔻��
			CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
			CObjUserInterface* ui = (CObjUserInterface*)Objs::GetObj(OBJ_USERINTERFACE);
			pb->BlockHit(&m_x, &m_y, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy);

			//�����蔻����s���I�u�W�F�N�g���
			int data_base[10] =
			{
				//OBJ_ENEMY,
				OBJ_ENEMY_BULLET,
				//OBJ_ENEMY3,
				OBJ_ENEMY_3BULLET,
				//OBJ_BOSS,
				OBJ_BOSS_BULLET,
				//OBJ_GHOST,
				OBJ_GHOST_ATTACK,
				//OBJ_BOSS2,
				OBJ_BOSS_BULLET2,
			};

			//�G�I�u�W�F�N�g�ƐڐG�������l����m_hp������
			if (m_hit == true)
			{
				for (int i = 0; i < 10; i++)
				{
					
					if (hit->CheckObjNameHit(data_base[i]) != nullptr)
					{
						//�e���e��
						Audio::Start(14);

						m_hp -= 1;
						m_hit = false;
					}
				}
			}
			//m_hp���O�ɂȂ�Ǝ�l����j��
			if (m_hp == 0)
			{
				this->SetStatus(false);//���g�ɍ폜���߂��o��
				Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����
				
				//Scene::SetScene(new CSceneGameOver());
				ui->setStageStatus(3);
			}

			//�U���Ԋu����p
			if (m_attack == false)
			{
				m_attack_time++;
				if (m_attack_time == 60)
				{
					m_attack = true;
					m_attack_time = 0;
				}
			}
			//��e�Ԋu����p
			if (m_hit == false)
			{
				m_hit_time++;
				if (m_hit_time == 60)
				{
					m_hit = true;
					m_hit_time = 0;
				}
			}
			//��l���i��ԁj��HitBox�ɓ������Ă���Ƃ��ɐ؂�ւ����ł���
			if (m_hp > 0) {
				if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
				{
					m_hit_tank = true;
					//��l�����l��ԂɈڍs
					if (Input::GetVKey('V') == true)
					{
						m_hero_flag = false;

						hero->m_hero_flag = false;

						this->SetStatus(false);//���g�ɍ폜���߂��o��
						Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����
						//�`���^�����O�h�~�p
						while (Input::GetVKey('V') == true);
					}
				}
				else {
					m_hit_tank = false;
				}
			}
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
	Draw::Draw(21, &src, &dst, c, m_r);
}