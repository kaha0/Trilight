#include<StaticDecorPrototype.h>
#include<Game.h>

StaticDecorPrototype::StaticDecorPrototype(TextureStorage * ts, TextureStorage::TexName texture)
{
	tname = texture;
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	SetWidthHeight();
}

StaticDecorPrototype::StaticDecorPrototype(TextureStorage * ts, TextureStorage::TexName texture, b2Vec2 pos)
{
	tname = texture;
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	SetWidthHeight();
	position = pos;
}

void StaticDecorPrototype::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(tname);
}

void StaticDecorPrototype::SetWidthHeight()
{
	D3DSURFACE_DESC surfaceDesc;
	img->GetLevelDesc(0, &surfaceDesc); 
	width = surfaceDesc.Width;
	height = surfaceDesc.Height;
}

void StaticDecorPrototype::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}