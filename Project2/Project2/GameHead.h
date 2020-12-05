#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_ENEMY,
	OBJ_ENEMY_BULLET,
	OBJ_BLOCK,
	OBJ_BULLET,
	OBJ_GHOST,
	OBJ_CHARA,
	OBJ_ENEMY_3BULLET,
	OBJ_ENEMY3,
	OBJ_BOX,
	OBJ_ATTACK,
	OBJ_BEAN,
	OBJ_BOSS,
	OBJ_BOSS_BULLET,
	OBJ_GHOST_ATTACK,
	OBJ_TITLE,
	OBJ_TITLEFONT,
	OBJ_SAVE,
	OBJ_USERINTERFACE,
	OBJ_BOSS2,
	OBJ_BOSS_BULLET2,
	OBJ_BREAK_BLOCK,
	OBJ_ANGLE_BULLET2,
	OBJ_BOSS_BULLET4,
	OBJ_PENETRATE_BULLET,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_CHARA,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjHero.h"
#include"Enemy.h"
#include"CObjEnemyBullet.h"
#include"CObjPlayerBullet.h"
#include"ObjGhost.h"
#include "Enemy.h"
#include "CObjEnemyBullet.h"
#include "Objblock.h"
#include "CObjPlayerBullet.h"
#include "CObjpenetrateBullet.h"
#include"CObjEnemy3Bullet.h"
#include"CObjEnemy3.h"
#include "ObjChara.h"
#include "ObjBox.h"
#include "ObjBean.h"
#include "CObjAttack.h"
#include"CObjBoss.h"
#include"CObjBossBullet.h"
#include"OBJGhostAttack.h"
#include"objTitle.h"
#include "ObjSaveSys.h"
#include "ObjUserInterface.h"
#include "CObjBoss2.h"
#include "CObjBossBullet2.h"
#include "CObjBossBullet4.h"
#include "SecondStage.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------



//ゲーム開始時のシーンクラス登録
//#define SET_GAME_START SceneTitle
#define SET_GAME_START SceneTitle
//#define SET_GAME_START CSceneGameClear
//-----------------------------------------------