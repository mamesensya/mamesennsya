#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
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

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
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
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
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

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------



//�Q�[���J�n���̃V�[���N���X�o�^
//#define SET_GAME_START SceneTitle
#define SET_GAME_START SceneTitle
//#define SET_GAME_START CSceneGameClear
//-----------------------------------------------