#pragma once
#include "GameL\SceneObjManager.h"


using namespace GameL;

class CObjGhost:public CObj
{
public:
	CObjGhost(float x,float y) ;
	~CObjGhost() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_x;//�ȉ��z�[�~���O�ϐ�
	float m_y;
	float m_vx;
	float m_vy;

	int m_time;

};