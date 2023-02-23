#ifdef _DEBUG
#pragma once

#include<StaticDecor.h>
#include<RoundList.h>


class AnimationTest : public StaticDecor
{
public:
	RoundList * sprites;
	Sprite * sprite;

	AnimationTest(LPDIRECT3DDEVICE9 device);
	void NextSprite();
	void Draw(LPD3DXSPRITE D3DXsprite);
};
#endif