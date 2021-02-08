#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjEnemy :public CObj
{
public:
	CObjEnemy(float x,float y);
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();


	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }
	int GetBI() { return  pbullet_interval; }

private:
	float m_x;//x座標
	float m_y;//y座標
	float m_vx;//移動方向x
	float m_vy;//移動方向y
	float m_r;//移動方向に描画する変数
	float m_hp;//HP
	int count;//主人公の位置を向く為の変数
	int m_time;//弾発射間隔制御用変数
	int m_move_time;//敵戦車移動硬直用変数

	float m_scroll_map_x{ 0 };//mapのスクロールに合わせて動くための変数
	float m_scroll_map_y{ 0 };

	int pbullet_interval;
	bool pbullet_enable;


	bool m_hit_up;//当たり判定用
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
