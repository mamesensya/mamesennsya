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
	void MapReload(int map[60][80]);
private:
	int src_x = 0; //スクロールの値を取得する為の変数
	int src_y = 0;

	int px = 0; //主人公の中心座標を格納する為の変数
	int py = 0;

	int bx = 0; //豆状態の主人公の中心座標を取得
	int by = 0;
	int oldbx = 0;
	int oldby = 0;
	int scroll_x = 0; //ミニマップをスクロールさせる際に必要になる変数
	int scroll_y = 0;

	int mapdata[60][80]; //マップデータ格納用
	int p, s;
	wchar_t str[128]; //デバッグモニター（座標の表示に使う）

	int flag =0; //主人公が戦車に載っているか降りているかのフラグを代入
	          //格納しておくことでメゾット毎にCOBjHero型を作らずに済む
};