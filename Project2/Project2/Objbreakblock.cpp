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
	
	
	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_BREAK_BLOCK,  1);
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
//BlockHit�֐�
//����1 float* x        :������s��object��X�ʒu
//����2 float* y        :������s��object��Y�ʒu
//����3 bool* up        :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����4 bool* down      :�������ɓ������Ă��邩��Ԃ�
//����5 bool* left      :�������ɓ������Ă��邩��Ԃ�
//����6 bool* right     :�E�����ɓ������Ă��邩��Ԃ�
//����7 float* vx       :���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����8 float* vy       :�㉺���莞�ɂ��ړ������E�͂̒l��ς��ĕԂ�
void CObjbreakblock::BBlockHit(
	float* x, float* y, bool* up, bool* down,
	bool* left, bool* right, float* vx, float* vy
)
{
	

	*up = false;
	*down = false;
	*left = false;
	*right = false;


	//�㉺���E�̔���

	//vector�̂�������
	float rvx = (*x + (-m_scroll_map_x) -m_x) ;
	float rvy = (*y + (-m_scroll_map_y)-m_y) ;

	//���������߂�
	float len = sqrt(rvx * rvx + rvy * rvy);

	float r = atan2(rvy, rvx);
	r = r * 180.0f / 3.14f;


	if (r < 0.0f)
		r = abs(r);
	else
		r = 360.0f - abs(r);

	if (len < 88.0f)
	{


		//�p�x�ŏ㉺���E�𔻒�
		if ((r < 45 && r>0) || r > 315)
		{
			//�E
			*right = true;
			*x = m_x + 64.0f + (m_scroll_map_x);
			*vx = -(*vx) * 0.1f;


		}
		if (r > 45 && r < 135)
		{
			//��
			*down = true;
			*y = m_y - 64.0f + (m_scroll_map_y);
			*vy = -(*vy) * 0.1f;



		}
		if (r > 135 && r < 225)
		{
			//��
			*left = true;
			*x = m_x - 64.0f + (m_scroll_map_x);
			*vx = -(*vx) * 0.1f;					
		}
		if (r > 225 && r < 315)
		{
			//��
			*up = true;
			*y = m_y + 64.0f + (m_scroll_map_y);
			*vy = -(*vy) * 0.1f;


		}
    }
}




