#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjChara :public CObj
{
public:
	CObjChara(float x, float y);
	~CObjChara() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }

	int GetHP() {return m_hp;}
	bool m_hero_flag{ false };//主人公の状態確認フラグ
	bool m_hit_tank{ false };
	//false：主人公（戦車）　true：主人公（人）
private:
	int m_hp{ 0 };//主人公のヒットポイント（体力）

	float m_x{ 0 };//主人公移動用変数：横軸
	float m_y{ 0 };//主人公移動用変数：縦軸
	float m_vx{ 0 };//主人公ベクトル：横軸
	float m_vy{ 0 };//主人公ベクトル：縦軸
	float m_px{ 0 };//主人公位置用変数：横軸
	float m_py{ 0 };//主人公位置用変数：縦軸

	float m_r{ 0 };//主人公の角度制御用

	int m_attack_time{ 0 };//攻撃間隔時間
	int m_hit_time{ 0 };//被弾間隔時間

	bool m_attack{ true };//攻撃間隔制御用
	bool m_hit{ true };//被弾間隔制御用

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	
};