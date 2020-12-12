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

	void SetterGetGun(int a, int uniquea, int uniqueb, bool getflug) {
		getguns[0] = a; 
		getguns[1] = uniquea;
		getguns[2] = uniquea;
		getflugs = getflug;
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

	wchar_t uistr[3][128];
	
	int waitcount = 0;
	int getguns[3] = { 0 };
	bool getflugs;
};