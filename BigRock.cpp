#include<BigRock.h>
#include<Game.h>

BigRock::BigRock(TextureStorage * ts)
{
	fps = 0;
	framesdrawn = 0;
	drawenabled = true;
	reconstruct = true;
	whole = NULL;
	cracked = NULL;
	breaking = NULL;

	LPDIRECT3DTEXTURE9 aux;

	whole = new RoundList();
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_whole);
	whole->Add(new Sprite(aux, false));
	sprite = whole->First;

	cracked = new RoundList();
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_cracked);
	cracked->Add(new Sprite(aux, false));

	breaking = new RoundList();
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break01);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break02);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break03);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break04);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break05);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break06);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break07);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break08);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break09);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break10);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break11);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break12);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break13);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break14);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break15);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break16);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break17);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break18);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break19);
	breaking->Add(new Sprite(aux, false));
	aux = ts->GetTexture(TextureStorage::TexName::BigRock_break20);
	breaking->Add(new Sprite(aux, true));

	SetWidthHeight();
}

void BigRock::GetTextures(TextureStorage * ts)
{
	whole->First->img = ts->GetTexture(TextureStorage::TexName::BigRock_whole);

	cracked->First->img = ts->GetTexture(TextureStorage::TexName::BigRock_cracked);

	Sprite * aux = breaking->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break14);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break15);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break16);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break17);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break18);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break19);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::BigRock_break20);

	SetWidthHeight();
}

void BigRock::ConstructBody(b2World * w, b2Vec2 pos)
{
	drawenabled = true;
	sprite = whole->First;
	SetWidthHeight();

	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(1.1f, 0.9f);
	body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void BigRock::SetWidthHeight()
{
	if ((sprite == whole->First) || (sprite == cracked->First))
	{
		width = 250;
		height = 200;
	}
	else
	{
		width = 500;
		height = 200;
	}
}

void BigRock::NextSprite()
{
	if (sprite->terminal) return;
	sprite = sprite->next;
}

void BigRock::Bucked()
{
	if (sprite == whole->First)
	{
		sprite = cracked->First;
		return;
	}
	if (sprite == cracked->First)
	{
		sprite = breaking->First;
		fps = 2;
		framesdrawn = 0;
		SetWidthHeight();
	}
}

void BigRock::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!drawenabled) return;
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= (float)width / 2.0f;
	vec.y -= (float)height / 2.0f;
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}