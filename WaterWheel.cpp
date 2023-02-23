#include<Game.h>
#include<WaterWheel.h>

WaterWheel::WaterWheel(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void WaterWheel::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::WaterWheel);
}

void WaterWheel::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[8];
	vertices[0].Set(-1.03f, 2.5f);
	vertices[1].Set(-2.5f, 1.03f);
	vertices[2].Set(-2.5f, -1.03f);
	vertices[3].Set(-1.03f, -2.5f);
	vertices[4].Set(1.03f, -2.5f);
	vertices[5].Set(2.5f, -1.03f);
	vertices[6].Set(2.5f, 1.03f);
	vertices[7].Set(1.03f, 2.5f);
	shape.Set(vertices, 8);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 10.0f;
	fixtureDef.friction = 1.0f;
	body->CreateFixture(&fixtureDef);

	b2PolygonShape s2;
	s2.SetAsBox(0.4f, 0.3f, b2Vec2(-2.5f, -1.03f), 3.534f);
	body->CreateFixture(&s2, 0.0f);

	s2.SetAsBox(0.4f, 0.3f, b2Vec2(-2.5f, 1.03f), 2.749f);
	body->CreateFixture(&s2, 0.0f);

	s2.SetAsBox(0.4f, 0.3f, b2Vec2(-1.03f, 2.5f), 1.963f);
	body->CreateFixture(&s2, 0.0f);

	s2.SetAsBox(0.4f, 0.3f, b2Vec2(1.03f, 2.5f), 1.178f);
	body->CreateFixture(&s2, 0.0f);

	s2.SetAsBox(0.4f, 0.3f, b2Vec2(2.5f, 1.03f), 0.393f);
	body->CreateFixture(&s2, 0.0f);

	s2.SetAsBox(0.4f, 0.3f, b2Vec2(2.5f, -1.03f), -0.393f);
	body->CreateFixture(&s2, 0.0f);

	s2.SetAsBox(0.4f, 0.3f, b2Vec2(1.03f, -2.5f), 5.105f);
	body->CreateFixture(&s2, 0.0f);

	s2.SetAsBox(0.4f, 0.3f, b2Vec2(-1.03f, -2.5f), 4.32f);
	body->CreateFixture(&s2, 0.0f);

	body->SetUserData((void *)this);
}

void WaterWheel::SetWidthHeight()
{
	width = height = 600;
}

void WaterWheel::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;

	float angle = -1 * body->GetAngle();
	D3DXVECTOR3 coord = Game::GetPosOnScreen(this);
	coord.x -= (float)width / 2.0f;
	coord.y -= (float)height / 2.0f;
	D3DXVECTOR2 spriteCenter = D3DXVECTOR2((float)width / 2.0f, (float)height / 2.0f);
	D3DXVECTOR2 trans(coord.x, coord.y);
	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, &spriteCenter, angle, &trans);
	D3DXsprite->SetTransform(&mat);
	D3DXsprite->Draw(img, NULL, NULL, NULL, 0xFFFFFFFF);

	D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, NULL, 0.0f, NULL);
	D3DXsprite->SetTransform(&mat);
}