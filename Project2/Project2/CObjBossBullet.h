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


	int count{ 0 };

private:
	float m_x;
	float m_y;
	float m_r;
	float m_vx;
	float m_vy;
	float mx{ 0 };
	float my{ 0 };
	float m_time{ 0 };

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };

	

	//ボス座標
	float Bx;
	float By;

	//ブロックとの当たり判定用
	bool m_up;
	bool m_reft;
	bool m_right;
	bool m_down;
};
