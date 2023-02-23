#pragma once

#include<Object.h>
#include<SkillsText.h>
#include<SoundStorage.h>
#include<TextureStorage.h>
#include<Box2D.h>

enum TriggerType
{
	Death, SavePoint, LevelExit, PlaySoundTrig, PutZombie, DeleteBody,
	EnableBuck, DecFlyCost, IncMaxBoxes, EnableLevit
};

class TriggerArea : public Object
{
public:
	TriggerType type;
	bool enabled;
	bool resetme;  // neni resetme zbyteèný? když nechceme TA resetovat tak ho mùžeme rovnou deleteovat
	bool deleteme;
	bool isinactors;  // pomocná promìnná, udává jestli je TriggerArea zároveò v map::Actors
	LPDIRECT3DTEXTURE9 img;

	void GetTextures(TextureStorage * ts);
	void Draw(LPD3DXSPRITE D3DXsprite);

	TriggerArea(TriggerType tt);
	TriggerArea(TextureStorage * ts, TriggerType tt);  // DEBUG?
	void ConstructBody(b2World * w, b2Vec2 pos);
	void ConstructBody(b2World * w, b2Vec2 pos, b2Vec2 size);
};

class DeleteBodyTA : public TriggerArea
{
public:
	Object * todelete;

	DeleteBodyTA();
	DeleteBodyTA(TextureStorage * ts);
};

class ActorTA : public TriggerArea  // abstraktní tøída
{
public:
	b2Vec2 actorpos;  // je vùbec actorpos dobrej nápad? dìlá to dost nepoøádek...

	ActorTA(TriggerType tt);
};

class SavePointTA : public  ActorTA
{
public:
	SavePointTA(TextureStorage * ts);
	void SetWidthHeight();
	void GetTextures(TextureStorage * ts);
	void Draw(LPD3DXSPRITE D3DXsprite);
};

class LevelExitTA : public  ActorTA
{
public:
	LevelExitTA(TextureStorage * ts);
	void SetWidthHeight();
	void GetTextures(TextureStorage * ts);
	void Draw(LPD3DXSPRITE D3DXsprite);
};

class PlaySoundTA : public TriggerArea
{
public:
	LPDIRECTSOUNDBUFFER sound;

	PlaySoundTA(SoundStorage * ss, SoundStorage::SoundName sn);
	PlaySoundTA(TextureStorage * ts, SoundStorage * ss, SoundStorage::SoundName sn);
};

class PutZombieTA : public TriggerArea
{
public:
	b2Vec2 pos;
	b2Vec2 bounds;
	int layer;

	PutZombieTA(TextureStorage * ts);
	PutZombieTA(TextureStorage * ts, b2Vec2 position, float Lbound, float Rbound, int Layer);
};

class PowerUpTA : public ActorTA
{
public:
	int state;
	SkillText * text;  // necháme to i do release verze nebo jen pro demo?

	PowerUpTA(TriggerType tt);
	void SetWidthHeight();
	void ConstructBody(b2World * w, b2Vec2 pos);
	void NextSprite();
	void Draw(LPD3DXSPRITE D3DXsprite);
};

class EnableBuckTA : public PowerUpTA
{
public:
	EnableBuckTA(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
};

class DecFlyCostTA : public PowerUpTA
{
public:
	DecFlyCostTA(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
};

class IncMaxBoxesTA : public PowerUpTA
{
public:
	IncMaxBoxesTA(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
};

class EnableLevitTA : public PowerUpTA
{
public:
	EnableLevitTA(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
};