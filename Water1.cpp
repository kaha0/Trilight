#include<Game.h>
#include<Water1.h>

Water1::Water1(TextureStorage * ts)
{
	fps = 6;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();

	imgs = new RoundList();
	LPDIRECT3DTEXTURE9 nutex = ts->GetTexture(TextureStorage::TexName::Water01);
	imgs->Add(new Sprite(nutex, false));
	nutex = ts->GetTexture(TextureStorage::TexName::Water02);
	imgs->Add(new Sprite(nutex, false));
	nutex = ts->GetTexture(TextureStorage::TexName::Water03);
	imgs->Add(new Sprite(nutex, false));
	sprite = imgs->First;
}

void Water1::GetTextures(TextureStorage * ts)
{
	Sprite * aux = imgs->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::Water01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Water02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Water03);
}

void Water1::NextSprite()
{
	sprite = sprite->next;
}

void Water1::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_staticBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	//shape.SetAsBox(0.5f, 0.5f);
	b2Vec2 vertices[4];
	vertices[0].Set(-5.0f, 1.3f);
	vertices[1].Set(-5.0f, -1.5f);
	vertices[2].Set(5.0f, -1.5f);
	vertices[3].Set(5.0f, 1.3f);
	shape.Set(vertices, 4);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.0f;
	fixtureDef.isSensor = true;
	body->CreateFixture(&fixtureDef);
	body->SetUserData((void *)this);
}

void Water1::SetWidthHeight()
{
	width = 1000;
	height = 300;
}

void Water1::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 500;
	vec.y -= 150;
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}