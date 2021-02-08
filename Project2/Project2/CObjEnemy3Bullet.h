#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjEnemy3B : public CObj {
public:
	CObjEnemy3B(float x, float y, float r);
	~CObjEnemy3B() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;//���W
	float m_y;

	float m_vx;//�ړ��x�N�g��
	float m_vy;

	float m_r;//�p�x

	float m_speed;//�e�̑��x

	float mx;//�ړ���
	float my;

	float m_scroll_map_x{ 0 };//�X�N���[���l
	float m_scroll_map_y{ 0 };
	

	bool m_up;//�����蔻��p
	bool m_reft;
	bool m_right;
	bool m_down;
};