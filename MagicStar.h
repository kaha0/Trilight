#pragma once

#include<RoundList.h>
#include<StaticDecor.h>
#include<TextureStorage.h>

class MagicStar : public StaticDecor
{
public:
	RoundList * imgs;
	Sprite * sprite;

	MagicStar(TextureStorage * ts, b2Vec2 pos = b2Vec2(0.0f, 0.0f));
	void GetTextures(TextureStorage * ts);
	void NextSprite();
	void Draw(LPD3DXSPRITE D3DXsprite);
	~MagicStar();
};