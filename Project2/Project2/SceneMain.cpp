//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include"GameL\UserData.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"
#include "Objblock.h"
#include"Objbreakblock.h"


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
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;            //ステージ情報の大きさ

	int map[60][80];
	int count = 1;
		switch (Stage) {
		case 0:
			p = Save::ExternalDataOpen(L"Book1.csv", &size);
			break;
		case 1:
			p = Save::ExternalDataOpen(L"Book2.csv", &size);
			break;
		case 2:
			p = Save::ExternalDataOpen(L"Book3.csv", &size);
			break;
		case 3:
			p = Save::ExternalDataOpen(L"Book4.csv", &size);
		default:
			break;
		};
	
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);
			if (w == 4 || w == 6) { GetenemyMax++; }
			map[i][j] = w;
			count += 2;
		}
	}
	

	//音楽読み込み
	Audio::LoadAudio(0, L"BGMGame.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMGame2.wav", BACK_MUSIC);

	Audio::LoadAudio(10, L"SE弾発射音.wav", EFFECT);
	Audio::LoadAudio(11, L"SE弾獲得音.wav", EFFECT);
	Audio::LoadAudio(12, L"SE敵爆破音.wav", EFFECT);
	Audio::LoadAudio(13, L"SE敵弾着弾音.wav", EFFECT);
	Audio::LoadAudio(14, L"SE主弾着弾音.wav", EFFECT);

	//ボリュームを1.0増やす
	Audio::VolumeMaster(1.0f);

	//音楽スタート
	Audio::Start(0);

	//主人公グラフィック読み込み(300×300)
	Draw::LoadImageW(L"さいころ5.png", 1, TEX_SIZE_512);
	//敵の弾（BB弾）
	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);
	//床
	Draw::LoadImageW(L"床改.png", 3, TEX_SIZE_512);

	//ボス戦車
	Draw::LoadImageW(L"おにゴム　赤.png", 5, TEX_SIZE_512);
	//鬼　攻撃
	Draw::LoadImageW(L"折れた芯.png", 6, TEX_SIZE_512);
	//敵戦車（3方向弾）
	Draw::LoadImageW(L"鬼トランプK.png", 7, TEX_SIZE_512);
	//ボス戦車2
	Draw::LoadImageW(L"砲　青.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"土台.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"枝豆.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"黒豆.png", 11, TEX_SIZE_512);
	//エフェクト
	Draw::LoadImageW(L"当たりエフェクト.png", 12, TEX_SIZE_512);
	//壁
	Draw::LoadImageW(L"hako.png", 13, TEX_SIZE_512);
	//弾
	Draw::LoadImageW(L"大豆.jpg", 14, TEX_SIZE_512);
	//主人公（人）
	Draw::LoadImageW(L"豆　静止.png", 15, TEX_SIZE_512);

	//壊れる壁
	Draw::LoadImageW(L"hako.png", 17, TEX_SIZE_512);
	//敵戦車
	Draw::LoadImageW(L"鬼トランプJ.png", 19, TEX_SIZE_512);
	//敵　鬼
	Draw::LoadImageW(L"おにボタン.png", 20, TEX_SIZE_512);
	//壊すと豆が出る箱
	Draw::LoadImageW(L"豆箱.jpg", 21, TEX_SIZE_512);
	//主人公（人）の攻撃
	Draw::LoadImageW(L"主人公近接攻撃（仮）.png", 22, TEX_SIZE_512);

	//ユーザーインターフェースで使用する画像集---------------------------------------------/
	Draw::LoadImageW(L"heart.png", 23, TEX_SIZE_512);	    //戦車　の体力表示
	Draw::LoadImageW(L"heart2.png", 24, TEX_SIZE_512);      //人　　の体力表示
	Draw::LoadImageW(L"testsave.png", 25, TEX_SIZE_512);
	Draw::LoadImageW(L"alphaboard.png", 26, TEX_SIZE_512);
	Draw::LoadImageW(L"button.png", 27, TEX_SIZE_512);
	Draw::LoadImageW(L"buttonstr.png", 28, TEX_SIZE_512);
	Draw::LoadImageW(L"fader.png", 29, TEX_SIZE_512);
	Draw::LoadImageW(L"material.png", 31, TEX_SIZE_512);
	//-------------------------------------------------------------------------------------/

		//主人公表示
	CObjHero* obj = new CObjHero(0, 0, 180);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	CObjChara* obj_c = new CObjChara(300, 300);
	Objs::InsertObj(obj_c, OBJ_CHARA, 10);

	//ユーザーインタフェース
	CObjUserInterface* obj_ui = new CObjUserInterface();

	obj_ui->setMAXenemy(GetenemyMax);
	obj_ui->setStage(Stage+1);
	obj_ui->flugset(true);

	CObjMinimap* minimap = new CObjMinimap(map);
	Objs::InsertObj(minimap, OBJ_MINIMAP, 1000);

	//obj_ui->NextStageProcess();
	Objs::InsertObj(obj_ui, OBJ_USERINTERFACE, 2000);

	//blockオブジェクトの作成
	CObjBlock* obj_b = new CObjBlock(map);
	Objs::InsertObj(obj_b, OBJ_BLOCK, 4);
}


//実行中メソッド
void CSceneMain::Scene()
{

}

void CSceneMain::RoundChange() {
	Stage++;
	
	CObjUserInterface* ui = (CObjUserInterface*)Objs::GetObj(OBJ_USERINTERFACE);
	ui->setStageStatus(2);
};

void CSceneMain::SStage() {
	Stage = 0;
};