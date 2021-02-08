#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBoss :public CObj
{
public:
	CObjBoss(float x, float y);
	~CObjBoss() {};
	void Init();
	void Action();
	void Draw();


	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }
	bool Getcek() { return m_check; }

	int GetBI() { return pbullet_interval; }

	int m_Bcount{ 0 };
	int m_oni_count{ 0 };
	int round{ 0 };
private:
	float m_x;//x座標
	float m_y;//y座標
	float m_get_x;//Hero座標x
	float m_get_y;//Hero座標y
	float m_vx;//移動ベクトルx
	float m_vy;//移動ベクトルy
	float m_posture;//
	float m_r;//移動方向に描画する変数
	float m_hp;//HP
	int count;//主人公の位置を向く為の変数
	int m_time;//弾発射間隔制御用変数
	int m_time2;//巨大弾発射間隔制御用
	int m_move_time;//BOSS移動硬直制御用
	int pbullet_interval;//貫通弾当たり判定制御用
	bool pbullet_enable;//貫通弾当たり判定flag

	bool m_check{false};

	float m_oni_time{ 0 };//鬼出現間隔制御用変数

	float m_scroll_map_x{ 0 };//スクロール値格納変数
	float m_scroll_map_y{ 0 };


	bool m_hit_up;//当たり判定用
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

};
