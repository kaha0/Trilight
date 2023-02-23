#pragma once

#include<ParallaxDecor.h>
#include<TextureStorage.h>

class Stars1 : public ParallaxDecor
{
public:
	LPDIRECT3DTEXTURE9 img;

	Stars1(TextureStorage * ts);
	Stars1(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};