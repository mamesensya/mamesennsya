//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjBean.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
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
	if (hero != nullptr)
	{
		float hx = hero->GetX();
		float hy = hero->GetY();
	}
	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_BEAN, 1);
}

//�A�N�V����
void CObjBean::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���i�ߐڍU���j�ƐڐG�����瓤���폜
	if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//�����폜
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

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(14, &src, &dst, c, 0);
}