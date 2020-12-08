#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�E���F�w�i
class CObjBlock :public CObj
{
public:
	CObjBlock(int map[60][80]);
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();

	float GetSX() { return m_scroll; };
	float GetSY() { return m_scroll2; };

	void SetSX(float x) { m_scroll = x; };
	void SetSY(float y) { m_scroll2 = y; };

	void BlockHit(
		float* x, float* y, bool* up, bool* down,
		bool* left, bool* right, float* vx, float* vy
	);
	
	

	int m_map[60][80]{0};//�}�b�v���


private:

	int m_back[6][8]{0};
	float m_scroll;//���E�X�N���[���p
	float m_scroll2;//�㉺�X�N���[���p
	int e{ 0 };
	bool f=false;
	int Enemycount{ 0 };

	int t{ 0 };
};
