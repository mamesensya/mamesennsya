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

	float GetX() 
	{
		if (m_hp == 0)
		{
			return 0;
		}
		else
		return m_x;
	}
	float GetY() 
	{
		if (m_hp == 0)
		{
			return 0;
		}
		else
		return m_y;
	}

	int direct{0};//��l���̕����L���ϐ�
private:
	int m_hp{ 0 };//��l���̃q�b�g�|�C���g�i�̗́j

	float m_x{ 0 };//��l���ړ��p�ϐ��F����
	float m_y{ 0 };//��l���ړ��p�ϐ��F�c��
	float m_px{ 0 };//��l���ʒu�p�ϐ��F����
	float m_py{ 0 };//��l���ʒu�p�ϐ��F�c��

	float m_r{ 0 };//��l���̊p�x����p

	bool m_bullet;//��l���i��ԁj�F�ʏ�e����p
	bool m_unique_bullet_1;//��l���i��ԁj�F����e�i�P�j����p
	bool m_unique_bullet_2;//��l���i��ԁj�F����e�i�Q�j����p

	bool m_human_flag;//��l���i�l�j����p
	bool m_attack;//��l���i�l�j�F�U��
};