#pragma once

#include<d3d9.h>

class Sprite
{
public:
	Sprite * next;
	Sprite * prev;
	LPDIRECT3DTEXTURE9 img;
	bool terminal;
	Sprite();
	Sprite(LPDIRECT3DTEXTURE9 texture, bool term);
};

class RoundList
{
	public:
	Sprite * First;
	Sprite * Last;
	int count;
	RoundList();
	void Add(Sprite * sprite);
	void Clear();
	~RoundList();
};