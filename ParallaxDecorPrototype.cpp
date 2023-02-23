#include<ParallaxDecorPrototype.h>
#include<Game.h>

ParallaxDecorPrototype::ParallaxDecorPrototype(TextureStorage * ts, TextureStorage::TexName texture)
{
	tname = texture;
	GetTextures(ts);
	coefX = 0.0f;
	coefY = 0.0f;
	fps = 0;
	framesdrawn = 0;
	SetWidthHeight();
}

ParallaxDecorPrototype::ParallaxDecorPrototype(TextureStorage * ts, TextureStorage::TexName texture, b2Vec2 pos)
{
	tname = texture;
	GetTextures(ts);
	coefX = 0.0f;
	coefY = 0.0f;
	fps = 0;
	framesdrawn = 0;
	SetWidthHeight();
	startpos = pos;
}

void ParallaxDecorPrototype::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(tname);
}

void ParallaxDecorPrototype::SetWidthHeight()
{
	D3DSURFACE_DESC surfaceDesc;
	img->GetLevelDesc(0, &surfaceDesc); 
	width = surfaceDesc.Width;
	height = surfaceDesc.Height;
}

void ParallaxDecorPrototype::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}