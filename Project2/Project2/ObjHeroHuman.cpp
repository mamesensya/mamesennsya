//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjHeroHuman.h"

using namespace GameL;

void CObjHeroHuman::Init()
{

}

void CObjHeroHuman::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_hero_flag = hero->Hero();
	//�l��ԁ���ԏ�Ԃ�
	if (m_hero_flag == true)
	{
		//��l�����l��ԂɈڍs
		if (Input::GetVKey('V') == true)
		{
			m_hero_flag = false;
			//�`���^�����O�h�~�p
			while (Input::GetVKey('V') == true);
		}
	}



}

void CObjHeroHuman::Draw()
{

}