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
	void RoundChange();
	int GetEnemy() {
		return GetenemyMax;
	}
	void ChangeRound(int chg_r) {
		nextrounds = chg_r;
	}
private:
	int GetenemyMax = 0;
	int nextrounds = 0;
protected:
	int nextr = 0;
	
};

struct StageManages {
	int Stage;
};