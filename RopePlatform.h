#pragma once

#include<Object.h>
#include<TextureStorage.h>

class RopePlatform : public Object
{
public:
	LPDIRECT3DTEXTURE9 img;

	RopePlatform(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void ConstructBody(b2World * w, b2Vec2 pos);
	void Draw(LPD3DXSPRITE D3DXsprite);
};