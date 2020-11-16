#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjEnemy3 :public CObj
{
public:
	CObjEnemy3(float x, float y);
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();


	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }

private:
	float m_x;//x���W
	float m_y;//y���W
	float m_get_x;//Hero���Wx
	float m_get_y;//Hero���Wy
	float m_vx;//�ړ�����x
	float m_vy;//�ړ�����y
	float m_posture;//
	float m_r;//�ړ������ɕ`�悷��ϐ�
	int m_hp;//HP
	int count;//��l���̈ʒu�������ׂ̕ϐ�
	int m_time;//�e���ˊԊu����p�ϐ�
	int m_move_time;
	int pbullet_interval;
	bool pbullet_enable;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };


	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
