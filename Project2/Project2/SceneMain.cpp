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
	

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMGame.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMGame2.wav", BACK_MUSIC);

	Audio::LoadAudio(10, L"SE�e���ˉ�.wav", EFFECT);
	Audio::LoadAudio(11, L"SE�e�l����.wav", EFFECT);
	Audio::LoadAudio(12, L"SE�G���j��.wav", EFFECT);
	Audio::LoadAudio(13, L"SE�G�e���e��.wav", EFFECT);
	Audio::LoadAudio(14, L"SE��e���e��.wav", EFFECT);

	//�{�����[����1.0���₷
	Audio::VolumeMaster(1.0f);

	//���y�X�^�[�g
	Audio::Start(0);

	//��l���O���t�B�b�N�ǂݍ���(300�~300)
	Draw::LoadImageW(L"��������5.png", 1, TEX_SIZE_512);
	//�G�̒e�iBB�e�j
	Draw::LoadImageW(L"EnemyBB.png", 2, TEX_SIZE_512);
	//��
	Draw::LoadImageW(L"����.png", 3, TEX_SIZE_512);

	//�{�X���
	Draw::LoadImageW(L"���ɃS���@��.png", 5, TEX_SIZE_512);
	//�S�@�U��
	Draw::LoadImageW(L"�܂ꂽ�c.png", 6, TEX_SIZE_512);
	//�G��ԁi3�����e�j
	Draw::LoadImageW(L"�S�g�����vK.png", 7, TEX_SIZE_512);
	//�{�X���2
	Draw::LoadImageW(L"�C�@��.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"�y��.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"�}��.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"����.png", 11, TEX_SIZE_512);
	//�G�t�F�N�g
	Draw::LoadImageW(L"������G�t�F�N�g.png", 12, TEX_SIZE_512);
	//��
	Draw::LoadImageW(L"hako.png", 13, TEX_SIZE_512);
	//�e
	Draw::LoadImageW(L"�哤.jpg", 14, TEX_SIZE_512);
	//��l���i�l�j
	Draw::LoadImageW(L"���@�Î~.png", 15, TEX_SIZE_512);

	//�����
	Draw::LoadImageW(L"hako.png", 17, TEX_SIZE_512);
	//�G���
	Draw::LoadImageW(L"�S�g�����vJ.png", 19, TEX_SIZE_512);
	//�G�@�S
	Draw::LoadImageW(L"���Ƀ{�^��.png", 20, TEX_SIZE_512);
	//�󂷂Ɠ����o�锠
	Draw::LoadImageW(L"����.jpg", 21, TEX_SIZE_512);
	//��l���i�l�j�̍U��
	Draw::LoadImageW(L"��l���ߐڍU���i���j.png", 22, TEX_SIZE_512);

	//���[�U�[�C���^�[�t�F�[�X�Ŏg�p����摜�W---------------------------------------------/
	Draw::LoadImageW(L"heart.png", 23, TEX_SIZE_512);	    //��ԁ@�̗͕̑\��
	Draw::LoadImageW(L"heart2.png", 24, TEX_SIZE_512);      //�l�@�@�̗͕̑\��
	Draw::LoadImageW(L"testsave.png", 25, TEX_SIZE_512);
	Draw::LoadImageW(L"alphaboard.png", 26, TEX_SIZE_512);
	Draw::LoadImageW(L"button.png", 27, TEX_SIZE_512);
	Draw::LoadImageW(L"buttonstr.png", 28, TEX_SIZE_512);
	Draw::LoadImageW(L"fader.png", 29, TEX_SIZE_512);
	Draw::LoadImageW(L"material.png", 31, TEX_SIZE_512);
	//-------------------------------------------------------------------------------------/

		//��l���\��
	CObjHero* obj = new CObjHero(0, 0, 180);
	Objs::InsertObj(obj, OBJ_HERO, 10);

	CObjChara* obj_c = new CObjChara(300, 300);
	Objs::InsertObj(obj_c, OBJ_CHARA, 10);

	//���[�U�[�C���^�t�F�[�X
	CObjUserInterface* obj_ui = new CObjUserInterface();

	obj_ui->setMAXenemy(GetenemyMax);
	obj_ui->setStage(Stage+1);
	obj_ui->flugset(true);

	CObjMinimap* minimap = new CObjMinimap(map);
	Objs::InsertObj(minimap, OBJ_MINIMAP, 1000);

	//obj_ui->NextStageProcess();
	Objs::InsertObj(obj_ui, OBJ_USERINTERFACE, 2000);

	//block�I�u�W�F�N�g�̍쐬
	CObjBlock* obj_b = new CObjBlock(map);
	Objs::InsertObj(obj_b, OBJ_BLOCK, 4);
}


//���s�����\�b�h
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