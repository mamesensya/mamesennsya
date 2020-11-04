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
	float GetS() { return m_scroll; };
private:
	int m_map[80][60];//マップ情報（仮）

	float m_scroll;//上下左右スクロール用

};

