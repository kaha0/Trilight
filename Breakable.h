#pragma once

#include<Object.h>
#include<RoundList.h>

class Breakable : public Object
{
public:
	Sprite * sprite;
	bool drawenabled;

	virtual void Bucked() {}
};