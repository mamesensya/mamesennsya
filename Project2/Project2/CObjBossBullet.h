#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBossBullet :public CObj
{
public:
	CObjBossBullet(float x, float y,float r);
	~CObjBossBullet() {};
	void Init();
	void Action();
	void Draw();


	int count{ 0 };

	float GetMX() { return mx; }
	float GetMY() { return my; }

private:
	float m_x;//座標
	float m_y;

	float m_r;//角度

	float m_vx;//ベクトル
	float m_vy;

	float mx{ 0 };//移動量
	float my{ 0 };

	float m_time{ 0 };//拡散タイミング制御用

	float m_scroll_map_x{ 0 };//スクロール値格納用変数
	float m_scroll_map_y{ 0 };

	//angleを実行するか判断する変数
	bool m_check{false};

	//ブロックとの当たり判定用
	bool m_up;
	bool m_reft;
	bool m_right;
	bool m_down;
};
