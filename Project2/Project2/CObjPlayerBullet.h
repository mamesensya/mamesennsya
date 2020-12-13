#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjPlayerBullet : public CObj {
public:
	CObjPlayerBullet(float x, float y, float r,int n);
	~CObjPlayerBullet() {};
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

	bool m_up;
	bool m_reft;
	bool m_right;
	bool m_down;


	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };

	int num;
};