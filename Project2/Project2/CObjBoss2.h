#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBoss2 :public CObj
{
public:
	CObjBoss2(float x, float y);
	~CObjBoss2() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }

private:
	float m_x{ 0 };//xç¿ïW
	float m_y{ 0 };//yç¿ïW
	float m_r{ 0 };//äpìx

	int m_hp{ 0 };//HP

	bool m_attack;//íeî≠éÀä‘äuêßå‰óp
	int m_attack_time{ 0 };//íeî≠éÀä‘äuéûä‘
	int pbullet_interval;//ä—í íeêßå‰óp
	bool pbullet_enable;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
