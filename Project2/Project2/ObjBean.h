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
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	float m_x;//�ʒu
	float m_y;

	int *getguns[3];
};