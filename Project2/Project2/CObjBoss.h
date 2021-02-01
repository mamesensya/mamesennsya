#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBoss :public CObj
{
public:
	CObjBoss(float x, float y);
	~CObjBoss() {};
	void Init();
	void Action();
	void Draw();


	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }
	bool Getcek() { return m_check; }

	int GetBI() { return pbullet_interval; }

	int m_Bcount{ 0 };
	int m_oni_count{ 0 };
	int round{ 0 };
private:
	float m_x;//xÀ•W
	float m_y;//yÀ•W
	float m_get_x;//HeroÀ•Wx
	float m_get_y;//HeroÀ•Wy
	float m_vx;//ˆÚ“®•ûŒüx
	float m_vy;//ˆÚ“®•ûŒüy
	float m_posture;//
	float m_r;//ˆÚ“®•ûŒü‚É•`‰æ‚·‚é•Ï”
	float m_hp;//HP
	int count;//ålŒö‚ÌˆÊ’u‚ğŒü‚­ˆ×‚Ì•Ï”
	int m_time;//’e”­ËŠÔŠu§Œä—p•Ï”
	int m_time2;//‹‘å’e”­ËŠÔŠu§Œä—p
	int m_move_time;//BOSSˆÚ“®d’¼§Œä—p
	int pbullet_interval;//ŠÑ’Ê’e“–‚½‚è”»’è§Œä—p
	bool pbullet_enable;//ŠÑ’Ê’e“–‚½‚è”»’èflag

	bool m_check{false};

	float m_oni_time{ 0 };//‹SoŒ»ŠÔŠu§Œä—p•Ï”

	float m_scroll_map_x{ 0 };//ƒXƒNƒ[ƒ‹’lŠi”[•Ï”
	float m_scroll_map_y{ 0 };


	bool m_hit_up;//“–‚½‚è”»’è
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
