#pragma once
#include "GameL\SceneObjManager.h"
//
using namespace GameL;

//
class Effect
{
	public:
		Effect(float x, float y) ;
		~Effect() {};
		void Init();//イニシャライズ
		void Action();//アクション
		void Draw();//ドロー

	private:
		float m_x;
		float m_y;
};