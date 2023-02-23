#include<Game.h>
#include<Platform1.h>

Platform1::Platform1(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void Platform1::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Platform1);
}

void Platform1::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[6];
	vertices[0].Set(-1.4f, 0.25f);
	vertices[1].Set(-1.5f, 0.2f);
	vertices[2].Set(-1.5f, -0.25f);
	vertices[3].Set(1.5f, -0.25f);
	vertices[4].Set(1.5f, 0.2f);
	vertices[5].Set(1.4f, 0.25f);
	shape.Set(vertices, 6);
	body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void Platform1::SetWidthHeight()
{
	width = 300;
	height = 50;
}

void Platform1::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 150;
	vec.y -= 25;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}