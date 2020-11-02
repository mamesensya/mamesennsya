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
	//�G�̒e�iBB�e�j
	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);


	//�G���
	Draw::LoadImageW(L"�G_���2.png", 1, TEX_SIZE_512);
	CObjEnemy* obj_enemy = new CObjEnemy(350,250);
	Objs::InsertObj(obj_enemy, OBJ_ENEMY, 50);

	//�{�X���
	Draw::LoadImageW(L"�{�X���.png", 5, TEX_SIZE_512);
	CObjBossEnemy* obj_bossenemy = new CObjBossEnemy(400, 300);
	Objs::InsertObj(obj_bossenemy, OBJ_BOSSENEMY, 52);

	//�G��ԁi3�����e�j
	CObjEnemy3* obj_enemy3 = new CObjEnemy3(350, 400);
	Objs::InsertObj(obj_enemy3, OBJ_ENEMY3, 51);
	
	

	//��l���O���t�B�b�N�ǂݍ���(400�~400)
	Draw::LoadImageW(L"test.png", 0, TEX_SIZE_512);
	//��l��
	CObjHero* obj = new CObjHero(700,500);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//�S
	Draw::LoadImageW(L"������.png", 4, TEX_SIZE_512);
	CObjGhost* obj_ghost = new CObjGhost(0,0);
	Objs::InsertObj(obj_ghost, OBJ_GHOST, 4);


	Draw::LoadImageW(L"hako.png", 13, TEX_SIZE_512);
	
	Draw::LoadImageW(L"����.jpg", 15, TEX_SIZE_512);
	CObjBox* obj_box = new CObjBox(400, 300);
	Objs::InsertObj(obj_box, OBJ_BOX, 11);

	Draw::LoadImageW(L"yuka.png", 3, TEX_SIZE_512);

	Draw::LoadImageW(L"�哤.jpg", 14, TEX_SIZE_512);
	CObjBlock* obj_block = new CObjBlock;
	Objs::InsertObj(obj_block, OBJ_BLOCK, 4);

//	Draw::LoadImageW(L"��l��_�l�i���j.jpg", 5, TEX_SIZE_512);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}