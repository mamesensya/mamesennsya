#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���@�F�@�Q�[�����C��
class CSceneMainThird :public CScene
{
public:
	CSceneMainThird();
	~CSceneMainThird();
	void InitScene();//�Q�[�����C���̏��������\�b�h
	void Scene();//�Q�[�����C���̎��s�����\�b�h
	int GetEnemy() {
		return GetenemyMax;
	}

private:
	int GetenemyMax = 0;
};
