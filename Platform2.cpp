#include<Game.h>
#include<Platform2.h>

Platform2::Platform2(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void Platform2::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Platform2);
}

void Platform2::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[6];
	vertices[0].Set(-1.4f, 0.1f);
	vertices[1].Set(-1.5f, 0.0f);
	vertices[2].Set(-1.5f, -0.1f);
	vertices[3].Set(1.5f, -0.1f);
	vertices[4].Set(1.5f, 0.0f);
	vertices[5].Set(1.4f, 0.1f);
	shape.Set(vertices, 6);
	body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void Platform2::SetWidthHeight()
{
	width = 300;
	height = 20;
}

void Platform2::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 150;
	vec.y -= 10;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}