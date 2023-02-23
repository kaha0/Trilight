#pragma once

#include<Object.h>

class NPC : public Object
{
public:
	virtual void Step() {}  // tady se bude simulovat pohyb
};

// víc tøíd? NPCactor, NPCobject...