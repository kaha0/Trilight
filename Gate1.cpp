#include<Game.h>
#include<Gate1.h>

Gate1::Gate1(TextureStorage * ts)
{
	fps = 0;
	framesdrawn = 0;
	reconstruct = true;
	GetTextures(ts);
	SetWidthHeight();
}

void Gate1::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::VertPlank);  // zatim
}

void Gate1::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(0.25f, 2.5f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.5f;
	fixtureDef.friction = 0.7f;
	body->CreateFixture(&fixtureDef);
	body->SetFixedRotation(true);
	body->SetUserData((void *)this);
}

void Gate1::SetWidthHeight()
{
	width = 50;
	height = 500;
}

void Gate1::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 25;
	vec.y -= 250;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}