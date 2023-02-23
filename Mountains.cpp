#include<Mountains.h>
#include<Game.h>

Mountains::Mountains(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	startpos = b2Vec2(0.0f, 0.0f);
	coefX = 0.1f;
	coefY = 0.0f;
	SetWidthHeight();
}

Mountains::Mountains(TextureStorage * ts, b2Vec2 pos)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	startpos = pos;
	coefX = 0.1f;
	coefY = 0.0f;
	SetWidthHeight();
}

void Mountains::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Mountains);
}

void Mountains::SetWidthHeight()
{
	width = 2000;
	height = 700;
}

void Mountains::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}