#include<BigTree.h>
#include<Game.h>

BigTree::BigTree(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void BigTree::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::BigTree);
}

void BigTree::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(1.3f, 5.0f);
	body->CreateFixture(&shape, 0.0f);

	//b2Vec2 vertices[4];
	//vertices[0].Set(-1.0f, -3.5f);
	//vertices[1].Set(-1.5f, -5.0f);
	//vertices[2].Set(1.5f, -5.0f);
	//vertices[3].Set(1.0f, -3.5f);
	//shape.Set(vertices, 4);
	//body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void BigTree::SetWidthHeight()
{
	width = 300;
	height = 1000;
}

void BigTree::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 150;
	vec.y -= 500;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}