#pragma once
#include "GameL\SceneObjManager.h"


using namespace GameL;

class CObjGhostAttack :public CObj
{
public:
	CObjGhostAttack(float x, float y) ;
	~CObjGhostAttack() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;

	float m_scroll_map;

	int m_time = 0;
};