#include<Grass2.h>
#include<Game.h>

Grass2::Grass2(TextureStorage * ts)
{
	Grass2(ts, b2Vec2(0.0f, 0.0f));
}

Grass2::Grass2(TextureStorage * ts, b2Vec2 pos)
{
	position = pos;
	fps = 7;
	framesdrawn = 0;
	SetWidthHeight();

	imgs = new RoundList();
	LPDIRECT3DTEXTURE9 tex = ts->GetTexture(TextureStorage::Grass2);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Grass3);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Grass4);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Grass5);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Grass6);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Grass7);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Grass8);
	imgs->Add(new Sprite(tex, false));
	//tex = ts->GetTexture(TextureStorage::Grass2);
	//imgs->Add(new Sprite(tex, false));

	sprite = imgs->First;
}

void Grass2::GetTextures(TextureStorage * ts)
{
	Sprite * aux = imgs->First;
	aux->img = ts->GetTexture(TextureStorage::Grass1);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Grass2);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Grass3);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Grass4);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Grass5);
	//aux = aux->next;
	//aux->img = ts->GetTexture(TextureStorage::Grass4);
	//aux = aux->next;
	//aux->img = ts->GetTexture(TextureStorage::Grass3);
	//aux = aux->next;
	//aux->img = ts->GetTexture(TextureStorage::Grass2);
}

void Grass2::NextSprite()
{
	if (sprite) sprite = sprite->next;
}

void Grass2::SetWidthHeight()
{
	width = 1000;
	height = 25;
}

void Grass2::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}