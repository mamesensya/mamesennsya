//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include"GameL\UserData.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"
#include "Objblock.h"
#include"Objbreakblock.h"
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
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;            //�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"Book1.csv", &size);//�O���f�[�^�ǂݍ���

		int map[60][80];
		int count = 1;
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
	

	//p = Save::ExternalDataOpen(L"Book2.csv", &size);//�O���f�[�^�ǂݍ���

	//p = Save::ExternalDataOpen(L"Book3.csv", &size);//�O���f�[�^�ǂݍ���

	//p = Save::ExternalDataOpen(L"Book4.csv", &size);//�O���f�[�^�ǂݍ���

	//p = Save::ExternalDataOpen(L"Book5.csv", &size);//�O���f�[�^�ǂݍ���


	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMGame.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMGame2.wav", BACK_MUSIC);
	Audio::LoadAudio(2, L"BGMBoss�i���j.wav", BACK_MUSIC);

	Audio::LoadAudio(10, L"SE�e���ˉ�.wav", EFFECT);
	Audio::LoadAudio(11, L"SE�e�l����.wav", EFFECT);
	Audio::LoadAudio(12, L"SE�G���j��.wav", EFFECT);
	Audio::LoadAudio(13, L"SE�G�e���e��.wav", EFFECT);
	Audio::LoadAudio(14, L"SE��e���e��.wav", EFFECT);

	//�{�����[����1.5���₷
	float v = Audio::VolumeMaster(1.0f);

	//���y�X�^�[�g
	Audio::Start(0);

	////���y�X�g�b�v
	//Audio::Stop(0);

	//�G�̒e�iBB�e�j
	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);

	//�G���
	Draw::LoadImageW(L"�S�g�����vJ.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"�S�g�����vK.png", 7, TEX_SIZE_512);
	//Draw::LoadImageW(L"�S�g�����vQ.png", 8, TEX_SIZE_512);

	////�G��ԁi3�����e�j
	//CObjEnemy3* obj_enemy3 = new CObjEnemy3(350, 250);
	//Objs::InsertObj(obj_enemy3, OBJ_ENEMY3, 51);

	//�{�X���
	Draw::LoadImageW(L"���ɃS���@��.png", 5, TEX_SIZE_512);
	//CObjBoss* obj_bossenemy = new CObjBoss(400, 300);
	//Objs::InsertObj(obj_bossenemy, OBJ_BOSS, 52);

	//�{�X���2
	Draw::LoadImageW(L"�y��.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"�C�@��.png", 8, TEX_SIZE_512);
	//CObjBoss2* obj_boss2 = new CObjBoss2(400, 300);
	//Objs::InsertObj(obj_boss2, OBJ_BOSS2, 20);

	//�G�@�S
	Draw::LoadImageW(L"���Ƀ{�^��.png", 4, TEX_SIZE_512);

	Draw::LoadImageW(L"�܂ꂽ�c.png", 6, TEX_SIZE_512);

	//��l���O���t�B�b�N�ǂݍ���(300�~300)
	Draw::LoadImageW(L"��������5.png", 19, TEX_SIZE_512);

	//��l���\��
	CObjHero* obj = new CObjHero(0,0);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//�e
	Draw::LoadImageW(L"�哤.jpg", 14, TEX_SIZE_512);

	//��l���i�l�j
	Draw::LoadImageW(L"���@�Î~.png", 21, TEX_SIZE_512);

	//��l���i�l�j�̍U��
	Draw::LoadImageW(L"��l���ߐڍU���i���j.png", 22, TEX_SIZE_512);

	//��
	Draw::LoadImageW(L"hako.png", 13, TEX_SIZE_512);
	
	//��
	Draw::LoadImageW(L"����.png", 3, TEX_SIZE_512);

	//���[�U�[�C���^�[�t�F�[�X�Ŏg�p����摜�W---------------------------------------------/
	Draw::LoadImageW(L"heart.png", 23, TEX_SIZE_512);	    //��ԁ@�̗͕̑\��
	Draw::LoadImageW(L"heart2.png", 24, TEX_SIZE_512);      //�l�@�@�̗͕̑\��
	Draw::LoadImageW(L"testsave.png", 25, TEX_SIZE_512);
	Draw::LoadImageW(L"alphaboard.png", 26, TEX_SIZE_512);
	Draw::LoadImageW(L"button.png", 27, TEX_SIZE_512);
	Draw::LoadImageW(L"buttonstr.png", 28, TEX_SIZE_512);
	//-------------------------------------------------------------------------------------/

	//�󂷂Ɠ����o�锠
	Draw::LoadImageW(L"����.jpg", 15, TEX_SIZE_512);
	/*CObjBox* obj_box = new CObjBox(400, 300);
	Objs::InsertObj(obj_box, OBJ_BOX, 11);*/

	//�����
	Draw::LoadImageW(L"hako.png", 17, TEX_SIZE_512);
	//CObjbreakblock* obj_break_block = new CObjbreakblock(200, 300);
	//Objs::InsertObj(obj_break_block, OBJ_BREAK_BLOCK, 17);

	//���[�U�[�C���^�t�F�[�X
	CObjUserInterface* obj_ui = new CObjUserInterface();

	obj_ui->setMAXenemy(GetenemyMax);
	Objs::InsertObj(obj_ui, OBJ_USERINTERFACE, 18);
	//CObjbreakblock* obj_break_block = new CObjbreakblock(200, 300);
	//Objs::InsertObj(obj_break_block, OBJ_BREAK_BLOCK, 17);

	//block�I�u�W�F�N�g�̍쐬
	CObjBlock* obj_b = new CObjBlock(map);
	Objs::InsertObj(obj_b, OBJ_BLOCK, 4);

	//�G�t�F�N�g
	Draw::LoadImageW(L"������G�t�F�N�g.png", 0,TEX_SIZE_512);
	Effect* f = new Effect(0,0);
	Objs::InsertObj(f, OBJ_EFFECT, 0);
	//Effect* of = new Effect(150,240);

}


//���s�����\�b�h
void CSceneMain::Scene()
{

}