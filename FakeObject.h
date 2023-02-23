#pragma once

#include<Box2D.h>
#include<Object.h>
#include<vector>

// class FakeObject inherits from Object, but is not an Actor
// useful for DestroyBodyTA
class FakeObject : public Object
{
public:
	enum FakeObjectType  // more types?
	{ FO_box, FO_polygon } type;
};

class FakeObjectBox : public FakeObject
{
public:
	b2Vec2 size;

	FakeObjectBox(b2Vec2 Size)
	{
		type = FakeObjectType::FO_box;
		reconstruct = true;
		size = Size;
	}

	void ConstructBody(b2World * w, b2Vec2 pos)
	{
		b2BodyDef def;
		b2PolygonShape shape;
		def.position = pos;
		body = w->CreateBody(&def);
		shape.SetAsBox(size.x, size.y);
		body->CreateFixture(&shape, 0.0f);
	}
};

class FakeObjectPolygon : public FakeObject
{
public:
	std::vector<b2Vec2> points;

	FakeObjectPolygon(b2Vec2 * Points, int count)
	{
		type = FakeObjectType::FO_polygon;
		reconstruct = true;
		for (int i = 0; i < count; ++i)
		{
			points.push_back(Points[i]);
		}
		
	}

	void ConstructBody(b2World * w, b2Vec2 pos)
	{
		b2BodyDef def;
		b2PolygonShape shape;
		def.position = pos;
		body = w->CreateBody(&def);
		b2Vec2 * pp = new b2Vec2[points.size()];
		int i = 0;
		for (std::vector<b2Vec2>::iterator it = points.begin(); it != points.end(); ++it)
		{
			pp[i] = (*it);
			++i;
		}
		shape.Set(pp, i);
		delete pp;
		body->CreateFixture(&shape, 0.0f);
	}
};