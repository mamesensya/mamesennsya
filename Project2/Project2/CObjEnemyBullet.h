#pragma once

#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjEnemyBullet :public CObj
{
public:
	CObjEnemyBullet(float x,float y);
	~CObjEnemyBullet() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_time;

};