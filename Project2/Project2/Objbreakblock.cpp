//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "Objbreakblock.h"
#include"ObjUserInterface.h"
#include"ObjHero.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;




//�R���X�g���N�^
CObjbreakblock::CObjbreakblock(float x, float y )
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjbreakblock::Init()
{
	
}

//�A�N�V����
void CObjbreakblock::Action()
{

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	CObjUserInterface* count = (CObjUserInterface*)Objs::GetObj(OBJ_USERINTERFACE);
	int Enemycount = count->GetEM();
	

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll_map_x = block->GetSX();
	m_scroll_map_y = block->GetSY();
	

	CHitBox* hit = Hits::GetHitBox(this);



		//�G��S���|�����炵����ǂ��폜
		if (Enemycount==0)
		{
			//�ǂ��폜
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			
		}

		if (m_x >= (80 * 64) || m_y >= (60 * 64))
		{

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





