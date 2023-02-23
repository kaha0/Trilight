#include<Grass1.h>
#include<Game.h>

Grass1::Grass1(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	SetWidthHeight();
}

Grass1::Grass1(TextureStorage * ts, b2Vec2 pos)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	SetWidthHeight();
	position = pos;
}

void Grass1::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Grass1);
}

void Grass1::SetWidthHeight()
{
	width = 1000;
	height = 25;
}

void Grass1::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}