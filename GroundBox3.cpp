#include<GroundBox3.h>
#include<Game.h>

GroundBox3::GroundBox3(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void GroundBox3::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::GroundBox3);
}

void GroundBox3::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[6];
	vertices[0].Set(-2.45f, 1.0f);
	vertices[1].Set(-2.5f, 0.95f);
	vertices[2].Set(-2.5f, -1.0f);
	vertices[3].Set(2.5f, -1.0f);
	vertices[4].Set(2.5f, 0.95f);
	vertices[5].Set(2.45f, 1.0f);
	shape.Set(vertices, 6);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.friction = 0.5f;
	body->CreateFixture(&fixtureDef);
	body->SetUserData((void *)this);
}

void GroundBox3::SetWidthHeight()
{
	width = 500;
	height = 200;
}

void GroundBox3::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 250;
	vec.y -= 100;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}