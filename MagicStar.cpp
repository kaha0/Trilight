#include<Game.h>
#include<MagicStar.h>

MagicStar::MagicStar(TextureStorage * ts, b2Vec2 pos)
{
	fps = 3;
	framesdrawn = 0;
	width = height = 8;
	position = pos;

	imgs = new RoundList();

	LPDIRECT3DTEXTURE9 tex;
	tex = ts->GetTexture(TextureStorage::MagicStar6);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar5);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar4);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar3);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar2);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar1);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar2);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar3);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar4);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar5);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar6);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar7);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar6);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar5);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar4);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar3);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar4);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar5);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar6);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar7);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar8);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::MagicStar9);
	imgs->Add(new Sprite(tex, true));

	sprite = imgs->First;
}

void MagicStar::GetTextures(TextureStorage * ts)
{
	Sprite * aux = imgs->First;
	aux->img = ts->GetTexture(TextureStorage::MagicStar6);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar5);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar4);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar3);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar2);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar1);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar2);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar3);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar4);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar5);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar6);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar7);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar6);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar5);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar4);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar3);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar4);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar5);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar6);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar7);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar8);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::MagicStar9);
}

void MagicStar::NextSprite()
{
	if (!sprite->terminal) sprite = sprite->next;
}

void MagicStar::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (sprite->terminal) return;
	if (!Game::ShouldIDraw(this)) return;

	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}

MagicStar::~MagicStar()
{
	delete imgs;
}