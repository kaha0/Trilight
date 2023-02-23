#pragma once

#include<DeathBox.h>
#include<RoundList.h>
#include<TextureStorage.h>

class Water1 : public DeathBox
{
public:
	RoundList * imgs;
	Sprite * sprite;

	Water1(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void NextSprite();
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};