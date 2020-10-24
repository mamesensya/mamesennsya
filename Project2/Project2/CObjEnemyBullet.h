#pragma once

#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjEnemyBullet :public CObj
{
public:
	CObjEnemyBullet(float x,float y);
	~CObjEnemyBullet() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_time;

};