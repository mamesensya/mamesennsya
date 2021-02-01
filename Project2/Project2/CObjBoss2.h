#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBoss2 :public CObj
{
public:
	CObjBoss2(float x, float y);
	~CObjBoss2() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetR() { return m_r; }

	int GetBI() { return pbullet_interval; }

	int m_bullet_type{ 0 };//ボスの攻撃方法変更用
private:
	float m_x{ 0 };//x座標
	float m_y{ 0 };//y座標
	float m_r{ 0 };//角度

	float m_hp{ 0 };//HP

	int m_maelstrom_time{ 0 };//渦巻き時間制御用
	bool m_attack;//弾発射間隔制御用
	int m_attack_time{ 0 };//弾発射間隔時間
	int pbullet_interval;//貫通弾制御用
	bool pbullet_enable;

	float m_scroll_map_x{ 0 };//スクロール値格納用変数
	float m_scroll_map_y{ 0 };

	bool m_hit_up;//当たり判定
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};
