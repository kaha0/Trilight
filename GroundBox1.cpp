#include<GroundBox1.h>
#include<Game.h>

GroundBox1::GroundBox1(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void GroundBox1::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::GroundBox1);
}

void GroundBox1::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	//shape.SetAsBox(5.0f, 2.5f);
	b2Vec2 vertices[6];
	vertices[0].Set(-4.95f, 2.5f);
	vertices[1].Set(-5.0f, 2.45f);
	vertices[2].Set(-5.0f, -2.5f);
	vertices[3].Set(5.0f, -2.5f);
	vertices[4].Set(5.0f, 2.45f);
	vertices[5].Set(4.95f, 2.5f);
	shape.Set(vertices, 6);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.5f;
	body->CreateFixture(&fixtureDef);
	//body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void GroundBox1::SetWidthHeight()
{
	width = 1000;
	height = 500;
}

void GroundBox1::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 500;
	vec.y -= 250;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}