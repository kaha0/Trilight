#pragma once
#include<Pony.h>
#include<RoundList.h>
#include<TextureStorage.h>

class AJPony : public Pony
{
public:
	RoundList * RunL;
	RoundList * RunR;
	RoundList * BuckL;
	RoundList * BuckR;
	float runcost;
	float runspeed; // ?
	bool canbuck;

	AJPony(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
};