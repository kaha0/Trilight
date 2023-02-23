#pragma once

#include<Actor.h>
#include<Box2D.h>

class Object : public Actor
{
public:
	b2Body * body;
	bool reconstruct;

	virtual void Land() {}
	virtual void ConstructBody(b2World * w, b2Vec2 pos) {}

	//@deprecated
	//virtual void Reset() {}
};