#include "GameHead.h"
#include "CObjMinimap.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"

using namespace GameL;

CObjMinimap::CObjMinimap(int map[60][80]) {
	memcpy(mapdata, map, sizeof(int) * (60 * 80)); //SceneMain�œǂݍ��񂾃}�b�v�f�[�^��ʂ̔z��ɃR�s�[
};

void CObjMinimap::Init() {
};

void CObjMinimap::Action() {
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO); //��l���̌��ݍ��W���擾����ׂɕK�v
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK); //�X�N���[���̒l���擾����ׂɕK�v
	CObjChara* chara = (CObjChara*)Objs::GetObj(OBJ_CHARA);
	
	src_x = (int)block->GetSX() - block->GetSX() - block->GetSX(); //�X�N���[���l�̔��]
	src_y = (int)block->GetSY() - block->GetSY() - block->GetSY();

	if (hero != nullptr) { //hero�I�u�W�F�N�g�����݂��Ă���ꍇ�݈̂ȉ��̏��������s
		flag = hero->m_hero_flag;
		px = ((hero->GetX() +src_x) + 40.0f) / 64;  //��l���̍��W�i���S����_�Ɂj�擾
		py = ((hero->GetY() +src_y) + 40.0f) / 64 ; //Y���i���S����_�Ɂj�擾

		if (px > 5 && px < 50) scroll_x = px-6; //��l����5�}�X�`50�}�X�ȓ��ɂ���ꍇ�̓X�N���[��������
		if (py > 5 && py < 70) scroll_y = py-6; //��l����5�}�X�`70�}�X�ȓ��ɂ���ꍇ�̓X�N���[��������
	}
	if (chara != nullptr) {
		bx = ((chara->GetX() + 24.0f + src_x)) / 64;
		by = ((chara->GetY() + 24.0f + src_y)) / 64; 
	}
};

void CObjMinimap::Draw() {
	//material number is 29 / minimap size 12math x 12 math (math size 20)

	RECT_F src;
	RECT_F dst;
	float c[4] = { 1.0f,1.0f,1.0f,0.5f };
	
	CObjUserInterface* ui = (CObjUserInterface*)Objs::GetObj(OBJ_USERINTERFACE);

	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 32.0f;
	src.m_bottom = 32.0f;

	dst.m_top    = 80.0f + 0.0f;
	dst.m_left   = 560.0f;
	dst.m_right  = dst.m_left + 240.0f;
	dst.m_bottom = dst.m_top  + 240.0f;

	Draw::Draw(29, &src, &dst, c, 0);
	
	for (p=0; p < 24; p++) {

		for (s=0; s < 24; s++) {
			dst.m_top    = 80.0f+ p * 10.0f;
			dst.m_left   = 560.0f + s * 10.0f;
			dst.m_right  = dst.m_left + 10.0f;
			dst.m_bottom = dst.m_top + 10.0f;

			if (mapdata[scroll_y + p][scroll_x + s] == 1) {
				c[0] = 1.0f; c[1] = 1.0f; c[2] = 1.0f; c[3] = 0.5f;
				Draw::Draw(31, &src, &dst, c, 0);
			}
			if (mapdata[scroll_y + p][scroll_x + s] == 3 && ui->GetEM() != 0) {
				c[0] = 0.0f; c[1] = 1.0f; c[2] = 0.0f; c[3] = 0.5f;
				Draw::Draw(31, &src, &dst, c, 0);
			}
			if (mapdata[scroll_y + p][scroll_x + s] == 2) {
				c[0] = 1.0f; c[1] = 1.0f; c[2] = 0.0f; c[3] = 0.5f;
				Draw::Draw(31, &src, &dst, c, 0);
			}

		}

	}
	//�~�j�}�b�v�ɐ�Ԃ�����ꏊ��ԐF�̃|�C���^�[�ŕ\��
	c[0] = 1.0f; c[1] = 0.0f; c[2] = 0.0f; c[3] = 1.0f;

	dst.m_top = 80.0f + py * 10.0f;
	dst.m_left = 560.0f + px * 10.0f;
	dst.m_right = dst.m_left + 10.0f;
	dst.m_bottom = dst.m_top + 10.0f;

	//�~�j�}�b�v�̃X�N���[���ɍ��킹��X���W�̈ʒu�𒲐�
	 if (px > 6 && px < 50) {
		dst.m_top = dst.m_top;
		dst.m_left = 620.0f;
		dst.m_right = dst.m_left + 10.0f;
		dst.m_bottom = dst.m_top + 10.0f;
	}

	//�~�j�}�b�v�̃X�N���[���ɍ��킹��Y���W�̈ʒu�𒲐�
	if (py > 6 && py < 70) {
		dst.m_top = 140.0f;
		dst.m_left = dst.m_left;
		dst.m_right = dst.m_left + 10.0f;
		dst.m_bottom = dst.m_top + 10.0f;
	}

	Draw::Draw(31, &src, &dst, c, 0);

	//��l���̂���ꏊ���~�j�}�b�v��ɃI�����W�F�̃|�C���^�[�ŕ\��
	c[0] = 1.0f; c[1] = 0.5f; c[2] = 0.0f; c[3] = 1.0f;
	dst.m_top = 80.0f + by * 10.0f;
	dst.m_left = 560.0f + bx * 10.0f;
	dst.m_right = dst.m_left + 10.0f;
	dst.m_bottom = dst.m_top + 10.0f;
	
	if (flag == true) {	
		//�~�j�}�b�v�̃X�N���[���ɍ��킹��X���W�̈ʒu�𒲐�
		if (bx > 6 && bx < 50) {
			dst.m_top = dst.m_top;
			dst.m_left = 560.0f + bx * 10.0f - (scroll_x *10);
			dst.m_right = dst.m_left + 10.0f;
			dst.m_bottom = dst.m_top + 10.0f;
		}

		//�~�j�}�b�v�̃X�N���[���ɍ��킹��Y���W�̈ʒu�𒲐�
		if (by > 6 && by < 70) {
			dst.m_top = 80.0f + by * 10.0f -(scroll_y * 10);
			dst.m_left = dst.m_left;
			dst.m_right = dst.m_left + 10.0f;
			dst.m_bottom = dst.m_top + 10.0f;
		}
		Draw::Draw(31, &src, &dst, c, 0);
	}
	else {
		oldbx = bx;
		oldby = by;
	}


	c[0] = 0.0f; c[1] = 0.0f; c[2] = 0.0f; c[3] = 1.0f;
	////�f�o�b�O
	//swprintf_s(str, L"��l���@px=%d,py=%d", px, py);
	//Font::StrDraw(str, 100, 100, 20, c);
	//swprintf_s(str, L"���@�@�@bx=%d,by=%d", bx, by);
	//Font::StrDraw(str, 100, 120, 20, c);
	//swprintf_s(str, L"���@�@�@fix_x=%d", (int)590-((oldbx - bx) * 10));
	//Font::StrDraw(str, 100, 140, 20, c);
	//swprintf_s(str, L"���@,   fix_y=%d", (int)80- ((oldby - by) * 10));
	//Font::StrDraw(str, 100, 160, 20, c);
};

void CObjMinimap::MapReload(int map[60][80]) {
	memcpy(mapdata, map, sizeof(int) * (60 * 80));
};