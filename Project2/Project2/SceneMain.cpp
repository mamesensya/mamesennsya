//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	Draw::LoadImage(L"red.jpg", 0, TEX_SIZE_512);
	//敵の弾（BB弾）
	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);
	CObjEnemyBullet* obj_enemybullet = new CObjEnemyBullet(300, 300);
	Objs::InsertObj(obj_enemybullet, OBJ_ENEMY_BULLET, 60);

	Draw::LoadImageW(L"敵_戦車2.png", 1, TEX_SIZE_512);
	CObjEnemy* obj_enemy = new CObjEnemy(300,300);
	Objs::InsertObj(obj_enemy, OBJ_ENEMY, 50);

	//主人公グラフィック読み込み
	Draw::LoadImageW(L"主人公_戦車.png", 0, TEX_SIZE_512);
	//主人公
	CObjHero* obj = new CObjHero(0,0);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	

}

//実行中メソッド
void CSceneMain::Scene()
{

}