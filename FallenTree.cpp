#include<FallenTree.h>
#include<Game.h>

FallenTree::FallenTree(TextureStorage * ts)
{
	GetTextures(ts);
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	SetWidthHeight();
}

void FallenTree::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::FallenTree);
}

void FallenTree::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(3.7f, 0.17f);
	body->CreateFixture(&shape, 0.0f);
	body->SetUserData((void *)this);
}

void FallenTree::SetWidthHeight()
{
	width = 800;
	height = 115;
}

void FallenTree::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 400;
	vec.y -= 57.5f;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}

