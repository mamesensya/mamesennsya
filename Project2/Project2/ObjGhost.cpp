//�g�p�w�b�_�[�ӂ�����
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"ObjGhost.h"

//�l�[���X�y�[�X
using namespace GameL;

CObjGhost::CObjGhost()
{

}

void CObjGhost::Init()
{

}

void CObjGhost::Action()
{

}

void CObjGhost::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right =  400.0f;
	dst.m_bottom = 400.0f ;

	//�`��
	Draw::Draw(4, &src, &dst, c,0.0f);
}