#pragma once

#include<Breakable.h>
#include<RoundList.h>
#include<TextureStorage.h>

class BigRock : public Breakable
{
public:
	RoundList * whole;
	RoundList * cracked;
	RoundList * breaking;

	BigRock(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	void NextSprite();
	void Bucked();
	void Draw(LPD3DXSPRITE D3DXsprite);
};