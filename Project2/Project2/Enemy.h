#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjEnemy :public CObj
{
public:
	CObjEnemy(float x,float y);
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();

	float GetR() { return m_r; }

private:
	float m_x;//x座標
	float m_y;//y座標
	float m_get_x;//Hero座標x
	float m_get_y;//Hero座標y
	float m_vx;//移動方向x
	float m_vy;//移動方向y
	float m_posture;//
	float m_r;//移動方向に描画する変数
	int m_hp;//HP
	int count;//主人公の位置を向く為の変数
	int m_time;//弾発射間隔制御用変数
	int m_move_time;


};
