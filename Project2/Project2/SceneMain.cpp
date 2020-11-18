//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"
#include "Objblock.h"
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
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMGame�i���j.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMGame2�i���j.wav", BACK_MUSIC);
	Audio::LoadAudio(2, L"BGMBoss�i���j.wav", BACK_MUSIC);

	Audio::LoadAudio(10, L"SE�e���ˉ�.wav", EFFECT);
	Audio::LoadAudio(11, L"SE�e�l����.wav", EFFECT);
	Audio::LoadAudio(12, L"SE�G���j��.wav", EFFECT);

	//�{�����[����1.5���₷
	float v = Audio::VolumeMaster(1.5f);

	//���y�X�^�[�g
	Audio::Start(0);

	//�G�̒e�iBB�e�j
	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);

	//�G���
	//Draw::LoadImageW(L"�G_���2.png", 1, TEX_SIZE_512);

	//CObjEnemy* obj_enemy = new CObjEnemy(350,250);
	//Objs::InsertObj(obj_enemy, OBJ_ENEMY, 50);

	////�G��ԁi3�����e�j
	//CObjEnemy3* obj_enemy3 = new CObjEnemy3(350, 400);
	//Objs::InsertObj(obj_enemy3, OBJ_ENEMY3, 51);

	//�{�X���
	Draw::LoadImageW(L"�{�X���.png", 5, TEX_SIZE_512);
	CObjBoss* obj_bossenemy = new CObjBoss(100,100);
	Objs::InsertObj(obj_bossenemy, OBJ_BOSS, 52);

	//�G�@�S
	Draw::LoadImageW(L"������.png", 4, TEX_SIZE_512);
	CObjGhost* obj_ghost = new CObjGhost(200, 300);
	Objs::InsertObj(obj_ghost, OBJ_GHOST, 52);

	Draw::LoadImageW(L"���_.png", 6, TEX_SIZE_512);

	//��l���O���t�B�b�N�ǂݍ���(400�~400)
	Draw::LoadImageW(L"test.png", 20, TEX_SIZE_512);
	//��l���\��
	CObjHero* obj = new CObjHero(200,200);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//�e
	Draw::LoadImageW(L"�哤.jpg", 14, TEX_SIZE_512);
	CObjBlock* obj_block = new CObjBlock;
	Objs::InsertObj(obj_block, OBJ_BLOCK, 4);

	//��l���i�l�j
	Draw::LoadImageW(L"��l��_�l�i���j.jpg", 21, TEX_SIZE_512);

	//��l���i�l�j�̍U��
	Draw::LoadImageW(L"��l���ߐڍU���i���j.png", 22, TEX_SIZE_512);

	//��
	Draw::LoadImageW(L"hako.png", 13, TEX_SIZE_512);
	
	//��
	Draw::LoadImageW(L"yuka.png", 3, TEX_SIZE_512);

	//���[�U�[�C���^�[�t�F�[�X�Ŏg�p����摜�W---------------------------------------------/
	Draw::LoadImageW(L"heart.png", 23, TEX_SIZE_512);	    //��ԁ@�̗͕̑\��
	Draw::LoadImageW(L"heart2.png", 24, TEX_SIZE_512);      //�l�@�@�̗͕̑\��
	Draw::LoadImageW(L"testsave.png", 25, TEX_SIZE_512);
	//-------------------------------------------------------------------------------------/

	//�󂷂Ɠ����o�锠
	Draw::LoadImageW(L"����.jpg", 15, TEX_SIZE_512);
	CObjBox* obj_box = new CObjBox(400, 300);
	Objs::InsertObj(obj_box, OBJ_BOX, 11);
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}