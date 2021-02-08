#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjPenetrateBullet : public CObj {
public:
	CObjPenetrateBullet(float x, float y, float r);
	~CObjPenetrateBullet() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_x;//���W
	float m_y;

	float m_vx;//�x�N�g��
	float m_vy;

	float m_r;//�p�x
	
	bool pbullet_enable;//�ђʒe�����蔻��
	int pbullet_interval;//�ђʒehit�^�C�~���O����p
	bool flag = false;//�ђʒe������flag

	bool m_up;//�����蔻��
	bool m_reft;
	bool m_right;
	bool m_down;

	float m_scroll_map_x{ 0 };//�X�N���[���l�i�[�p
	float m_scroll_map_y{ 0 };
};