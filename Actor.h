#pragma once

#include<d3dx9.h>
#include<TextureStorage.h>

class Actor
{
public:
	int height;
	int width;
	int fps;  // constant (fps == 0 means that sprite does not change)
	int framesdrawn;  // used to count how many times we've drawn the current sprite

	Actor()
	{
		fps = 0;
		framesdrawn = 0;
	}
	virtual void GetTextures(TextureStorage * ts) {}
	virtual void Draw(LPD3DXSPRITE D3DXsprite) {}
	virtual void NextSprite() {}
	virtual void SetWidthHeight()
	{
		height = 0;
		width = 0;
	}
};