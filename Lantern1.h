#pragma once

#include<Object.h>

// class Lantern1 : public Switchable ?
class Lantern1 : public Object
{
public:
	LPDIRECT3DTEXTURE9 img;

	Lantern1(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};