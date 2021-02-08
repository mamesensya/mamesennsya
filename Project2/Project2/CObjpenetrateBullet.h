#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjPenetrateBullet : public CObj {
public:
	CObjPenetrateBullet(float x, float y, float r);
	~CObjPenetrateBullet() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_x;//座標
	float m_y;

	float m_vx;//ベクトル
	float m_vy;

	float m_r;//角度
	
	bool pbullet_enable;//貫通弾当たり判定
	int pbullet_interval;//貫通弾hitタイミング制御用
	bool flag = false;//貫通弾初期化flag

	bool m_up;//当たり判定
	bool m_reft;
	bool m_right;
	bool m_down;

	float m_scroll_map_x{ 0 };//スクロール値格納用
	float m_scroll_map_y{ 0 };
};