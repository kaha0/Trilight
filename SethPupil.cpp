#include<SethPupil.h>
#include<Game.h>

SethPupil::SethPupil(TextureStorage * ts, b2Vec2 pos)
{
	fps = 1;
	framesdrawn = 0;
	startpos = pos;
	coefX = 0.12f;
	coefY = 0.28f;
	SetWidthHeight();

	LPDIRECT3DTEXTURE9 tex;
	imgs = new RoundList();
	tex = ts->GetTexture(TextureStorage::TexName::Seth3_1);
	imgs->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::TexName::Seth3_2);
	imgs->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::TexName::Seth3_3);
	imgs->Add(new Sprite(tex, true));
	sprite = imgs->First;
}

void SethPupil::GetTextures(TextureStorage * ts)
{
	Sprite * aux = imgs->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::Seth3_1);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Seth3_2);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Seth3_3);
	aux = aux->next;
}

void SethPupil::SetWidthHeight()
{
	width = 70;
	height = 105;
}

void SethPupil::NextSprite()
{
	sprite = sprite->next;
}

void SethPupil::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}