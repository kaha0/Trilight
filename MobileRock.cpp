#include<Game.h>
#include<MobileRock.h>

MobileRock::MobileRock(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = true;
	SetWidthHeight();
}

void MobileRock::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::MobileRock);
}

void MobileRock::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[6];
	vertices[0].Set(-0.25f, 0.5f);
	vertices[1].Set(-0.5f, 0.0f);
	vertices[2].Set(-0.25f, -0.5f);
	vertices[3].Set(0.25f, -0.5f);
	vertices[4].Set(0.5f, 0.0f);
	vertices[5].Set(0.25f, 0.5f);
	shape.Set(vertices, 6);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 50.0f;
	fixtureDef.friction = 0.7f;
	body->CreateFixture(&fixtureDef);
	body->SetUserData((void *)this);
}

void MobileRock::SetWidthHeight()
{
	width = 128;
	height = 128;
}

void MobileRock::Draw(LPD3DXSPRITE D3DXsprite)
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