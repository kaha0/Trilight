#pragma once

#include<Box2D.h>

#include<Actor.h>
#include<JointDefWrapper.h>
#include<MagicBox.h>
#include<Object.h>
#include<Player.h>
#include<SaveState.h>
#include<TextureStorage.h>
#include<SoundStorage.h>
#include<TriggerArea.h>
#include<map>
#include<vector>

class Map
{
private:
	Map();
public:
	std::multimap<int, Actor*> Actors;
	int boxlayer;
	int mslayer;
	unsigned char level;
	std::vector<TriggerArea *> Triggers;

	Player * player;
	b2World * world;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;

	bool CanBeTrixie;
	bool CanBeRD;
	bool CanBeAJ;

	static Map * LoadMap(int level, TextureStorage * ts, SoundStorage * ss, SaveState * savestate, bool skillsloaded);

	void Step();
	void GetSaveState(SaveState * savestate);
	void ResetToSavestate(SaveState * savestate);
	void SkillsToState(SaveState * savestate);
	void SkillsFromState(SaveState * savestate);
	void DestroyAllBodies(bool all);
	void DestroyBody(Object * o);
	void DestroyBody(b2Body * b);
	void DeleteAllActors();
	void ResetTextures(TextureStorage * ts);

	// @deprecated - mazání Actorù je nežádoucí!
	// smažou se až pøi LevelExit, jinak se mažou jen bodies
	void DeleteActor(Actor * a);
	void DeleteActor(std::multimap<int, Actor*>::iterator it);

	// does NOT delete a!
	void RemovePtrFromActors(Actor * a);

	MagicBox * PutBox(TextureStorage * ts, b2Vec2 pos);

	// @deprecated
	//void DestroyBox(MagicBox * mb);
	int PutMagicStar(TextureStorage * ts, b2Vec2 pos);
	void PutZombie(TextureStorage * ts, b2Vec2 pos, float LeftBound, float RightBound, int l);

	~Map();
};