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


};
