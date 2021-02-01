#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

static int Stage;

//シーン　：　ゲームメイン
class CSceneMain :public CScene
{

public:
	CSceneMain() ;
	~CSceneMain() ;
	void InitScene() ;//ゲームメインの初期化メソッド
	void Scene();//ゲームメインの実行中メソッド
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

