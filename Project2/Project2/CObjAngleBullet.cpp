//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\HitboxManager.h"
#include "GameHead.h"
#include "CObjAngleBullet.h"



//使用するゲームスペース
using namespace GameL;


//コンストラクタ
CObjAngleBullet::CObjAngleBullet(float x, float y, float r)
{
    m_x = x;
    m_y = y;
    m_r = r;
}


//イニシャライズ
void CObjAngleBullet::Init()
{
    CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
    if (hero != nullptr)
    {
        CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
        m_scroll_map_x = block->GetSX();
        m_scroll_map_y = block->GetSY();

        float hx = hero->GetX();
        float hy = hero->GetY();

        //敵から主人公のベクトルを求める
        float x = m_x - hx + m_scroll_map_x;
        float y = m_y - hy + m_scroll_map_y;

        m_vx = cos(3.14 / 180 * m_r);
        m_vy = sin(3.14 / 180 * m_r);


    }

    m_time = 0.0f;
    //当たり判定用ヒットボックスを作成
    Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ANGLE_BULLET2, 1);

  
}


//アクション
void CObjAngleBullet::Action()
{
    m_time++;

    CHitBox* hit = Hits::GetHitBox(this);
    //移動
    m_x += m_vx * 1;
    m_y -= m_vy * 1;



}


//ドロー
void CObjAngleBullet::Draw()
{
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };
    
    RECT_F src;//描画切り取り位置
    RECT_F dst;//描画表示位置
    
    //切り取り位置
    src.m_top = 0.0f;
    src.m_left = 96.0f;
    src.m_right = 126.0f;
    src.m_bottom = 32.0f;

    //表示位置の設定
    dst.m_top = 0.0f + m_y;
    dst.m_left = 0.0f + m_x;
    dst.m_right = 32.0f + m_x;
    dst.m_bottom = 32.0f + m_y;
    
    Draw::Draw(0, &src, &dst,c, m_r);
           
}