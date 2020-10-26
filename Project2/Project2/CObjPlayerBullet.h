#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjPlayerBullet : public CObj {
public:
	CObjPlayerBullet(float x, float y, float r);
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
};