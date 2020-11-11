#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjChara :public CObj
{
public:
	CObjChara(float x, float y);
	~CObjChara() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }

	bool m_hero_flag{ false };//��l���̏�Ԋm�F�t���O
	//false�F��l���i��ԁj�@true�F��l���i�l�j
private:
	int m_hp{ 0 };//��l���̃q�b�g�|�C���g�i�̗́j

	float m_x{ 0 };//��l���ړ��p�ϐ��F����
	float m_y{ 0 };//��l���ړ��p�ϐ��F�c��
	float m_vx{ 0 };//��l���x�N�g���F����
	float m_vy{ 0 };//��l���x�N�g���F�c��
	float m_px{ 0 };//��l���ʒu�p�ϐ��F����
	float m_py{ 0 };//��l���ʒu�p�ϐ��F�c��

	float m_r{ 0 };//��l���̊p�x����p

	int m_time{ 0 };//��l���U���Ԋu����

	bool m_attack_time{ true };//��l���i�l�j�F�U���̊Ԋu�̐���p
};