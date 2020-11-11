#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjTitles: public CObj {
public:
	CObjTitles() {};
	~CObjTitles() {};
	void Init();
	void Action();
	void Draw();
private:
	int phase[30];
	float adjustpos[30];
	float ease[30];
	int visible;
};