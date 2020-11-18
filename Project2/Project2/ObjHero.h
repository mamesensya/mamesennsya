#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjHero :public CObj
{
public:
	CObjHero(float x,float y) ;
	~CObjHero() {};
	void Init();//CjVCY
	void Action();//ANV
	void Draw();//h[

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	int GetHP() {return m_hp;}

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void GetBullet(int bullet) { m_bullet += bullet; }
	void GetUniqueBullet1(int unique_bullet_1)
	{	m_unique_bullet_1 += unique_bullet_1;	}
	void GetUniqueBullet2(int unique_bullet_2)
	{	m_unique_bullet_2 += unique_bullet_2;	}

	bool m_hero_flag;//ๅl๖ฬ๓ิmFtO
	//falseFๅl๖iํิj@trueFๅl๖ilj
private:
	int m_hp{ 0 };//ๅl๖ฬqbg|Cgiฬอj

	float m_x;//ๅl๖ฺฎpฯFกฒ
	float m_y;//ๅl๖ฺฎpฯFcฒ
	float m_vx{ 0 };//ๅl๖xNgFกฒ
	float m_vy{ 0 };//ๅl๖xNgFcฒ
	

	float m_r{ 0 };//ๅl๖ฬpxงไp

	float rad{ 0 };//WA

	int bullet{ 0 };//ๅl๖ฬe
	int m_bullet;//ๅl๖iํิjFสํe
	int m_unique_bullet_1;//ๅl๖iํิjFม๊eiPje
	int m_unique_bullet_2;//ๅl๖iํิjFม๊eiQje
	
	int m_attack_time{ 0 };//Uิuิ
	int m_hit_time{ 0 };//ํeิuิ

	bool m_attack{ true };//eญหิuงไp
	bool m_hit{ true };//ํeิuงไp

	float sin_f{ 0 };
	float cos_f{ 0 };

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};