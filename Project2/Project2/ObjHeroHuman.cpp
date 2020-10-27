//使用するヘッダーファイル
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
	//人状態→戦車状態へ
	if (m_hero_flag == true)
	{
		//主人公が人状態に移行
		if (Input::GetVKey('V') == true)
		{
			m_hero_flag = false;
			//チャタリング防止用
			while (Input::GetVKey('V') == true);
		}
	}



}

void CObjHeroHuman::Draw()
{

}