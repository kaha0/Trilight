#pragma once

#include<Object.h>
#include<TextureStorage.h>

class RopeBridgeSegment : public Object
{
public:
	LPDIRECT3DTEXTURE9 img;

	RopeBridgeSegment(TextureStorage * ts);
	void ConstructBody(b2World * w, b2Vec2 pos);
	void SetWidthHeight();
	void Draw(LPD3DXSPRITE D3DXsprite);
	void Reset();
};