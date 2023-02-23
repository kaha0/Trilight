#pragma once

#include<StaticDecor.h>
#include<RoundList.h>
#include<TextureStorage.h>

class Grass2 : public StaticDecor
{
public:
	RoundList * imgs;
	Sprite * sprite;

	Grass2(TextureStorage * ts);
	Grass2(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void NextSprite();
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};