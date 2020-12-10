#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト・箱：背景
class CObjBlock :public CObj
{
public:
	CObjBlock(int map[60][80]);
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();

	float GetSX() { return m_scroll; };
	float GetSY() { return m_scroll2; };

	void SetSX(float x) { m_scroll = x; };
	void SetSY(float y) { m_scroll2 = y; };

	void BlockHit(
		float* x, float* y, bool* up, bool* down,
		bool* left, bool* right, float* vx, float* vy
	);
	
	

	int m_map[60][80]{0};//マップ情報


private:

	int m_back[6][8]{0};
	float m_scroll;//左右スクロール用
	float m_scroll2;//上下スクロール用
	int e{ 0 };
	bool f=false;
	int Enemycount{ 0 };

	int t{ 0 };
};
