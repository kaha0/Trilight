#include<Game.h>
#include<RopeBridgeSegment.h>

RopeBridgeSegment::RopeBridgeSegment(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::RopeBridge_segment);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void RopeBridgeSegment::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[4];
	vertices[0].Set(-0.25f, 0.1f);
	vertices[1].Set(-0.3f, -0.1f);
	vertices[2].Set(0.3f, -0.1f);
	vertices[3].Set(0.25f, 0.1f);
	shape.Set(vertices, 4);
	body->CreateFixture(&shape, 0.0f);
	body->SetFixedRotation(false);
	body->SetUserData((void *)this);
}

void RopeBridgeSegment::SetWidthHeight()
{
	width = 50;
	height = 20;
}

void RopeBridgeSegment::Draw(LPD3DXSPRITE D3DXsprite)
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

void RopeBridgeSegment::Reset()
{
	if (body)
	{
		body->SetAngularVelocity(0.0f);
		body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
	}
}