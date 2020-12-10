#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン　：　ゲームメイン
class CSceneMainSecond :public CScene
{
public:
	CSceneMainSecond();
	~CSceneMainSecond();
	void InitScene();//ゲームメインの初期化メソッド
	void Scene();//ゲームメインの実行中メソッド
	int GetEnemy() {
		return GetenemyMax;
	}

private:
	int GetenemyMax = 0;
};
