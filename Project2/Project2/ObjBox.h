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
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetX() { return m_x; }
	float GetY() { return m_y; }

private:
	float m_x;//位置
	float m_y;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };
};