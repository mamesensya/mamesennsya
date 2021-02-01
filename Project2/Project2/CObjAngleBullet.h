#pragma once

#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjAngleBullet :public CObj
{
public:
	CObjAngleBullet(float x, float y, float r);
	~CObjAngleBullet() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	float m_x;//���W
	float m_y;

	float m_vx{ 0 };//�ړ��p
	float m_vy{ 0 };

	float m_r;//�p�x

	float mx{ 0 };//�ړ���
	float my{ 0 };


	float m_scroll_map_x{ 0 };//�X�N���[���̒l
	float m_scroll_map_y{ 0 };

	bool m_up;//�����蔻��
	bool m_reft;
	bool m_right;
	bool m_down;
	bool m_hit;

};