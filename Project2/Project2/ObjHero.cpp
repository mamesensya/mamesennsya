//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "CObjPlayerBullet.h"
#include "CObjpenetrateBullet.h"
#include "GameL\Audio.h"
#include"Objbreakblock.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "math.h"

//��l����HP�i�̗́j
#define HP 5

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�p�x�����W�A���ɕς���
inline void sin_cos(float r,float *sin,float *cos) 
{ 
	float rad = r * 3.14 / 180;

	*sin = sinf(rad);
	*cos = cosf(rad);
}

//�e���������񎝂��Ă���Ǝ�l���̑��x���ω�
inline void VectorChange(int bullet, float* sin, float* cos)
{
	if (bullet >= 40)
	{
		*sin *= 0.1f;
		*cos *= 0.1f;
	}
	else if (bullet >= 30)
	{
		*sin *= 0.5f;
		*cos *= 0.5f;
	}
}

bool VectorNormalize(float* vx, float* vy);//�x�N�g�����K���֐�

//�R���X�g���N�^
CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_bullet = 10;
	m_unique_bullet_1 = 3;
	m_unique_bullet_2 = 3;
	m_hero_flag = false;
	m_hp = HP;
	bullet = m_bullet + m_unique_bullet_1 + m_unique_bullet_2;

	//�����蔻��
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//m_time++;
	//if (m_time == 21.0f)
	//{
	//	m_time = 0;
	//}


	//HitBox�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);

	//��l���i�l�j�̏�ԂȂ瓮�삵�Ȃ�
	if (m_hero_flag == false)
	{
		//�x�N�g����0�ɂ���
		m_vx = 0;
		m_vy = 0;

		//��ԏ�ԁ��l��Ԃ�
		if (Input::GetVKey('V') == true)
		{
			if (m_hero_flag == false)
			{
				m_hero_flag = true;

				//��l���i�l�j���쐬
				CObjChara* obj_chara = new CObjChara(m_x, m_y);
				Objs::InsertObj(obj_chara, OBJ_CHARA, 11);
				//�`���^�����O�h�~�p
				while (Input::GetVKey('V') == true);
			}
		}

		//�p�x��0�`360���ȓ��̐����ɗ}����
		if (m_r > 360.0f)
			m_r = 0.0f;
		else if (m_r < 0.0f)
			m_r = 360.0f;

		//�E����
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_r -= 1.0f;
		}
		//������
		else if (Input::GetVKey(VK_LEFT) == true)
		{
			m_r += 1.0f;
		}
		//�����
		if (Input::GetVKey(VK_UP) == true)
		{
			//�p�x�����W�A���ɕϊ�����sin cos�̌v�Z
			sin_cos(m_r, &sin_f, &cos_f);
			//�x�N�g���̐��K��
			VectorNormalize(&sin_f, &cos_f);
			//�e�̏������ɉ����đ��x�ύX
			VectorChange(bullet, &sin_f, &cos_f);

			m_vx = -sin_f*3;
			m_vy = -cos_f*3;
		}
		//������
		else if (Input::GetVKey(VK_DOWN) == true)
		{
			//�p�x�����W�A���ɕϊ�����sin cos�̌v�Z
			sin_cos(m_r, &sin_f, &cos_f);
			//�x�N�g���̐��K��
			VectorNormalize(&sin_f, &cos_f);
			//�e�̏������ɉ����đ��x�ύX
			VectorChange(bullet, &sin_f, &cos_f);

			m_vx = +sin_f*3;
			m_vy = +cos_f*3;
		}

		//�u���b�N�Ƃ̓����蔻��
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_x, &m_y, &m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy);

		


		//�x�N�g�����ʒu�ɉ��Z
		m_x += m_vx;
		m_y += m_vy;

		m_scroll = pb->GetSX();
		m_scroll2 = pb->GetSY();
		//�X�N���[��������x500y500�ȏ�@�E��x-5000y-2500�ȉ��Ȃ珉���l�ɖ߂�
		if (m_scroll >= 500 || m_scroll <= -5000 || m_scroll2 >= 500 || m_scroll2 <= -2000)
		{
			m_scroll = 0;
			m_scroll2 = 0;
			pb->SetSX(m_scroll);
			pb->SetSY(m_scroll2);
		}
		hit->SetPos(m_x, m_y);

		if (m_attack == true) {
			if (Input::GetVKey('Z') == true && m_bullet > 0)
			{
				//���ˉ��炷
				Audio::Start(10);

				CObjPlayerBullet* obj_ab = new CObjPlayerBullet(m_x, m_y, m_r - (m_r * 2) - 90);
				Objs::InsertObj(obj_ab, OBJ_BULLET, 14);
				m_bullet -= 1;
				bullet -= 1;
				m_attack = false;
			}
			if (Input::GetVKey('X') == true && m_unique_bullet_1 > 0) {
				//���ˉ��炷
				Audio::Start(10);

				CObjPenetrateBullet* obj_pb = new CObjPenetrateBullet(m_x, m_y, m_r - (m_r * 2) - 90);
				Objs::InsertObj(obj_pb, OBJ_BULLET, 15);
				m_unique_bullet_1 -= 1;
				bullet -= 1;
				m_attack = false;
			}
			if (Input::GetVKey('C') == true && m_unique_bullet_2 > 0) {
				//���ˉ��炷
				Audio::Start(10);
				
				for (int i = 0; i < 3; i++) {
					CObjPlayerBullet* obj_db = new CObjPlayerBullet(m_x, m_y, m_r - (m_r * 2) - (60 + (30 * i)));
					Objs::InsertObj(obj_db, OBJ_BULLET, 16);
				}
				m_unique_bullet_2 -= 1;
				bullet -= 1;
				m_attack = false;
			}
		}

		if (Input::GetVKey('Q') == true) {
			CObjSaveSystem* savesys = new CObjSaveSystem();
			int state = savesys->GetState();
			if (state == 0) {
				savesys->SetState(1);
				Objs::InsertObj(savesys, OBJ_SAVE, 17);
			};
		};

		//�����蔻����s���I�u�W�F�N�g���
		int data_base[10] =
		{
			OBJ_ENEMY,
			OBJ_ENEMY_BULLET,
			OBJ_ENEMY3,
			OBJ_ENEMY_3BULLET,
			OBJ_BOSS,
			OBJ_BOSS_BULLET,
			OBJ_GHOST,
			OBJ_GHOST_ATTACK,
			OBJ_BOSS2,
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
		if (m_hp <= 0)
		{
			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//��l�������L����HitBox���폜����

			Scene::SetScene(new CSceneGameOver());
		}

		//�U���Ԋu����
		if (m_attack == false)
		{
			m_attack_time++;
			if (m_attack_time == 30)
			{
				m_attack = true;
				m_attack_time = 0;
			}	
		}
		//��e�Ԋu����
		if (m_hit == false)
		{
			m_hit_time++;
			if (m_hit_time == 60)
			{
				m_hit = true;
				m_hit_time = 0;
			}
		}
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
	dst.m_top = -10.0f+ m_y;
	dst.m_left = -10.0f+ m_x;
	dst.m_right = 70.0f + m_x;
	dst.m_bottom =  70.0f + m_y;

	//�`��
	Draw::Draw(19, &src, &dst, c, m_r);
}

//�x�N�g���̐��K���֐�
//float vx		m_vx�Fx���x�N�g��
//float vy		m_vy�Fy���x�N�g��
bool VectorNormalize(float* vx, float* vy)
{
	//�x�N�g���̒��������߂�
	float r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);

	//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		//0�Ȃ�v�Z���s
		return false;
	}
	else
	{
		//���K�����s���Avx��vy�̎Q�Ɛ�̒l��ύX
		(*vx) = 1.0f / r * (*vx);
		(*vy) = 1.0f / r * (*vy);
	}
	//�v�Z����
	return true;
}