#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjPlayerBullet : public CObj {
public:
	CObjPlayerBullet(float x, float y, float r,int n);
	~CObjPlayerBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;//���W
	float m_y;

	float m_vx;//�x�N�g��
	float m_vy;

	float m_r;//�p�x

	float m_speed;//�e�ۂ̑��x


	bool m_up;//�����蔻��
	bool m_reft;
	bool m_right;
	bool m_down;

	float m_scroll_map_x{ 0 };//�X�N���[���l�i�[�p
	float m_scroll_map_y{ 0 };

	float m_newscroll_x{0};//���݂̃X�N���[���̒l���i�[
	float m_newscroll_y{0};

	int bullettype;//�e��
};