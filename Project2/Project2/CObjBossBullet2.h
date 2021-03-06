#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBossBullet2 :public CObj
{
public:
	CObjBossBullet2(float x, float y, float r);
	~CObjBossBullet2() {};
	void Init();
	void Action();
	void Draw();



private:
	float m_x;
	float m_y;
	float m_r;
	float m_vx;
	float m_vy;
	float mx{ 0 };
	float my{ 0 };

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };

	float m_speed{ 1 };


	bool m_up;
	bool m_reft;
	bool m_right;
	bool m_down;
};