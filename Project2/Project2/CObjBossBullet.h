#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBossBullet :public CObj
{
public:
	CObjBossBullet(float x, float y,float r);
	~CObjBossBullet() {};
	void Init();
	void Action();
	void Draw();


	int count{ 0 };

	float GetMX() { return mx; }
	float GetMY() { return my; }

private:
	float m_x;//���W
	float m_y;

	float m_r;//�p�x

	float m_vx;//�x�N�g��
	float m_vy;

	float mx{ 0 };//�ړ���
	float my{ 0 };

	float m_time{ 0 };//�g�U�^�C�~���O����p

	float m_scroll_map_x{ 0 };//�X�N���[���l�i�[�p�ϐ�
	float m_scroll_map_y{ 0 };

	//angle�����s���邩���f����ϐ�
	bool m_check{false};

	//�u���b�N�Ƃ̓����蔻��p
	bool m_up;
	bool m_reft;
	bool m_right;
	bool m_down;
};
