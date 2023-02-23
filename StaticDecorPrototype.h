#pragma once

#include<StaticDecor.h>
#include<TextureStorage.h>
#include<d3dx9.h>

class StaticDecorPrototype : public StaticDecor
{
public:
	LPDIRECT3DTEXTURE9 img;
	TextureStorage::TexName tname;

	StaticDecorPrototype(TextureStorage * ts, TextureStorage::TexName texture);
	StaticDecorPrototype(TextureStorage * ts, TextureStorage::TexName texture, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};