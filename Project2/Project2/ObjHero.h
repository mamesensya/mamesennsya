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
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }

	bool Hero() { return m_hero_flag; }

	

	int direct{0};//主人公の方向記憶変数
private:
	int m_hp{ 0 };//主人公のヒットポイント（体力）

	float m_x;//主人公移動用変数：横軸
	float m_y;//主人公移動用変数：縦軸
	float m_vx{ 0 };//主人公ベクトル：横軸
	float m_vy{ 0 };//主人公ベクトル：縦軸
	float m_px{ 0 };//主人公位置用変数：横軸
	float m_py{ 0 };//主人公位置用変数：縦軸

	float m_r{ 0 };//主人公の角度制御用

	int m_time{0};//

	bool m_bullet;//主人公（戦車）：通常弾の制御用
	bool m_unique_bullet_1;//主人公（戦車）：特殊弾（１）制御用
	bool m_unique_bullet_2;//主人公（戦車）：特殊弾（２）制御用
	bool m_bullet_time;//主人公（戦車）：弾の発射間隔の制御用

	bool m_hero_flag;//主人公の状態確認フラグ
	//false：主人公（戦車）　true：主人公（人）
};