#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjHero :public CObj
{
public:
	CObjHero(float x,float y,float r) ;
	~CObjHero() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	int GetHP() {return m_hp;}
	int GetBullet() {return m_bullet;}
	int GetUBulletA() {return m_unique_bullet_1;}
	int GetUBulletB() {return m_unique_bullet_2;}
	bool GetHeroState() {
		return m_hero_flag;
	}

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void GetBullet(int bullet) { m_bullet += bullet; }
	void GetUniqueBullet1(int unique_bullet_1)
	{	m_unique_bullet_1 += unique_bullet_1;	}
	void GetUniqueBullet2(int unique_bullet_2)
	{	m_unique_bullet_2 += unique_bullet_2;	}

	bool m_hero_flag;//��l���̏�Ԋm�F�t���O
	//false�F��l���i��ԁj�@true�F��l���i�l�j


	bool Getup() { return m_hit_up; };
	bool Getdown() { return m_hit_down; };
	bool Getleft() { return m_hit_left; };
	bool Getright() { return m_hit_right; };
private:
	int m_hp{ 0 };//��l���̃q�b�g�|�C���g�i�̗́j

	float m_x;//��l���ړ��p�ϐ��F����
	float m_y;//��l���ړ��p�ϐ��F�c��
	float m_vx{ 0 };//��l���x�N�g���F����
	float m_vy{ 0 };//��l���x�N�g���F�c��
	

	float m_r{ 0 };//��l���̊p�x����p

	float rad{ 0 };//���W�A��

	int bullet{ 0 };//��l���̑��e��
	int m_bullet;//��l���i��ԁj�F�ʏ�e��
	int m_unique_bullet_1;//��l���i��ԁj�F����e�i�P�j�e��
	int m_unique_bullet_2;//��l���i��ԁj�F����e�i�Q�j�e��
	
	int m_attack_time{ 0 };//�U���Ԋu����
	int m_hit_time{ 0 };//��e�Ԋu����

	bool m_attack{ true };//�e���ˊԊu����p
	bool m_hit{ true };//��e�Ԋu����p

	float sin_f{ 0 };
	float cos_f{ 0 };

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	float m_scroll{ 0 };
	float m_scroll2{ 0 };

};