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

	float m_vx{ 0 };//移動用
	float m_vy{ 0 };

	float m_r;//角度

	float mx{ 0 };//移動量
	float my{ 0 };


	float m_scroll_map_x{ 0 };//スクロールの値
	float m_scroll_map_y{ 0 };

	bool m_up;//当たり判定
	bool m_reft;
	bool m_right;
	bool m_down;
	bool m_hit;

};