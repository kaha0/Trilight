#pragma once

#include<d3dx9.h>
#include<map>
#include<vector>

class TextureStorage
{
private:
	LPDIRECT3DDEVICE9 Device;
	TextureStorage() {}
public:
	enum TexName  // do vlastního hlavièkovýho souboru?
	{ Black, White, MainMenu_newgame, MainMenu_load, MainMenu_quit,
	LoadMenu_none, LoadMenu_1_1, LoadMenu_2_1, LoadMenu_2_2, LoadMenu_3_1, LoadMenu_3_2, LoadMenu_3_3,  // zatim, pozdìji pøidat další
	GameMenu_resume, GameMenu_quit,
	VFX1, VFX2, VFX3,
	EnergyBar_Active_L, EnergyBar_Active_M, EnergyBar_Active_R, EnergyBar_Inactive_L, EnergyBar_Inactive_M, EnergyBar_Inactive_R,
	PU_Horseshoe, PU_Wings, PU_Wand, PU_Levit,  // power-ups
	Stars1, Moon, GroundBox1, GroundBox2, GroundBox3, Grass1, Grass2, Grass3, Grass4, Grass5, Grass6, Grass7, Grass8, SmallRock, BigTree, BigTree2, Box01,
	MagicStar1, MagicStar2, MagicStar3, MagicStar4, MagicStar5, MagicStar6, MagicStar7, MagicStar8, MagicStar9,
	BoxLevitate_01, BoxLevitate_02, BoxLevitate_03, BoxLevitate_04, BoxLevitate_05, BoxLevitate_06, BoxLevitate_07, BoxLevitate_08, BoxLevitate_09, BoxLevitate_10, BoxLevitate_11,
	DeathBox1, TriggerBox,
	Cloud1, Cloud2, Cloud3, Cloud4,
	SleepBubble_01, SleepBubble_02, SleepBubble_03, SleepBubble_04, SleepBubble_05, SleepBubble_06, SleepBubble_07, SleepBubble_08, SleepBubble_09, SleepBubble_10, SleepBubble_11, SleepBubble_12, SleepBubble_13, SleepBubble_14, SleepBubble_15, SleepBubble_16,
	AppleTree_01, AppleTree_02, AppleTree_03, AppleTree_04, AppleTree_05, AppleTree_06, AppleTree_07, AppleTree_08, AppleTree_09, AppleTree_10,
	DeadTree01, DeadTree02, DeadTree03, DeadTree04, DeadTree05, DeadTree06, DeadTree07, DeadTree08, DeadTree09, DeadTree10, Stump, FallenTree, Lamppost1, Lantern1,
	Building01, Building02, Building03, Building04, Building05,
	Town_Hall, Farmhouse, ChickenCoop, Fence1, Fence2, Fence3, HayBale1, HayBale2, Shed,
	BigRock_whole, BigRock_cracked, BigRock_break01, BigRock_break02, BigRock_break03, BigRock_break04, BigRock_break05, BigRock_break06, BigRock_break07, BigRock_break08, BigRock_break09, BigRock_break10, BigRock_break11, BigRock_break12, BigRock_break13, BigRock_break14, BigRock_break15, BigRock_break16, BigRock_break17, BigRock_break18, BigRock_break19, BigRock_break20,
	Scaffolding01, Scaffolding02, Rope_segment, Pulley_Rope, Rope_platform, RopeBridge_segment, Water01, Water02, Water03, MobileRock,
	Platform1, Platform2, Platform3, SeesawBase, BrokenPlatform1, BrokenPlatform2, CrossSupports, VertPlank, Ramp_left, Ramp_right, Palisade, GatePassage, WaterWheel, Mill,
	StarPillar, BallPillar, Mountains,
	Seth1, Seth2, Seth3_1, Seth3_2, Seth3_3, Gray,

	// texty
	Text_Change, Text_Jump, Text_Draw, Text_Swim, Text_Savepoint, Text_Shift, Text_End1, Text_End2, Text_End3, Text_End4,
	Text_Buck1, Text_Buck2, Text_Fly, Text_IncBoxes, Text_Levit1, Text_Levit2,

	Zombie_left_01, Zombie_left_02, Zombie_left_03, Zombie_left_04, Zombie_left_05, Zombie_left_06, Zombie_left_07, Zombie_left_08, Zombie_left_09, Zombie_left_10, Zombie_left_11, Zombie_left_12, Zombie_left_13, Zombie_left_14, Zombie_left_15, Zombie_left_16,
	Zombie_right_01, Zombie_right_02, Zombie_right_03, Zombie_right_04, Zombie_right_05, Zombie_right_06, Zombie_right_07, Zombie_right_08, Zombie_right_09, Zombie_right_10, Zombie_right_11, Zombie_right_12, Zombie_right_13, Zombie_right_14, Zombie_right_15, Zombie_right_16,

	Parasprite1, Parasprite2, Parasprite3,

	Trixie,  // naète všechny textury pro Trixie
	Trixie_HUD_active, Trixie_HUD_inactive, Trixie_idle_left, Trixie_idle_right,  // pozdìji mùžeme animovat i idle
	Trixie_walk_left_01, Trixie_walk_left_02, Trixie_walk_left_03, Trixie_walk_left_04, Trixie_walk_left_05, Trixie_walk_left_06, Trixie_walk_left_07, Trixie_walk_left_08, Trixie_walk_left_09, Trixie_walk_left_10, Trixie_walk_left_11, Trixie_walk_left_12, Trixie_walk_left_13, Trixie_walk_left_14, Trixie_walk_left_15, Trixie_walk_left_16,
	Trixie_walk_right_01, Trixie_walk_right_02, Trixie_walk_right_03, Trixie_walk_right_04, Trixie_walk_right_05, Trixie_walk_right_06, Trixie_walk_right_07, Trixie_walk_right_08, Trixie_walk_right_09, Trixie_walk_right_10, Trixie_walk_right_11, Trixie_walk_right_12, Trixie_walk_right_13, Trixie_walk_right_14, Trixie_walk_right_15, Trixie_walk_right_16,
	Trixie_END,

	AJ,
	AJ_HUD_active, AJ_HUD_inactive, AJ_idle_left, AJ_idle_right,
	AJ_walk_left_01, AJ_walk_left_02, AJ_walk_left_03, AJ_walk_left_04, AJ_walk_left_05, AJ_walk_left_06, AJ_walk_left_07, AJ_walk_left_08, AJ_walk_left_09, AJ_walk_left_10, AJ_walk_left_11, AJ_walk_left_12, AJ_walk_left_13, AJ_walk_left_14, AJ_walk_left_15, AJ_walk_left_16,
	AJ_walk_right_01, AJ_walk_right_02, AJ_walk_right_03, AJ_walk_right_04, AJ_walk_right_05, AJ_walk_right_06, AJ_walk_right_07, AJ_walk_right_08, AJ_walk_right_09, AJ_walk_right_10, AJ_walk_right_11, AJ_walk_right_12, AJ_walk_right_13, AJ_walk_right_14, AJ_walk_right_15, AJ_walk_right_16,
	AJ_run_left_01, AJ_run_left_02, AJ_run_left_03, AJ_run_left_04, AJ_run_left_05, AJ_run_left_06, AJ_run_left_07, AJ_run_left_08, AJ_run_left_09, AJ_run_left_10, AJ_run_left_11, AJ_run_left_12,
	AJ_run_right_01, AJ_run_right_02, AJ_run_right_03, AJ_run_right_04, AJ_run_right_05, AJ_run_right_06, AJ_run_right_07, AJ_run_right_08, AJ_run_right_09, AJ_run_right_10, AJ_run_right_11, AJ_run_right_12,
	AJ_buck_left_1, AJ_buck_left_2, AJ_buck_left_3, AJ_buck_left_4, AJ_buck_left_5, AJ_buck_left_6, AJ_buck_left_7, AJ_buck_left_8,
	AJ_buck_right_1, AJ_buck_right_2, AJ_buck_right_3, AJ_buck_right_4, AJ_buck_right_5, AJ_buck_right_6, AJ_buck_right_7, AJ_buck_right_8,
	AJ_END,

	RD,
	RD_HUD_active, RD_HUD_inactive, RD_idle_left, RD_idle_right,
	RD_walk_left_01, RD_walk_left_02, RD_walk_left_03, RD_walk_left_04, RD_walk_left_05, RD_walk_left_06, RD_walk_left_07, RD_walk_left_08, RD_walk_left_09, RD_walk_left_10, RD_walk_left_11, RD_walk_left_12, RD_walk_left_13, RD_walk_left_14, RD_walk_left_15, RD_walk_left_16,
	RD_walk_right_01, RD_walk_right_02, RD_walk_right_03, RD_walk_right_04, RD_walk_right_05, RD_walk_right_06, RD_walk_right_07, RD_walk_right_08, RD_walk_right_09, RD_walk_right_10, RD_walk_right_11, RD_walk_right_12, RD_walk_right_13, RD_walk_right_14, RD_walk_right_15, RD_walk_right_16,
	RD_fly_left_01, RD_fly_left_02, RD_fly_left_03, RD_fly_left_04, RD_fly_left_05, RD_fly_left_06, RD_fly_left_07, RD_fly_left_08, RD_fly_left_09, RD_fly_left_10, RD_fly_left_11, RD_fly_left_12, RD_fly_left_13, RD_fly_left_14, RD_fly_left_15, RD_fly_left_16,
	RD_fly_right_01, RD_fly_right_02, RD_fly_right_03, RD_fly_right_04, RD_fly_right_05, RD_fly_right_06, RD_fly_right_07, RD_fly_right_08, RD_fly_right_09, RD_fly_right_10, RD_fly_right_11, RD_fly_right_12, RD_fly_right_13, RD_fly_right_14, RD_fly_right_15, RD_fly_right_16,
	RD_dash_left_01, RD_dash_left_02, RD_dash_left_03, RD_dash_left_04, RD_dash_left_05, RD_dash_left_06, RD_dash_left_07, RD_dash_left_08, RD_dash_left_09, RD_dash_left_10, RD_dash_left_11, RD_dash_left_12, RD_dash_left_13, RD_dash_left_14, RD_dash_left_15, RD_dash_left_16,
	RD_dash_right_01, RD_dash_right_02, RD_dash_right_03, RD_dash_right_04, RD_dash_right_05, RD_dash_right_06, RD_dash_right_07, RD_dash_right_08, RD_dash_right_09, RD_dash_right_10, RD_dash_right_11, RD_dash_right_12, RD_dash_right_13, RD_dash_right_14, RD_dash_right_15, RD_dash_right_16,
	RD_END,
	ZZZ_TexturesEnd };  // není skuteèná textura, jen pomocná zarážka

	std::map<TexName, LPDIRECT3DTEXTURE9> * Textures;
	std::vector<TexName> * LoadedTextures;

	TextureStorage(LPDIRECT3DDEVICE9 device);
	LPDIRECT3DTEXTURE9 GetTexture(TexName t);
	void LoadTextures();  // ?
	LPDIRECT3DTEXTURE9 LoadTexture(TexName t);  // private!
	void ReleaseTexture(TexName t);
	void ReleaseTextures(bool storeloadedtexnames);
	void ReloadTextures();
	~TextureStorage();
};