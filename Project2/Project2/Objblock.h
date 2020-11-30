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

	void BlockHit(
		float* x, float* y, bool* up, bool* down,
		bool* left, bool* right, float* vx, float* vy
	);
	int GetEnemy() {
		return enemies;
	}
	

	int m_map[60][80];//マップ情報
private:

	int m_back[6][8]{0};
	float m_scroll;//左右スクロール用
	float m_scroll2;//上下スクロール用
	int enemies = 0;

	int e{ 0 };

};
