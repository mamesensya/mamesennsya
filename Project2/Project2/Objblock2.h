#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト・箱：背景
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();

	float GetScrollX() { return m_scroll;}
	float GetScrollY() { return m_scroll2; }
	float GetSX() { return m_scroll; };
	float GetSY() { return m_scroll2; };

	void BlockHit(
		float* x, float* y, bool* up, bool* down,
		bool* left, bool* right, float* vx, float* vy
	);
	int m_map[60][80];//マップ情報（仮）
private:
	

	float m_scroll;//左右スクロール用
	float m_scroll2;//上下スクロール用


};

