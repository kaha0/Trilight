#pragma once

#include<Mob.h>
#include<RoundList.h>
#include<TextureStorage.h>

class Zombie : public Mob
{
public:
	RoundList * Wleft;
	RoundList * Wright;
	Sprite * sprite;
	bool left;
	float Lbound;
	float Rbound;

	Zombie(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void NextSprite();
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
	void Step();
};