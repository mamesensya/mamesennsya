#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjUserInterface : public CObj {
public:
	CObjUserInterface() {};
	~CObjUserInterface() {};
	void Init();
	void Action();
	void Draw();
	void setMAXenemy(int setenemy) { setenemyMax = setenemy; nowenemy = setenemy; }
	void DestroyedRequest() {
		setenemyMax--;
	}
	int setenemyMax;
private:
	char keystr[4] = { 'Z','X','C','V' };
	bool flug;
	
	int nowenemy = 0;
};