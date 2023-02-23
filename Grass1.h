#pragma once

#include<StaticDecor.h>
#include<TextureStorage.h>

class Grass1 : public StaticDecor
{
public:
	LPDIRECT3DTEXTURE9 img;

	Grass1(TextureStorage * ts);
	Grass1(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};