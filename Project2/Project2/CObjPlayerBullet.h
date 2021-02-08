#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjPlayerBullet : public CObj {
public:
	CObjPlayerBullet(float x, float y, float r,int n);
	~CObjPlayerBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;//座標
	float m_y;

	float m_vx;//ベクトル
	float m_vy;

	float m_r;//角度

	float m_speed;//弾丸の速度


	bool m_up;//当たり判定
	bool m_reft;
	bool m_right;
	bool m_down;

	float m_scroll_map_x{ 0 };//スクロール値格納用
	float m_scroll_map_y{ 0 };

	float m_newscroll_x{0};//現在のスクロールの値を格納
	float m_newscroll_y{0};

	int bullettype;//弾丸
};