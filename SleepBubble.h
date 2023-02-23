#pragma once

#include<StaticDecor.h>
#include<RoundList.h>
#include<TextureStorage.h>

class SleepBubble : public StaticDecor
{
public:
	Sprite * sprite;
	RoundList * imgs;

	SleepBubble(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void NextSprite();
	void Draw(LPD3DXSPRITE D3DXsprite);
};