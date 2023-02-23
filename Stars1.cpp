#include<Stars1.h>
#include<Game.h>

Stars1::Stars1(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	startpos = b2Vec2(0.0f, 0.0f);
	coefX = 0.15f;
	coefY = 0.0f;
	SetWidthHeight();
}

Stars1::Stars1(TextureStorage * ts, b2Vec2 pos)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	startpos = pos;
	coefX = 0.15f;
	coefY = 0.0f;
	SetWidthHeight();
}

void Stars1::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Stars1);
}

void Stars1::SetWidthHeight()
{
	width = 1500;
	height = 1000;
}

void Stars1::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}