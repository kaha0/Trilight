#include<Game.h>
#include<BrokenPlatform1.h>

BrokenPlatform1::BrokenPlatform1(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void BrokenPlatform1::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::BrokenPlatform1);
}

void BrokenPlatform1::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[5];
	vertices[0].Set(-2.9f, 0.25f);
	vertices[1].Set(-3.0f, 0.2f);
	vertices[2].Set(-3.0f, -0.25f);
	vertices[3].Set(3.0f, -0.25f);
	vertices[4].Set(3.0f, 0.25f);
	shape.Set(vertices, 5);
	body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void BrokenPlatform1::SetWidthHeight()
{
	width = 600;
	height = 50;
}

void BrokenPlatform1::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 300;
	vec.y -= 25;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}