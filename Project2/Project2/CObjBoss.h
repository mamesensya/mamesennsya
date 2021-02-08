#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBoss :public CObj
{
public:
	CObjBoss(float x, float y);
	~CObjBoss() {};
	void Init();
	void Action();
	void Draw();


	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }
	bool Getcek() { return m_check; }

	int GetBI() { return pbullet_interval; }

	int m_Bcount{ 0 };
	int m_oni_count{ 0 };
	int round{ 0 };
private:
	float m_x;//x���W
	float m_y;//y���W
	float m_get_x;//Hero���Wx
	float m_get_y;//Hero���Wy
	float m_vx;//�ړ��x�N�g��x
	float m_vy;//�ړ��x�N�g��y
	float m_posture;//
	float m_r;//�ړ������ɕ`�悷��ϐ�
	float m_hp;//HP
	int count;//��l���̈ʒu�������ׂ̕ϐ�
	int m_time;//�e���ˊԊu����p�ϐ�
	int m_time2;//����e���ˊԊu����p
	int m_move_time;//BOSS�ړ��d������p
	int pbullet_interval;//�ђʒe�����蔻�萧��p
	bool pbullet_enable;//�ђʒe�����蔻��flag

	bool m_check{false};

	float m_oni_time{ 0 };//�S�o���Ԋu����p�ϐ�

	float m_scroll_map_x{ 0 };//�X�N���[���l�i�[�ϐ�
	float m_scroll_map_y{ 0 };


	bool m_hit_up;//�����蔻��p
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
