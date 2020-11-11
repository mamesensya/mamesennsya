//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"
#include "Objblock.h"
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
	//敵の弾（BB弾）

	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);

	//敵戦車
	Draw::LoadImageW(L"敵_戦車2.png", 1, TEX_SIZE_512);
	CObjEnemy* obj_enemy = new CObjEnemy(350,250);
	Objs::InsertObj(obj_enemy, OBJ_ENEMY, 50);

	//敵戦車（3方向弾）
	CObjEnemy3* obj_enemy3 = new CObjEnemy3(350, 400);
	Objs::InsertObj(obj_enemy3, OBJ_ENEMY3, 51);

	//ボス戦車
	Draw::LoadImageW(L"ボス戦車.png", 5, TEX_SIZE_512);
	CObjBoss* obj_bossenemy = new CObjBoss(400, 300);
	Objs::InsertObj(obj_bossenemy, OBJ_BOSS, 52);

	
	

	//主人公グラフィック読み込み(400×400)
	Draw::LoadImageW(L"test.png", 20, TEX_SIZE_512);
	//主人公表示
	CObjHero* obj = new CObjHero(700,500);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//弾
	Draw::LoadImageW(L"大豆.jpg", 14, TEX_SIZE_512);
	CObjBlock* obj_block = new CObjBlock;
	Objs::InsertObj(obj_block, OBJ_BLOCK, 4);

	//主人公（人）
	Draw::LoadImageW(L"主人公_人（仮）.jpg", 21, TEX_SIZE_512);

	//主人公（人）の攻撃
	Draw::LoadImageW(L"主人公近接攻撃（仮）.png", 22, TEX_SIZE_512);

	//壁
	Draw::LoadImageW(L"hako.png", 13, TEX_SIZE_512);
	
	//床
	Draw::LoadImageW(L"yuka.png", 3, TEX_SIZE_512);

	//壊すと豆が出る箱
	Draw::LoadImageW(L"豆箱.jpg", 15, TEX_SIZE_512);
	CObjBox* obj_box = new CObjBox(400, 300);
	Objs::InsertObj(obj_box, OBJ_BOX, 11);
}

//実行中メソッド
void CSceneMain::Scene()
{

}