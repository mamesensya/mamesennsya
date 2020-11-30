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

	void BlockHit(
		float* x, float* y, bool* up, bool* down,
		bool* left, bool* right, float* vx, float* vy
	);
	int GetEnemy() {
		return enemies;
	}
	

	int m_map[60][80];//�}�b�v���
private:

	int m_back[6][8]{0};
	float m_scroll;//���E�X�N���[���p
	float m_scroll2;//�㉺�X�N���[���p
	int enemies = 0;

	int e{ 0 };

};
