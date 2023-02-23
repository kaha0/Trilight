#include<RoundList.h>

Sprite::Sprite()
{
	next = NULL;
	prev = NULL;
	img = NULL;
}

Sprite::Sprite(LPDIRECT3DTEXTURE9 texture, bool term)
{
	next = NULL;
	prev = NULL;
	img = texture;
	terminal = term;
}

RoundList::RoundList()
{
	First = NULL;
	Last = NULL;
	count = 0;
}

void RoundList::Add(Sprite * sprite)
{
	if (count == 0)
	{
		First = sprite;
		Last = sprite;
		count = 1;
		sprite->next = sprite;
		sprite->prev = sprite;
	}
	else
	{
		Last->next = sprite;
		sprite->prev = Last;
		First->prev = sprite;
		sprite->next = First;
		Last = sprite;
		++count;
	}
}

void RoundList::Clear()
{
	if (count == 0)
	{
		First = NULL;
		Last = NULL;
		return;
	}
	if (count == 1)
	{
		delete First;
		First = NULL;
		Last = NULL;
		count = 0;
		return;
	}

	Sprite * t;
	Last->next = NULL;
	while (First)
	{
		t = First;
		First = First->next;
		t->next = NULL;
		t->prev = NULL;
		delete t;
	}
	First = Last = NULL;
	count = 0;
}

RoundList::~RoundList()
{
	Clear();
}