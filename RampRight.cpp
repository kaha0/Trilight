#include<Game.h>
#include<RampRight.h>

RampRight::RampRight(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void RampRight::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::Ramp_right);
}

void RampRight::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[4];
	vertices[0].Set(-1.28f, 0.6f);
	vertices[1].Set(-1.28f, -0.65f);
	vertices[2].Set(1.3f, -0.65f);
	vertices[3].Set(-1.2f, 0.64f);
	shape.Set(vertices, 4);
	body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void RampRight::SetWidthHeight()
{
	width = 256;
	height = 128;
}

void RampRight::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 128;
	vec.y -= 64;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}