#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�E���F�w�i
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();

	float GetScrollX() { return m_scroll;}
	float GetScrollY() { return m_scroll2; }
	float GetSX() { return m_scroll; };
	float GetSY() { return m_scroll2; };

	void BlockHit(
		float* x, float* y, bool* up, bool* down,
		bool* left, bool* right, float* vx, float* vy
	);
	int m_map[60][80];//�}�b�v���i���j
private:
	

	float m_scroll;//���E�X�N���[���p
	float m_scroll2;//�㉺�X�N���[���p


};

