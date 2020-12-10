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
	void setStage(int sets) { playstage = sets; }
	void DestroyedRequest() {
		setenemyMax--;
	}
	int setenemyMax;
	int GetEM() { return setenemyMax; };
	void flugset(bool flugs) {
		flug = flugs;
	}
private:
	char keystr[4] = { 'Z','X','C','V' };
	bool flug;
	
	int nowenemy = 0;
	int playstage = 0;
	float ease = 0;
	float easey = 0;
	float alpha = 0; float alpha2 = 0.0f;
	int phase = 0;


};