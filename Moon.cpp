#include<Moon.h>
#include<Game.h>

Moon::Moon(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	startpos.x = 8.0f;
	startpos.y = 8.0f;
	coefX = 0.20f;
	coefY = 0.0f;
	SetWidthHeight();
}

Moon::Moon(TextureStorage * ts, b2Vec2 pos)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	startpos = pos;
	coefX = 0.20f;
	coefY = 0.0f;
	SetWidthHeight();
}

void Moon::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Moon);
}

void Moon::SetWidthHeight()
{
	width = 700;
	height = 700;
}

void Moon::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}