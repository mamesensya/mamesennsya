//�g�p�w�b�_�[�ӂ�����
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"obj ghost.h"

//�l�[���X�y�[�X
using namespace GameL;

CObjghost::CObjghost()
{

}

void CObjghost::Init()
{

}

void CObjghost::Action()
{

}

void CObjghost::Draw()
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
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 32.0f + 64.0f ;
	dst.m_bottom = 32.0f + 64.0f ;

	//�`��
	Draw::Draw(0, &src, &dst, c,1);
}