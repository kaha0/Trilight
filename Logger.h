#pragma once

#include<d3dx9.h>
#include<queue>

template<class T>
class Logger
{
public:
	T * owner;
	bool log;
	DWORD lasttime;
	int framesdrawn;
	int lastfps;
	LPD3DXFONT fontSmall;
	LPD3DXFONT fontBig;
	std::queue<std::string> * msgs;
	Logger(T * t, LPDIRECT3DDEVICE9 device);
	void Draw(LPDIRECT3DDEVICE9 device);
	void LogMsg(const char * s, WPARAM k);
	~Logger();
};