#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjghost :public CObj
{
public:
	CObjghost();
	~CObjghost();
	void Init();
	void Action();
	void Draw();

private:


};