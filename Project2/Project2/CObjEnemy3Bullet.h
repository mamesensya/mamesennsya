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
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_r;
	float m_speed;
	float mx;
	float my;

	float m_scroll_map;
};