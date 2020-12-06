//�g�p����w�b�_�[�t�@�C��

#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

//�ϐ��̒l���Ď����邽�߂�DrawFont
#include "GameL\DrawFont.h"
#include "GameHead.h"
#include "Objblock.h"
#include"Objbreakblock.h"

//�f�o�b�O�p�ɃC���N���[�h����w�b�_�[
#include "GameL\DrawFont.h"
#include"GameL/HitBoxManager.h"

//�g�p����l�[���X�y�[�X

using namespace GameL;

CObjBlock::CObjBlock(int map[60][80])
{
	memcpy(m_map, map, sizeof(int) * (60 * 80));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = -0.0f;
	m_scroll2 = -0.0f;

	
	
		
}

//�A�N�V����
void CObjBlock::Action()
{

	CObjUserInterface* count = (CObjUserInterface*)Objs::GetObj(OBJ_USERINTERFACE);
	Enemycount = count->GetEM();

	//	��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	float hx = hero->GetX();
	float hy = hero->GetY();

	float hvx = hero->GetVX();
	float hvy = hero->GetVY();

	//�E���X�N���[�����C��
	if (hx < 200)
	{
		hero->SetX(200);
		m_scroll -= hero->GetVX();
	}
	//�����X�N���[�����C��
	if (hx > 400)
	{
		hero->SetX(400);
		m_scroll -= hero->GetVX();
	}
	//����X�N���[�����C��
	if (hy < 200)
	{
		hero->SetY(200);
		m_scroll2 -= hero->GetVY();
	}

	//�����X�N���[�����C��
	if (hy > 400)
	{
		hero->SetY(400);
		m_scroll2 -= hero->GetVY();
	}
	//�G�o�����C��
	float lineX = 0.0;

	//������ς���Ώo�����C���ς����
	//---------------------------------------------------------------
	if(hvx>0)
		lineX = hx + (-m_scroll + 400);
	else if(hvx<0)
		lineX = hx + (-m_scroll - 300);
	//---------------------------------------------------------------
	//�G�o�����C����v�f�ԍ���
	int ex = ((int)lineX) / 64;


	//�G�o�����C���̗������
	/*enemies = 0;*/
	//if((hx+m_scroll)<=m_map[0][0]&&>=m_map[0][80])

	for (int i = 0; i < 80; i++)
	{
		
		//��̒�����4��T��
		if (m_map[i][ex] == 4)
		{
			//4������΁A�G���o��
			CObjEnemy* obje = new CObjEnemy(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY, 50);
			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
		}
		//��̒�����6��T��
		if (m_map[i][ex] == 6)
		{
			//6������΁A�U�e�G���o��
			CObjEnemy3* obje = new CObjEnemy3(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY3, 51);
			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
		}
		//��̒�����5��T��
		if (m_map[i][ex] == 5)
		{
			//5������΁A�{�X���o��
			CObjBoss* obje = new CObjBoss(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obje, OBJ_BOSS, 51);
			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
		}
		//��̒�����7��T��
		if (m_map[i][ex] == 7)
		{
			//7������΁A�{�X2���o��
			CObjBoss2* obje = new CObjBoss2(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obje, OBJ_ENEMY3, 51);
			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
		}
		//��̒�����3��T��
		if (m_map[i][ex] == 3&&f==false)
		{
			//3������΁A����ǂ��o��
			CObjbreakblock* obj_break_block = new CObjbreakblock(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obj_break_block, OBJ_BREAK_BLOCK, 17);
			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
			e++;
		}
		//��̒�����2��T��
		if (m_map[i][ex] == 2)
		{
			//2������Δ����o��
			CObjBox* obj_box = new CObjBox(ex * 64.0f, i * 64.0f);
			Objs::InsertObj(obj_box, OBJ_BOX, 11);
			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
		}
	}
	/*if (e > 20)
	{
		f = true;
	}
	*/
}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	////�w�i�\��
	//src.m_top = 0.0f;
	//src.m_left = 0.0f;
	//src.m_right = 800.0f;
	//src.m_bottom = 560.0f;
	//dst.m_top = 0.0f+m_scroll2;
	//dst.m_left = 0.0f+m_scroll;
	//dst.m_right = 800.0f+m_scroll;
	//dst.m_bottom = 600.0f+m_scroll2;
	//Draw::Draw(3, &src, &dst, c, 0.0f);





	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <8 ; j++)
		{
			if (m_back[i][j] == 0 )
			{

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 600.0f + m_scroll2 - 300;
				dst.m_left = j * 800.0f + m_scroll - 300;
				dst.m_right = dst.m_left + 800.0;
				dst.m_bottom = dst.m_top + 600.0;




				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 800.0f;
				src.m_bottom = 600.0f;


			
				

				//�`��
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}
		}
	}






	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 320.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;



	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 7 && m_map[i][j] != 6 && m_map[i][j] != 5 &&m_map[i][j]!=4 &&m_map[i][j]!=3&& m_map[i][j] != 2)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f + m_scroll2;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;
				if (m_map[i][j] == 2)
				{
					;
				}
				//else if(m_map[i][j]==3)
				//{
				//	//�؂���ʒu�̐ݒ�
				//	src.m_top = 0.0f;
				//	src.m_left = 320.0f;
				//	src.m_right = src.m_left + 64.0f;
				//	src.m_bottom = 64.0f;



				//}
				else if (m_map[i][j] == 4)
				{
					;
				}
				else if (m_map[i][j] == 5)
				{
					;
				}
				else if (m_map[i][j] == 6)
				{
					;
				}
				if (m_map[i][j] == 7)
				{
					;
				}
				else
				{
					src.m_top = 0.0f;
					src.m_left = 320.0f;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = 64.0f;
				}
				//if(m_map[i][j]==3)
				//Draw::Draw(17, &src, &dst, c, 0.0f);
				//else
				Draw::Draw(13, &src, &dst, c, 0.0f);//�`��
			}
		}
	}
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
void CObjBlock::BlockHit(
	float* x, float* y, bool* up, bool* down,
	bool* left, bool* right, float* vx, float* vy
)
{

	*up = false;
	*down = false;
	*left = false;
	*right = false;


	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (m_map[i][j] == 1||(m_map[i][j]==3&&Enemycount!=0)||(m_map[i][j]==2))
			{
				//�v�f�ԍ������W�ɕϊ�
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//��l���ƃu���b�N�̂����蔻��
				if ((*x + (-m_scroll) + 64.0f > bx) && (*x + (-m_scroll) < bx + 64.0f) && (*y + (-m_scroll2) + 64.0f > by) && (*y + (-m_scroll2) < by + 64.0f))
				{
					//�㉺���E�̔���

					//vector�̂�������
					float rvx = (*x + (-m_scroll)) - bx;
					float rvy = (*y + (-m_scroll2)) - by;

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
							*x = bx + 64.0f + (m_scroll);
							*vx = -(*vx) * 0.2f;


						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;
							*y = by - 64.0f + (m_scroll2);
							*vy = -(*vy)*0.2f;



						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;
							*x = bx - 64.0f + (m_scroll);
							*vx = -(*vx) * 0.2f;




						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;
							*y = by + 64.0f + (m_scroll2);
							*vy = -(*vy) * 0.2f;

							
						}

					}

				}




			}



		}
	}

}