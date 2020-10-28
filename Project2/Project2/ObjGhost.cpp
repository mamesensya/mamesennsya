//使用ヘッダーふぁいる
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"ObjGhost.h"

//ネームスペース
using namespace GameL;

CObjGhost::CObjGhost()
{

}

void CObjGhost::Init()
{

}

void CObjGhost::Action()
{

}

void CObjGhost::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	//表示位置の設定
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right =  400.0f;
	dst.m_bottom = 400.0f ;

	//描画
	Draw::Draw(4, &src, &dst, c,0.0f);
}