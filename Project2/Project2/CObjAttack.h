#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjAttack : public CObj {
public:
	CObjAttack(float x, float y, float r);
	~CObjAttack() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;//ç¿ïW
	float m_y;

	float m_r;//äpìx

	int m_time{ 0 };//éûä‘êßå‰óp
};