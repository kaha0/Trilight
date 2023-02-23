#pragma once

#include<Object.h>
#include<TextureStorage.h>

class GroundBox3 : public Object
{
public:
	LPDIRECT3DTEXTURE9 img;

	GroundBox3(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
};