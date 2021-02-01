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

	int m_bullet_type{ 0 };//ƒ{ƒX‚ÌUŒ‚•û–@•ÏX—p
private:
	float m_x{ 0 };//xÀ•W
	float m_y{ 0 };//yÀ•W
	float m_r{ 0 };//Šp“x

	float m_hp{ 0 };//HP

	int m_maelstrom_time{ 0 };//‰QŠª‚«ŠÔ§Œä—p
	bool m_attack;//’e”­ËŠÔŠu§Œä—p
	int m_attack_time{ 0 };//’e”­ËŠÔŠuŠÔ
	int pbullet_interval;//ŠÑ’Ê’e§Œä—p
	bool pbullet_enable;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};
