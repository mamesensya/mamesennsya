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



private:
	float m_x;
	float m_y;
	float m_r;
	float m_vx;
	float m_vy;







	float m_scroll_map;

};
