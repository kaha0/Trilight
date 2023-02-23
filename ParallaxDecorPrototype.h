#pragma once

#include<ParallaxDecor.h>
#include<TextureStorage.h>

class ParallaxDecorPrototype : public ParallaxDecor
{
public:
	LPDIRECT3DTEXTURE9 img;
	TextureStorage::TexName tname;

	ParallaxDecorPrototype(TextureStorage * ts, TextureStorage::TexName texture);
	ParallaxDecorPrototype(TextureStorage * ts, TextureStorage::TexName texture, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};