#pragma once

#include<Object.h>
#include<Movement.h>
#include<PlayerKA.h>
#include<RoundList.h>
#include<TextureStorage.h>

#include<AJPony.h>
#include<RDPony.h>
#include<TrixiePony.h>
#include<d3dx9.h>

class Player : public Object
{
public:
#ifdef _DEBUG
	float pBodyX;
	float pBodyY;
	float drawX;
	float drawY;
#endif

	AJPony * AJ;
	RDPony * RD;
	TrixiePony * Trixie;
	Pony * CurrentPony;

	PlayerKA<Player> * playerKA;
	Movement movement;
	Sprite * sprite;

	Sprite * dobuckL;
	Sprite * dobuckR;

	Player(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void SetState(int state);
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	bool ShouldIDraw();
	void Draw(LPD3DXSPRITE D3DXsprite);
	void NextSprite();
	void Fall(bool evenflying = false);
	void Land();
	void SwitchToAJ();
	void SwitchToRD();
	void SwitchToTrixie();
	void SetEnergyToMax();
	void KeyDown(WPARAM key);
	void KeyUp(WPARAM key);
	~Player();
};