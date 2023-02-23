#include<Game.h>
#include<Lantern1.h>

Lantern1::Lantern1(TextureStorage * ts)
{
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
	GetTextures(ts);
}

void Lantern1::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Lantern1);
}

void Lantern1::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(0.05f, 0.1f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 10.0f;
	//fixtureDef.friction = 1.0f;
	//fixtureDef.filter.categoryBits = 0x0001;
	//fixtureDef.filter.maskBits = 0xFFFD;
	fixtureDef.isSensor = true;
	body->CreateFixture(&fixtureDef);
	
	body->SetFixedRotation(false);
	body->SetUserData((void *)this);
}

void Lantern1::SetWidthHeight()
{
	width = 330;
	height = 330;
}

void Lantern1::Draw(LPD3DXSPRITE D3DXsprite)
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