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

	bool weit;
	int waittimer = 0;

	float m_r;

	float m_scroll_map_x;
	float m_scroll_map_y;

	int m_time = 1;//�ڋ߂Ɠ����p
	int c{0};//�U������Ԋu

	float n{0.0f};//����
};