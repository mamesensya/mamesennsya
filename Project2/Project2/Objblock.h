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
	float GetS() { return m_scroll; };
private:
	int m_map[80][60];//�}�b�v���i���j

	float m_scroll;//�㉺���E�X�N���[���p

};

