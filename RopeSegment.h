#pragma once

#include<Object.h>
#include<TextureStorage.h>

class RopeSegment : public Object
{
public:
	LPDIRECT3DTEXTURE9 img;

	RopeSegment(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void ConstructBody(b2World * w, b2Vec2 pos);
	void Draw(LPD3DXSPRITE D3DXsprite);
	void Reset();
};