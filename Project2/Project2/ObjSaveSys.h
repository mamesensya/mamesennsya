#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjSaveSystem : public CObj {
public:
	CObjSaveSystem() {};
	~CObjSaveSystem() {};
	void Init();
	void Action();
	void Draw();
	int GetState() { return savemode; }
	void SetState(int state) { savemode = state; }

private:
	int drawphase = 0;
	int savemode = 0;
	int viewtime = 0;
	float alpha = 0;

};