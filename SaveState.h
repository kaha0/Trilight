#pragma once

#include<Object.h>
#include<JointDefWrapper.h>
#include<vector>

struct ObjectAndDef
{
	Object * object;
	b2Vec2 pos;
	b2Vec2 vel;

	// a co když v prùbìhu hry pøibude staticdecor nebo parallaxdecor? takhle by tam zustal
	// nebo když nìjakej decor odstraníme
};

class SaveState
{
public:
	unsigned char level;
	unsigned char characters;
	unsigned char playerchar;
	unsigned char playerstate;
	b2Vec2 screenpos;
	b2Vec2 playerpos; // player neni mezi objects, pointer má map, tady staèí playerpos

	//SKILLS
	float runcost;
	float runspeed;
	bool canbuck;

	float flycost;
	float flyspeed;
	bool candash;

	float boxcost;
	int maxboxes;
	float levitcost;
	bool canlevitate;
	
	// seznam objektù s pozicema
	std::vector<ObjectAndDef> * objects;

	// seznam joints
	// joint ukládat, pouze pokud alespoò jedno z tìles bude rekonstruováno
	std::vector<JointDefWrapper *> * joints;

	//staticdecor, parallaxdecor ??

	SaveState()
	{
		screenpos = b2Vec2(0.0f, 0.0f);
		objects = new std::vector<ObjectAndDef>();
		joints = new std::vector<JointDefWrapper *>();
	}

	void Reset(bool resetskills = false)
	{
		characters = 0;
		level = 0;
		if (objects) objects->clear();
		else objects = new std::vector<ObjectAndDef>();
		if (joints)
		{
			for (std::vector<JointDefWrapper *>::iterator it = joints->begin(); it != joints->end(); it++)
				delete (*it);
			joints->clear();
		}
		else joints = new std::vector<JointDefWrapper *>();
		playerchar = 0;
		playerpos = b2Vec2(0.0f, 0.0f);
		playerstate = 0;
		screenpos = b2Vec2(0.0f, 0.0f);

		if (resetskills)
		{
			runcost = runspeed = 0.0f;
			canbuck = false;
			flycost = flyspeed = 0.0f;
			candash = false;
			boxcost = levitcost = 0.0f;
			canlevitate = false;
			maxboxes = 0;
		}
	}
	//bool SaveToFile(const char * path);  // TODO
	//static SaveState * LoadFromFile(const char * path);  // TODO

	~SaveState()
	{
		delete objects;
		for (std::vector<JointDefWrapper *>::iterator it = joints->begin(); it != joints->end(); it++)
			delete (*it);
		delete joints;
	}
};