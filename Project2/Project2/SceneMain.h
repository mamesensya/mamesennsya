#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

static int Stage;

//�V�[���@�F�@�Q�[�����C��
class CSceneMain :public CScene
{

public:
	CSceneMain() ;
	~CSceneMain() ;
	void InitScene() ;//�Q�[�����C���̏��������\�b�h
	void Scene();//�Q�[�����C���̎��s�����\�b�h
	void RoundChange();
	void SStage() ;
	int GetEnemy() {
		return GetenemyMax;
	}
	int GetStage()
	{
		return Stage;
	};

private:
	int GetenemyMax = 0;
	int Resetflg = 0;
};

