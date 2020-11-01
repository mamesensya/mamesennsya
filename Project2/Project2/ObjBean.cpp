//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjBean.h"
#include "ObjBox.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBean::CObjBean(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBean::Init()
{
	//�{�b�N�X�̓����蔻��
	//��l���̈ʒu�擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	CObjBox* box = (CObjBox*)Objs::GetObj(OBJ_BOX);
	m_x = box->GetX();
	m_y = box->GetY();


	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_BOX, 1);
}

//�A�N�V����
void CObjBean::Action()
{		
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���i�ߐڍU���j�ƐڐG������{�b�N�X���폜
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		//��l���̎����Ă���e�̐��𑝉�������
		hero->GetBullet(3);
		hero->GetUniqueBullet1(3);
		hero->GetUniqueBullet2(3);
	}
}

//�h���[
void CObjBean::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 768.0f;
	src.m_bottom = 768.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 32.0f;
	dst.m_bottom = 32.0f;

	Draw::Draw(14, &src, &dst, c, 0);
}