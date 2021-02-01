#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBossBullet4 :public CObj
{
public:
	CObjBossBullet4(float x, float y, float r);
	~CObjBossBullet4() {};
	void Init();
	void Action();
	void Draw();



private:
	float m_x;//座標
	float m_y;

	float m_r;//角度

	float m_vx;//ベクトル
	float m_vy;

	float mx{ 0 };//移動量
	float my{ 0 };

	float m_scroll_map_x{ 0 };//スクロール値格納用
	float m_scroll_map_y{ 0 };

	float m_speed{ 0.5 };//弾丸スピード


	bool m_up;//当たり判定
	bool m_reft;
	bool m_right;
	bool m_down;
};