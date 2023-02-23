#include<SmallRock.h>
#include<Game.h>

SmallRock::SmallRock(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void SmallRock::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::SmallRock);
}

void SmallRock::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	//shape.SetAsBox(5.5f, 0.25f);  // NE
	b2Vec2 vertices[5];
	vertices[0].Set(-0.2f, 0.36f);
	vertices[1].Set(-0.4f, -0.3f);
	vertices[2].Set(-0.4f, -0.4f);
	vertices[3].Set(0.4f, -0.4f);
	vertices[4].Set(0.4f, 0.36f);
	shape.Set(vertices, 5);
	body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void SmallRock::SetWidthHeight()
{
	width = 80;
	height = 80;
}

void SmallRock::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 40;
	vec.y -= 40;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}