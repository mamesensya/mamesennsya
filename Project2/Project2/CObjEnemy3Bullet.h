#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjEnemy3B : public CObj {
public:
	CObjEnemy3B(float x, float y, float r);
	~CObjEnemy3B() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;//座標
	float m_y;

	float m_vx;//移動ベクトル
	float m_vy;

	float m_r;//角度

	float m_speed;//弾の速度

	float mx;//移動量
	float my;

	float m_scroll_map_x{ 0 };//スクロール値
	float m_scroll_map_y{ 0 };
	

	bool m_up;//当たり判定用
	bool m_reft;
	bool m_right;
	bool m_down;
};