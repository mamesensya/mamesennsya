#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjHero :public CObj
{
public:
	CObjHero(float x,float y) ;
	~CObjHero() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	
	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	void GetBullet(int bullet) { m_bullet += bullet; }
	void GetUniqueBullet1(int unique_bullet_1)
	{	m_unique_bullet_1 += unique_bullet_1;	}
	void GetUniqueBullet2(int unique_bullet_2)
	{	m_unique_bullet_2 += unique_bullet_2;	}

	bool Hero() { return m_hero_flag; }

	int direct{0};//��l���̕����L���ϐ�
private:
	int m_hp{ 0 };//��l���̃q�b�g�|�C���g�i�̗́j

	float m_x;//��l���ړ��p�ϐ��F����
	float m_y;//��l���ړ��p�ϐ��F�c��
	float m_vx{ 0 };//��l���x�N�g���F����
	float m_vy{ 0 };//��l���x�N�g���F�c��
	

	float m_r{ 0 };//��l���̊p�x����p

	int m_time{0};//

	int m_bullet;//��l���i��ԁj�F�ʏ�e��
	int m_unique_bullet_1;//��l���i��ԁj�F����e�i�P�j�e��
	int m_unique_bullet_2;//��l���i��ԁj�F����e�i�Q�j�e��
	bool m_bullet_time;//��l���i��ԁj�F�e�̔��ˊԊu�̐���p

	bool m_hero_flag;//��l���̏�Ԋm�F�t���O
	//false�F��l���i��ԁj�@true�F��l���i�l�j

	float sin_f{ 0 };
	float cos_f{ 0 };


	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};