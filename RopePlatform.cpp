#include<Game.h>
#include<RopePlatform.h>

RopePlatform::RopePlatform(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	width = 250;
	height = 230;
	reconstruct = true;
}

void RopePlatform::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::Rope_platform);
}

void RopePlatform::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[4];
	//vertices[0].Set(-1.2f, -2.4f);  rope_platform_SOLID
	//vertices[1].Set(-1.2f, -2.6f);
	//vertices[2].Set(1.2f, -2.6f);
	//vertices[3].Set(1.2f, -2.4f);
	vertices[0].Set(-1.2f, -0.9f);
	vertices[1].Set(-1.2f, -1.1f);
	vertices[2].Set(1.2f, -1.1f);
	vertices[3].Set(1.2f, -0.9f);
	shape.Set(vertices, 4);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &shape;
	boxFixtureDef.density = 10.0f;
	boxFixtureDef.friction = 1.0f;
	body->CreateFixture(&boxFixtureDef);
	body->SetFixedRotation(false);
	body->SetUserData((void *)this);
}

void RopePlatform::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;

	float angle = -1 * body->GetAngle();
	D3DXVECTOR3 coord = Game::GetPosOnScreen(this);
	coord.x -= (float)width / 2.0f;
	coord.y -= (float)height / 2.0f;
	D3DXVECTOR2 spriteCenter = D3DXVECTOR2((float)width / 2.0f, (float)height / 2.0f);
	//D3DXVECTOR2 spriteCenter = D3DXVECTOR2(125.0f, 5.0f);
	D3DXVECTOR2 trans(coord.x, coord.y);
	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, &spriteCenter, angle, &trans);
	D3DXsprite->SetTransform(&mat);
	D3DXsprite->Draw(img, NULL, NULL, NULL, 0xFFFFFFFF);

	D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, NULL, 0.0f, NULL);
	D3DXsprite->SetTransform(&mat);
}