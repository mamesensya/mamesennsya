//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������\�b�h
void CSceneMain::InitScene()
{
	Draw::LoadImage(L"red.jpg", 0, TEX_SIZE_512);
	//�G�̒e�iBB�e�j
	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);
	CObjEnemyBullet* obj_enemybullet = new CObjEnemyBullet(300, 300);
	Objs::InsertObj(obj_enemybullet, OBJ_ENEMY_BULLET, 60);

	Draw::LoadImageW(L"�G_���2.png", 1, TEX_SIZE_512);
	CObjEnemy* obj_enemy = new CObjEnemy(300,300);
	Objs::InsertObj(obj_enemy, OBJ_ENEMY, 50);

	//��l���O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"��l��_���.png", 0, TEX_SIZE_512);
	//��l��
	CObjHero* obj = new CObjHero(0,0);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}