//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "Objbreakblock.h"

//�}�b�v��X����
#define MAP_X (100)
//�}�b�v��Y����
#define MAP_Y (10)

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjbreakblock::CObjbreakblock(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjbreakblock::Init()
{

	//�{�b�N�X�̓����蔻��
	//��l���̈ʒu�擾
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//float hx = hero->GetX();
	//float hy = hero->GetY();
	////�}�b�v�̗v�f�ɃA�N�Z�X
	//for (int i = 0; i < MAP_Y; i++)
	//{
	//	for (int j = 0; j < MAP_X; j++)
	//	{
	//		//�v�f�ԍ������W�ɕύX
	//		float x = j * 64.0f;
	//		float y = i * 64.0f;

	//		//��l���ƃ{�b�N�X�̓����蔻��
	//		if ((hx+64.0f>x)&&(hx<x+64.0f)&&(hy+64.0f>y)&&(hy<y+64.0f))
	//		{
	//			//�������Ă���ꍇ
	//			hero->SetX(hx);
	//			hero->SetY(0.0f);
	//		}
	//	}
	//}

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_BOX, 1);
}

//�A�N�V����
void CObjbreakblock::Action()
{

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll_map_x, m_y + m_scroll_map_y);

	//�G��S���|�����炵����ǂ��폜
	if (Enemycount==0)
	{
		//�ǂ��폜
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	
	}
}

//�h���[
void CObjbreakblock::Draw()
{
	float c[4] = { 1.0f,4.0f,2.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;
	//�`��ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y + m_scroll_map_y;
	dst.m_left = 0.0f + m_x + m_scroll_map_x;
	dst.m_right = 64.0f + m_x + m_scroll_map_x;
	dst.m_bottom = 64.0f + m_y + m_scroll_map_y;

	//�`��
	Draw::Draw(17, &src, &dst, c, 0.0f);
}
