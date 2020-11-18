#pragma once

#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjAngleBullet :public CObj
{
public:
	CObjAngleBullet(float x, float y, float r);
	~CObjAngleBullet() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	float m_x;//座標
	float m_y;
	float m_vx;//移動用
	float m_vy;
	float m_r;//方向
	float mx;//移動量
	float my;

	float m_time;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };


};