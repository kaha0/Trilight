#pragma once

#include<Levitable.h>
#include<TextureStorage.h>

class MagicBox : public Levitable
{
public:
	LPDIRECT3DTEXTURE9 img;

	MagicBox(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void ConstructBody(b2World * w, b2Vec2 pos);
	void Draw(LPD3DXSPRITE D3DXsprite);
};