#pragma once
//
#include "GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjBox :public CObj
{
public:
	CObjBox(float x, float y);
	~CObjBox() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetX() { return m_x; }
	float GetY() { return m_y; }

private:
	float m_x;//�ʒu
	float m_y;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };
};