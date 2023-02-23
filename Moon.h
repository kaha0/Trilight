#pragma once

#include<ParallaxDecor.h>
#include<TextureStorage.h>

class Moon : public ParallaxDecor
{
public:
	LPDIRECT3DTEXTURE9 img;

	Moon(TextureStorage * ts);
	Moon(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};