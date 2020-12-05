#pragma once
//
#include "GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjbreakblock :public CObj
{
public:
	CObjbreakblock(float x, float y);
	~CObjbreakblock() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetX() { return m_x; }
	float GetY() { return m_y; }


	void BBlockHit(
		float* x, float* y, bool* up, bool* down,
		bool* left, bool* right, float* vx, float* vy
	);

	int Enemycount{ 0 };

private:
	float m_x;//�ʒu
	float m_y;

	float m_vx;
	float m_vy;

	float m_scroll_map_x{ 0 };
	float m_scroll_map_y{ 0 };

	int num{0};
	int *m_map[60][80];
};