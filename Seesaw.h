#pragma once

#include<Object.h>
#include<TextureStorage.h>

class Seesaw : public Object
{
public:
	LPDIRECT3DTEXTURE9 plank;
	LPDIRECT3DTEXTURE9 base;

	Seesaw(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};