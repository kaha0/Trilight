#pragma once

#include<ParallaxDecor.h>
#include<TextureStorage.h>

class Mountains : public ParallaxDecor
{
public:
	LPDIRECT3DTEXTURE9 img;

	Mountains(TextureStorage * ts);
	Mountains(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};