#pragma once

#include<Object.h>

class NPC : public Object
{
public:
	virtual void Step() {}  // tady se bude simulovat pohyb
};

// v�c t��d? NPCactor, NPCobject...