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
	float m_vx;//�ړ��p
	float m_vy;
	float m_r;//����
	float mx;//�ړ���
	float my;

	float m_time;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };


};