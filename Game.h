#pragma once

#include<Box2D.h>
#include<BoxLevitateAura.h>
#include<Breakable.h>
#include<DeathBox.h>
#include<GameVFX.h>
#include<Levitable.h>
#include<Map.h>
#include<Mob.h>
#include<Player.h>
#include<ParallaxDecor.h>
#include<StaticDecor.h>
#include<SaveState.h>
#include<SoundStorage.h>
#include<TextureStorage.h>
#include<TriggerArea.h>
#include<d3dx9.h>
#include<dsound.h>
#include<WinDef.h>
#include<vector>
#include<fstream>
#include<stdexcept>

#ifdef _DEBUG
#include<Logger.h>
#endif

struct PointMagicStar
{
	int x, y, ActorKey;
};

class Game
{
private:
	LPDIRECT3DDEVICE9 Device;
	LPDIRECTSOUND8 Dsound;    // this pointer is pretty much useless since SoundStorage holds another pointer to Dsound but whatever
	Game() {}

public:
	enum GameState
	{
		MainMenu_newgame, MainMenu_load, MainMenu_quit,
		LoadMenu_none, LoadMenu_1_1, LoadMenu_2_1, LoadMenu_2_2, LoadMenu_3_1, LoadMenu_3_2, LoadMenu_3_3,  // LoadMenu_HIGHEST_ACTIVE
		GameMenu_resume, GameMenu_quit,
		Cutscene, Paused, Running, DeathReset, NextLevel, Quit
	} State;
	static int ScreenWidth;
	static int ScreenHeight;
	static float PositionX;  // position of the screen within game-world, point of reference is upper left corner
	static float PositionY;
	bool devicelost;
	SaveState * Savestate;

	unsigned long stateaux_ul;
	long stateaux_l;
	//D3DCOLOR FadeOut;
	//unsigned char AuxCounter;

	LPDIRECT3DTEXTURE9 MainMenu_ng;
	LPDIRECT3DTEXTURE9 MainMenu_l;
	LPDIRECT3DTEXTURE9 MainMenu_q;
	LPDIRECT3DTEXTURE9 LoadMenu_n;
	LPDIRECT3DTEXTURE9 LoadMenu_11;
	LPDIRECT3DTEXTURE9 LoadMenu_21;
	LPDIRECT3DTEXTURE9 LoadMenu_22;
	LPDIRECT3DTEXTURE9 LoadMenu_31;
	LPDIRECT3DTEXTURE9 LoadMenu_32;
	LPDIRECT3DTEXTURE9 LoadMenu_33;
	LPDIRECT3DTEXTURE9 GameMenu_r;
	LPDIRECT3DTEXTURE9 GameMenu_q;
	LPDIRECT3DTEXTURE9 Black;
	LPDIRECT3DTEXTURE9 White;
	GameVFX * vfx;
	BoxLevitateAura * LevitAura;

	LPDIRECT3DTEXTURE9 EBAL;
	LPDIRECT3DTEXTURE9 EBAM;
	LPDIRECT3DTEXTURE9 EBAR;
	LPDIRECT3DTEXTURE9 EBIL;
	LPDIRECT3DTEXTURE9 EBIM;
	LPDIRECT3DTEXTURE9 EBIR;

#ifdef _DEBUG
	Logger<Game> * logger;
#endif

	bool drawing; // necháme to takhle
	std::vector<PointMagicStar> * points; // nebo nìjak líp?

	bool levitating;
	b2Vec2 levitTargetPoint;
	unsigned char levitStarCounter;
	Levitable * levitBody;

	TextureStorage * Textures;
	SoundStorage * Sounds;
	static Player * player;
	Map * map;

	Game(int W, int H);
	void InitGame(LPDIRECT3DDEVICE9 device, LPDIRECTSOUND8 dsound);
	void Render(LPDIRECT3DDEVICE9 device);
	void DoCutscene(LPD3DXSPRITE sprite);
	void DrawActors(LPD3DXSPRITE sprite);
	void DrawTriggers(LPD3DXSPRITE sprite);  // ONLY FOR DEBUGGING
	void DrawVFX(LPD3DXSPRITE sprite);
	void MoveScreen();
	void KeyDown(WPARAM key);
	void KeyUp(WPARAM key);
	void LMBdown(int x, int y);
	void MouseMove(int x, int y);
	void LMBup(int x, int y);
	void RMBdown(int x, int y);
	void RMBup(int x, int y);
	void AnalyzePoints();
	void DeletePoints();
	void DoPhysics();
	void SubtractEnergy();
	void FillEnergy();
	void CheckTriggers();
	void Pause();
	void DrawHUD(LPD3DXSPRITE D3DXsprite);
	bool LoadSavedSkills(SaveState * savestate, int level);
	bool SaveSkills(SaveState * savestate, int level);
	void WriteSkills(std::ofstream * w, SaveState * savestate);
	void TruncSaveFile();

	void ReleaseTextures();
	void ReloadTextures();

	// statické metody
	static D3DXVECTOR3 GetPosOnScreen(b2Vec2 v);
	static D3DXVECTOR3 GetPosOnScreen(Object * o);  // <- volající Object si sám odeète offset textury
	static D3DXVECTOR3 GetPosOnScreen(StaticDecor * sd);
	static D3DXVECTOR3 GetPosOnScreen(ParallaxDecor * pd);
	static b2Vec2 GetPosInWorld(int x, int y);
	static bool ShouldIDraw(Object * o);
	static bool ShouldIDraw(StaticDecor * sd);
	static bool ShouldIDraw(ParallaxDecor * pd);
	static bool ShouldIDraw(ActorTA * ata);
	~Game();
};

class BuckRayCastCallback : public b2RayCastCallback
{
public:
	Player * player;

	BuckRayCastCallback(Player * p)
	{
		player = p;
	}

	float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction)
	{
		Object * o = (Object *)fixture->GetBody()->GetUserData();
		if (o == player) return -1.0f;  // zbyteèný
		// b2Vec2 p = player->body->GetLocalPoint(point); neni potøeba
		Breakable * b = dynamic_cast<Breakable *>(o);
		if (b) b->Bucked();
		return 0.0f;
	}
};

class IsBodyRayCastCallback : public b2RayCastCallback
{
public:
	b2Body * body;

	IsBodyRayCastCallback()
	{
		body = NULL;
	}

	float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction)
	{
		body = fixture->GetBody();
		//return 0.0f;
		return fraction;
	}
};

class IsBodyQueryCallback : public b2QueryCallback
{
public:
	b2Body * body;  // nestaèil by bool? staèil...

	IsBodyQueryCallback()
	{
		body = NULL;
	}

	bool ReportFixture(b2Fixture* fixture)
	{
		body = fixture->GetBody();
		return false;
	}
};

class IsMagicboxQueryCallback : public b2QueryCallback
{
public:
	MagicBox * box;

	IsMagicboxQueryCallback()
	{
		box = NULL;
	}

	bool ReportFixture(b2Fixture* fixture)
	{
		Object * o = (Object *)fixture->GetBody()->GetUserData();
		MagicBox * mb = dynamic_cast<MagicBox *>(o);
		if (mb)
		{
			box = mb;
			return false;
		}
		return true;
	}
};

class IsLevitableQueryCallback : public b2QueryCallback
{
public:
	Levitable * body;

	IsLevitableQueryCallback()
	{
		body = NULL;
	}

	bool ReportFixture(b2Fixture* fixture)
	{
		Object * o = (Object *)fixture->GetBody()->GetUserData();
		Levitable * l = dynamic_cast<Levitable *>(o);
		if (l)
		{
			body = l;
			return false;
		}
		return true;
	}
};