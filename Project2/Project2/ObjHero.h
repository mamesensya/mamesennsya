#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjHero :public CObj
{
public:
	CObjHero(float x,float y) ;
	~CObjHero() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	
	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	void GetBullet(int bullet) { m_bullet += bullet; }
	void GetUniqueBullet1(int unique_bullet_1)
	{	m_unique_bullet_1 += unique_bullet_1;	}
	void GetUniqueBullet2(int unique_bullet_2)
	{	m_unique_bullet_2 += unique_bullet_2;	}

	bool Hero() { return m_hero_flag; }

	int direct{0};//主人公の方向記憶変数
private:
	int m_hp{ 0 };//主人公のヒットポイント（体力）

	float m_x;//主人公移動用変数：横軸
	float m_y;//主人公移動用変数：縦軸
	float m_vx{ 0 };//主人公ベクトル：横軸
	float m_vy{ 0 };//主人公ベクトル：縦軸
	

	float m_r{ 0 };//主人公の角度制御用

	int m_time{0};//

	int m_bullet;//主人公（戦車）：通常弾数
	int m_unique_bullet_1;//主人公（戦車）：特殊弾（１）弾数
	int m_unique_bullet_2;//主人公（戦車）：特殊弾（２）弾数
	bool m_bullet_time;//主人公（戦車）：弾の発射間隔の制御用

	bool m_hero_flag;//主人公の状態確認フラグ
	//false：主人公（戦車）　true：主人公（人）

	float sin_f{ 0 };
	float cos_f{ 0 };


	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};