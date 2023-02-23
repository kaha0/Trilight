#pragma once

#include<Actor.h>
#include<RoundList.h>

class GameVFX : public Actor
{
public:
	RoundList * imgs;
	Sprite * current;
	D3DXVECTOR3 offset;

	GameVFX(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void Draw(LPD3DXSPRITE D3DXsprite);
	void NextSprite();
	~GameVFX();
};