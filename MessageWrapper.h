#pragma once

#include<Game.h>
#include<set>

#ifndef WPARAM
typedef unsigned int WPARAM;
#endif

class MessageWrapper
{
	std::set<WPARAM> keys;
	std::set<WPARAM> filter;
	Game * game;
public:
	MessageWrapper(Game * g);
	void AddMessage(WPARAM key);
	void RemoveMessage(WPARAM key);
	void Step();
};