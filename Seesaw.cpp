#include<Seesaw.h>
#include<Game.h>

Seesaw::Seesaw(TextureStorage * ts)
{
	fps = 0;
	framesdrawn = 0;
	reconstruct = false; // ?

	SetWidthHeight();
	GetTextures(ts);
}

void Seesaw::GetTextures(TextureStorage * ts)
{
	plank = ts->GetTexture(TextureStorage::TexName::Platform2);
	base = ts->GetTexture(TextureStorage::TexName::SeesawBase);
}

void Seesaw::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(1.5f, 0.1f);  // lichobìžník nepomáhá
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 10.0f;
	fixtureDef.friction = 1.0f;
	body->CreateFixture(&fixtureDef);
	body->SetFixedRotation(false);
	body->SetUserData((void *)this);

	def.type = b2_staticBody;
	def.position.y -= 0.2f;
	b2Body * stat = w->CreateBody(&def);
	shape.SetAsBox(0.1f, 0.1f);
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.0f;
	fixtureDef.isSensor = true;
	stat->CreateFixture(&fixtureDef);

	b2RevoluteJointDef rjd;
	rjd.bodyA = stat;
	rjd.bodyB = body;
	rjd.localAnchorA = b2Vec2(0.0f, 0.2f);
	rjd.localAnchorB = b2Vec2(0.0f, 0.0f);
	w->CreateJoint(&rjd);
}

void Seesaw::SetWidthHeight()
{
	width = 300;
	height = 20;
}

void Seesaw::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;

	float angle = -1 * body->GetAngle();
	D3DXVECTOR3 coord = Game::GetPosOnScreen(this);
	D3DXVECTOR3 coord_base = coord;
	coord.x -= (float)width / 2.0f;
	coord.y -= (float)height / 2.0f;
	D3DXVECTOR2 spriteCenter = D3DXVECTOR2((float)width / 2.0f, (float)height / 2.0f);
	D3DXVECTOR2 trans(coord.x, coord.y);
	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, &spriteCenter, angle, &trans);
	D3DXsprite->SetTransform(&mat);
	D3DXsprite->Draw(plank, NULL, NULL, NULL, 0xFFFFFFFF);

	D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, NULL, 0.0f, NULL);
	D3DXsprite->SetTransform(&mat);

	coord_base.x -= 64.0f;  // nastavit podle velikosti textury base
	coord_base.y -= 20.0f;
	D3DXsprite->Draw(base, NULL, NULL, &coord_base, 0xFFFFFFFF);
}