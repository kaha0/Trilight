#pragma once

#include<d3d9.h>
#include<Movement.h>
#include<VertexEdge.h>

#ifndef WPARAM
typedef unsigned int WPARAM;
#endif

template<class T>
class PlayerKA
{
public:
	T * owner;
	Vertex * EntryPoint;
	Vertex * Actual;
	bool hasOTM;
	Movement onetimemv;

	const float jumpforce;		// = 62.5f;  // 50 pro 16
	const float flyforcestrong; // = 3.75f;  // 3.0
	const float flyforce;		// = 1.9f;   // 1.52
	const float dashforce;

	Vertex * IL;
	Vertex * IR;
	Vertex * FL;
	Vertex * FR;
	Vertex * JL;
	Vertex * JR;
	Vertex * FlyL;
	Vertex * FlyR;
	Vertex * DashL;
	Vertex * DashR;
	Vertex * WL;
	Vertex * WR;
	Vertex * DL;
	Vertex * DR;
	Vertex * BL;
	Vertex * BR;

	// pomocný vrcholy - jsou vùbec potøeba? FlyX nepotøebuje Fly2X...
	Vertex *IL2;
	Vertex *IR2;
	Vertex *WL2;
	Vertex *WR2;
	Vertex *RL;
	Vertex *RR;
	Vertex *RL2;
	Vertex *RR2;

	PlayerKA(T * t);
	void KeyDown(WPARAM key);
	void KeyUp(WPARAM key);
	void Fall(bool evenflying);
	Movement GetMovement();
	~PlayerKA();
};