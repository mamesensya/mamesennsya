//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjBox.h"
#include "ObjBean.h"

//�}�b�v��X����
#define MAP_X (100)
//�}�b�v��Y����
#define MAP_Y (10)

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBox::CObjBox(float x, float y)
{
	m_x;
	m_y;
}

//�C�j�V�����C�Y
void CObjBox::Init()
{
	//�{�b�N�X�̓����蔻��
	//��l���̈ʒu�擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
	//�}�b�v�̗v�f�ɃA�N�Z�X
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			//�v�f�ԍ������W�ɕύX
			float x = j * 64.0f;
			float y = i * 64.0f;

			//��l���ƃ{�b�N�X�̓����蔻��
			if ((hx+64.0f>x)&&(hx<x+64.0f)&&(hy+64.0f>y)&&(hy<y+64.0f))
			{
				//�������Ă���ꍇ
				hero->SetX(hx);
				hero->SetY(0.0f);
			}
		}
	}

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_BOX, 1);
}

//�A�N�V����
void CObjBox::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���i�ߐڍU���j�ƐڐG������{�b�N�X���폜
	if (hit->CheckObjNameHit(OBJ_ATTACK) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjBean* obj_bean = new CObjBean(m_x, m_y);
		Objs::InsertObj(obj_bean, OBJ_BEAN, 0);
	}
}

//�h���[
void CObjBox::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;

	//�`��
	Draw::Draw(13, &src, &dst, c, 0.0f);
}
