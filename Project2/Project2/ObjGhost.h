#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjGhost:public CObj
{
public:
	CObjGhost();
	~CObjGhost() {};
	void Init();
	void Action();
	void Draw();

private:


};