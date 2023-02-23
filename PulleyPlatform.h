#pragma once

#include<Object.h>
#include<TextureStorage.h>

class PulleyPlatform : public Object
{
public:
	LPDIRECT3DTEXTURE9 img;
	LPDIRECT3DTEXTURE9 rope;
	bool userope;
	float ropeheight;

	PulleyPlatform(TextureStorage * ts);
	PulleyPlatform(TextureStorage * ts, float anchor);
	void GetTextures(TextureStorage * ts);
	void ConstructBody(b2World * w, b2Vec2 pos);
	bool ShouldIDraw();
	void Draw(LPD3DXSPRITE D3DXsprite);
};