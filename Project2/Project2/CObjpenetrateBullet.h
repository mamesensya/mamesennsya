#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjPenetrateBullet : public CObj {
public:
	CObjPenetrateBullet(float x, float y, float r);
	~CObjPenetrateBullet() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_r;
	
	bool pbullet_enable;
	int pbullet_interval=1;
	bool flag = false;

	bool m_up;
	bool m_reft;
	bool m_right;
	bool m_down;

	bool m_hit;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };
};