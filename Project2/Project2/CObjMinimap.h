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
	int src_x = 0;
	int src_y = 0;
	int px = 0;
	int py = 0;
	int scroll_x = 0;
	int scroll_y = 0;
	int mapdata[60][80];
	int p, s;
	wchar_t str[128];
};