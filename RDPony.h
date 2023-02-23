#pragma once
#include<Pony.h>
#include<RoundList.h>
#include<TextureStorage.h>

class RDPony : public Pony
{
public:
	RoundList * FlyL;
	RoundList * FlyR;
	RoundList * DashL;
	RoundList * DashR;
	float flycost;
	float flyspeed; // ?
	bool candash;

	RDPony(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
};