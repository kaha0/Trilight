#pragma warning( disable : 4482 )

#include<Game.h>
#include<MagicBox.h>

MagicBox::MagicBox(TextureStorage * ts)
{
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	GetTextures(ts);
	SetWidthHeight();
}

void MagicBox::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Box01);
}

void MagicBox::SetWidthHeight()
{
	// load dynamically ?
	width = 105;
	height = 105;
}

void MagicBox::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(0.5f, 0.5f);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &shape;
	boxFixtureDef.density = 25.0f;
	boxFixtureDef.friction = 1.0f;
	boxFixtureDef.filter.categoryBits = 0x0001;
	boxFixtureDef.filter.maskBits = 0xFFFD;
	body->CreateFixture(&boxFixtureDef);
	body->SetFixedRotation(false);
	body->SetUserData((void *)this);
}

void MagicBox::Draw(LPD3DXSPRITE D3DXsprite)
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

	D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, NULL, 0.0f, NULL);  // nastavit matici transformace zpátky
	D3DXsprite->SetTransform(&mat);
}