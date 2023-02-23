#pragma once

#include<MagicBox.h>
#include<RoundList.h>

class BoxLevitateAura : public Actor
{
public:
	MagicBox * box;
	RoundList * imgs;
	Sprite * sprite;

	BoxLevitateAura(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void NextSprite();
	void Reset();
	bool ShouldIDraw();
	void Draw(LPD3DXSPRITE D3DXsprite);
	~BoxLevitateAura();
};