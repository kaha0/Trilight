#pragma once

#include<RoundList.h>
#include<d3dx9.h>

class Pony
{
public:
	float Energy;
	float FillRate;
	float MaxEnergy;

	LPDIRECT3DTEXTURE9 HUDa;
	LPDIRECT3DTEXTURE9 HUDi;

	RoundList * IdleL;
	RoundList * IdleR;
	RoundList * WalkL;
	RoundList * WalkR;
	RoundList * JumpL;
	RoundList * JumpR;
	RoundList * FallL;
	RoundList * FallR;
};