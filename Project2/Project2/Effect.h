#pragma once
#include "GameL\SceneObjManager.h"
//
using namespace GameL;

//
class Effect :public CObj
{
	public:
		Effect(float x, float y,float r) ;
		~Effect() {};
		void Init();//�C�j�V�����C�Y
		void Action();//�A�N�V����
		void Draw();//�h���[
	private:
		float m_x;
		float m_y;
		float m_r;

		float m_scroll_map_x{ 0 };
		float m_scroll_map_y{ 0 };

		int out ;//�폜����
};