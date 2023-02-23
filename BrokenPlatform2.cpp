#include<Game.h>
#include<BrokenPlatform2.h>

BrokenPlatform2::BrokenPlatform2(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void BrokenPlatform2::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::BrokenPlatform2);
}

void BrokenPlatform2::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[5];
	vertices[0].Set(-1.6f, 0.45f);
	vertices[1].Set(-3.0f, -0.05f);
	vertices[2].Set(3.0f, -0.05f);
	vertices[3].Set(3.0f, 0.4f);
	vertices[4].Set(2.9f, 0.45f);
	shape.Set(vertices, 5);
	body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void BrokenPlatform2::SetWidthHeight()
{
	width = 600;
	height = 90;
}

void BrokenPlatform2::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 300;
	vec.y -= 45;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}