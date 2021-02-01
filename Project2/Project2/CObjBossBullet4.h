#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBossBullet4 :public CObj
{
public:
	CObjBossBullet4(float x, float y, float r);
	~CObjBossBullet4() {};
	void Init();
	void Action();
	void Draw();



private:
	float m_x;//���W
	float m_y;

	float m_r;//�p�x

	float m_vx;//�x�N�g��
	float m_vy;

	float mx{ 0 };//�ړ���
	float my{ 0 };

	float m_scroll_map_x{ 0 };//�X�N���[���l�i�[�p
	float m_scroll_map_y{ 0 };

	float m_speed{ 0.5 };//�e�ۃX�s�[�h


	bool m_up;//�����蔻��
	bool m_reft;
	bool m_right;
	bool m_down;
};