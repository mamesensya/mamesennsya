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

	float GetX() 
	{
		if (m_hp == 0)
		{
			return 0;
		}
		else
		return m_x;
	}
	float GetY() 
	{
		if (m_hp == 0)
		{
			return 0;
		}
		else
		return m_y;
	}

	int direct{0};//主人公の方向記憶変数
private:
	int m_hp{ 0 };//主人公のヒットポイント（体力）

	float m_x{ 0 };//主人公移動用変数：横軸
	float m_y{ 0 };//主人公移動用変数：縦軸
	float m_px{ 0 };//主人公位置用変数：横軸
	float m_py{ 0 };//主人公位置用変数：縦軸

	float m_r{ 0 };//主人公の角度制御用

	bool m_bullet;//主人公（戦車）：通常弾制御用
	bool m_unique_bullet_1;//主人公（戦車）：特殊弾（１）制御用
	bool m_unique_bullet_2;//主人公（戦車）：特殊弾（２）制御用

	bool m_human_flag;//主人公（人）制御用
	bool m_attack;//主人公（人）：攻撃
};