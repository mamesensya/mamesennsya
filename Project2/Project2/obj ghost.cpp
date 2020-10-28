//使用ヘッダーふぁいる
#include"GameL/DrawTexture.h"
#include"GameL/SceneManager.h"
#include"GameL/HitBoxManager.h"


#include"GameHead.h"
#include"obj ghost.h"

//ネームスペース
using namespace GameL;

CObjghost::CObjghost()
{

}

void CObjghost::Init()
{

}

void CObjghost::Action()
{

}

void CObjghost::Draw()
{
	//カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 300.0f;

	//表示位置の設定
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 32.0f + 64.0f ;
	dst.m_bottom = 32.0f + 64.0f ;

	//描画
	Draw::Draw(0, &src, &dst, c,1);
}