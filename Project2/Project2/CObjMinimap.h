#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjMinimap : public CObj {
public:
	CObjMinimap(int map[60][80]);
	~CObjMinimap() {};
	void Init();
	void Action();
	void Draw();
private:
	int src_x = 0; //スクロールの値を取得する為の変数
	int src_y = 0;
	int px = 0; //主人公の中心座標を格納する為の変数
	int py = 0;
	int scroll_x = 0; //ミニマップをスクロールさせる際に必要になる変数
	int scroll_y = 0;
	int mapdata[60][80]; //マップデータ格納用
	int p, s;
	wchar_t str[128]; //デバッグモニター（座標の表示に使う）
};