#pragma once
#include "GameL\SceneManager.h"
#include <string>

using namespace GameL;
using namespace std;

class SceneTitle :public CScene {
public:
	SceneTitle() {};
	~SceneTitle() {};
	void InitScene();
	void Scene();
private:
	bool keyover = false;
};