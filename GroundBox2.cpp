#include<GroundBox2.h>
#include<Game.h>

GroundBox2::GroundBox2(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void GroundBox2::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::GroundBox2);
}

void GroundBox2::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	//shape.SetAsBox(10.0f, 2.5f);
	b2Vec2 vertices[6];
	vertices[0].Set(-9.95f, 2.5f);
	vertices[1].Set(-10.0f, 2.45f);
	vertices[2].Set(-10.0f, -2.5f);
	vertices[3].Set(10.0f, -2.5f);
	vertices[4].Set(10.0f, 2.45f);
	vertices[5].Set(9.95f, 2.5f);
	shape.Set(vertices, 6);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.5f;
	body->CreateFixture(&fixtureDef);
	//body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void GroundBox2::SetWidthHeight()
{
	width = 2000;
	height = 500;
}

void GroundBox2::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 1000;
	vec.y -= 250;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}