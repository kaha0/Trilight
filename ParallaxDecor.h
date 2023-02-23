#pragma once

#include<Actor.h>
#include<Box2D.h>

class ParallaxDecor : public Actor
{
public:
	b2Vec2 startpos;
	float coefX;
	float coefY;
};