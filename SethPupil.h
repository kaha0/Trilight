#pragma once

#include<ParallaxDecor.h>
#include<RoundList.h>
#include<TextureStorage.h>

class SethPupil : public ParallaxDecor
{
public:
	Sprite * sprite;
	RoundList * imgs;

	SethPupil(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void NextSprite();
	void Draw(LPD3DXSPRITE D3DXsprite);
};