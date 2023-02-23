#pragma once

#include<Box2D.h>
#include<NPC.h>
#include<RoundList.h>
#include<TextureStorage.h>

class Parasprite : public NPC
{
public:
	RoundList * imgs;
	Sprite * sprite;
	b2Vec2 position;
	b2Vec2 anchor;
	b2Vec2 awayanchor;
	b2Vec2 direction;
	bool flyaway;
	float Xbound;
	float Ybound;

	Parasprite(TextureStorage * ts, b2Vec2 pos, float xbound, float ybound, b2Vec2 awaypos);
	void GetTextures(TextureStorage * ts);
	void NextSprite();
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
	void Step();
};