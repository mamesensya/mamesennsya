#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CObjMinimap : public CObj {
public:
	CObjMinimap(int map[60][80]);
	~CObjMinimap() {};
	void Init();
	void Action();
	void Draw();
private:
	int src_x = 0; //�X�N���[���̒l���擾����ׂ̕ϐ�
	int src_y = 0;
	int px = 0; //��l���̒��S���W���i�[����ׂ̕ϐ�
	int py = 0;
	int scroll_x = 0; //�~�j�}�b�v���X�N���[��������ۂɕK�v�ɂȂ�ϐ�
	int scroll_y = 0;
	int mapdata[60][80]; //�}�b�v�f�[�^�i�[�p
	int p, s;
	wchar_t str[128]; //�f�o�b�O���j�^�[�i���W�̕\���Ɏg���j
};