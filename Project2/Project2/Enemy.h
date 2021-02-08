#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjEnemy :public CObj
{
public:
	CObjEnemy(float x,float y);
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();


	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }
	int GetBI() { return  pbullet_interval; }

private:
	float m_x;//x���W
	float m_y;//y���W
	float m_vx;//�ړ�����x
	float m_vy;//�ړ�����y
	float m_r;//�ړ������ɕ`�悷��ϐ�
	float m_hp;//HP
	int count;//��l���̈ʒu�������ׂ̕ϐ�
	int m_time;//�e���ˊԊu����p�ϐ�
	int m_move_time;//�G��Ԉړ��d���p�ϐ�

	float m_scroll_map_x{ 0 };//map�̃X�N���[���ɍ��킹�ē������߂̕ϐ�
	float m_scroll_map_y{ 0 };

	int pbullet_interval;
	bool pbullet_enable;


	bool m_hit_up;//�����蔻��p
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
