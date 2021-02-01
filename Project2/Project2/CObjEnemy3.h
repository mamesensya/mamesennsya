#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjEnemy3 :public CObj
{
public:
	CObjEnemy3(float x, float y);
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();


	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }

private:
	float m_x;//x座標
	float m_y;//y座標
	float m_get_x;//Hero座標x
	float m_get_y;//Hero座標y
	float m_vx;//移動方向x
	float m_vy;//移動方向y
	float m_posture;//
	float m_r;//移動方向に描画する変数
	float m_hp;//HP
	int count;//主人公の位置を向く為の変数
	int m_time;//弾発射間隔制御用変数
	int m_move_time;//移動硬直制御用変数
	int pbullet_interval;//貫通弾当たり判定制御用変数
	bool pbullet_enable;//貫通弾当たり判定flag

	float m_scroll_map_x{ 0 };//スクロール値格納用
	float m_scroll_map_y{ 0 };


	bool m_hit_up;//当たり判定
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
