#pragma once

#include<StaticDecor.h>
#include<TextureStorage.h>

class SkillText : public StaticDecor
{
public:
	bool visited;

	SkillText();
	virtual void SetVisited(bool value);
};

class BuckText : public SkillText
{
public:
	LPDIRECT3DTEXTURE9 first;
	LPDIRECT3DTEXTURE9 second;
	D3DCOLOR fade;

	BuckText(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void SetVisited(bool value);
	void Draw(LPD3DXSPRITE D3DXsprite);
};

class FlyText : public SkillText
{
public:
	LPDIRECT3DTEXTURE9 img;
	D3DCOLOR fade;

	FlyText(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void SetVisited(bool value);
	void Draw(LPD3DXSPRITE D3DXsprite);
};

class IncBoxesText : public SkillText
{
public:
	LPDIRECT3DTEXTURE9 img;
	D3DCOLOR fade;

	IncBoxesText(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void SetVisited(bool value);
	void Draw(LPD3DXSPRITE D3DXsprite);
};

class LevitText : public SkillText
{
public:
	LPDIRECT3DTEXTURE9 first;
	LPDIRECT3DTEXTURE9 second;
	D3DCOLOR fade;

	LevitText(TextureStorage * ts, b2Vec2 pos);
	void GetTextures(TextureStorage * ts);
	void SetWidthHeight();
	void SetVisited(bool value);
	void Draw(LPD3DXSPRITE D3DXsprite);
};