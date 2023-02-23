#pragma once

#include<Movement.h>
#include<map>
#include<d3d9.h>

enum EdgeType { SetVelocity, ApplyImpulse };

template<class T>
class Edge
{
public:
	T * target;
	EdgeType type;
	float amount;

	Edge();
	Edge(T * t);
};

class Vertex
{
public:
	Movement mv;
	std::map<WPARAM, Edge<Vertex>> * keydowntr;  // mam si držet pøímo ten objekt
	std::map<WPARAM, Edge<Vertex>> * keyuptr;    // nebo jenom pointer?
	std::string name;

	Vertex(Movement movement);
	Vertex(Movement movement, std::string n);
	~Vertex();
};