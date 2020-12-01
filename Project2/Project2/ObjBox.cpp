//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjBox.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBox::CObjBox(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBox::Init()
{

	

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_BOX, 1);
}

//�A�N�V����
void CObjBox::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	/*CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hvx = hero->GetVX();*/

	//// ��l���ƐڐG���Ă��邩�ǂ������ׂ�
	//	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	//	{
	//		hvx = hvx - hvx - hvx;
	//		hero->SetVX(hvx);
	//	}

	
	hit->SetPos(m_x+m_scroll_map_x, m_y+m_scroll_map_y);

	//��l���i�ߐڍU���j�ƐڐG������{�b�N�X���폜
	if(hit->CheckObjNameHit(OBJ_ATTACK)!=nullptr)
	{
		//�������폜
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�����o��������
		CObjBean* obj_bean = new CObjBean(m_x+m_scroll_map_x, m_y+m_scroll_map_y);
		Objs::InsertObj(obj_bean, OBJ_BEAN, 9);
	}

	if (m_x >= (80 * 64) || m_y >= (60 * 64))
	{

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
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
	src.m_left = 0.0f;
	src.m_right = 240.0f;
	src.m_bottom = 240.0f;
	//�`��ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y+m_scroll_map_y;
	dst.m_left = 0.0f + m_x+m_scroll_map_x;
	dst.m_right = 64.0f + m_x+m_scroll_map_x;
	dst.m_bottom = 64.0f + m_y+m_scroll_map_y;

	//�`��
	Draw::Draw(15, &src, &dst, c, 0.0f);
}
