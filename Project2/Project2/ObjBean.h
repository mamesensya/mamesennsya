#pragma once
//
#include "GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjBean :public CObj
{
public:
	CObjBean(float x,float y);
	~CObjBean() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	float m_x;//位置
	float m_y;

	int *getguns[3];
};