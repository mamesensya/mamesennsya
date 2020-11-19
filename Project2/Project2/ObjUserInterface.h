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
private:
	char keystr[4] = { 'Z','X','C','V' };
};