#include<SleepBubble.h>
#include<Game.h>

SleepBubble::SleepBubble(TextureStorage * ts, b2Vec2 pos)
{
	fps = 8;
	framesdrawn = 0;
	position = pos;
	width = height = 200;

	LPDIRECT3DTEXTURE9 tex;
	imgs = new RoundList();
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_01);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_02);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_03);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_04);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_05);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_06);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_07);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_08);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_09);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_10);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_11);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_12);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_13);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_14);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_15);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::TexName::SleepBubble_16);
	imgs->Add(new Sprite(tex, false));
	sprite = imgs->First;
}

void SleepBubble::GetTextures(TextureStorage * ts)
{
	Sprite * aux = imgs->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_14);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_15);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::SleepBubble_16);
}

void SleepBubble::NextSprite()
{
	sprite = sprite->next;
}

void SleepBubble::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}