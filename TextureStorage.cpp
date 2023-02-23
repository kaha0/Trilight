#pragma warning( disable : 4482 )

#include<TextureStorage.h>
#include<Game.h>

TextureStorage::TextureStorage(LPDIRECT3DDEVICE9 device)
{
	Device = device;
	Textures = new std::map<TexName, LPDIRECT3DTEXTURE9>();
	LoadedTextures = NULL;
}

LPDIRECT3DTEXTURE9 TextureStorage::GetTexture(TexName t)
{
	std::map<TexName, LPDIRECT3DTEXTURE9>::iterator it = Textures->find(t);
	if (it == Textures->end())
	{
		//LPDIRECT3DTEXTURE9 tex = LoadTexture(Device, t);
		//if (tex) return tex;
		//else throw exception();

		return LoadTexture(t);
	}
	else return it->second;

	//LPDIRECT3DTEXTURE9 r = Textures->at(t);
	//return r;
}

// @deprecated
void TextureStorage::LoadTextures()
{
	for (int i = TexName::Black; i < TexName::ZZZ_TexturesEnd; ++i)
	{
		if ((TexName)i == TexName::AJ) continue;
		if ((TexName)i == TexName::AJ_END) continue;
		if ((TexName)i == TexName::RD) continue;
		if ((TexName)i == TexName::RD_END) continue;
		if ((TexName)i == TexName::Trixie) continue;
		if ((TexName)i == TexName::Trixie_END) continue;
		LoadTexture((TexName)i);
	}
}

LPDIRECT3DTEXTURE9 TextureStorage::LoadTexture(TexName t)
{
	std::map<TexName, LPDIRECT3DTEXTURE9>::iterator it = Textures->find(t);
	if (it != Textures->end()) return it->second;

	LPDIRECT3DTEXTURE9 nutex = NULL;
	switch (t)
	{
	case TexName::Black:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\black.png", Game::ScreenWidth, Game::ScreenHeight, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::White:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\white.png", Game::ScreenWidth, Game::ScreenHeight, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MainMenu_newgame:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\mm_ng.png", 370, 330, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MainMenu_load:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\mm_l.png", 370, 330, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MainMenu_quit:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\mm_q.png", 370, 330, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::LoadMenu_none:
		D3DXCreateTextureFromFile(Device, "data\\textures\\lm_none.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::LoadMenu_1_1:
		D3DXCreateTextureFromFile(Device, "data\\textures\\lm_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::LoadMenu_2_1:
		D3DXCreateTextureFromFile(Device, "data\\textures\\lm_21.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::LoadMenu_2_2:
		D3DXCreateTextureFromFile(Device, "data\\textures\\lm_22.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::LoadMenu_3_1:
		D3DXCreateTextureFromFile(Device, "data\\textures\\lm_31.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::LoadMenu_3_2:
		D3DXCreateTextureFromFile(Device, "data\\textures\\lm_32.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::LoadMenu_3_3:
		D3DXCreateTextureFromFile(Device, "data\\textures\\lm_33.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::GameMenu_resume:
		D3DXCreateTextureFromFile(Device, "data\\textures\\gm_r.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::GameMenu_quit:
		D3DXCreateTextureFromFile(Device, "data\\textures\\gm_q.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::VFX1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\v1.png", 1280, 960, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::VFX2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\v2.png", 1280, 960, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::VFX3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\v3.png", 1280, 960, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::EnergyBar_Active_L:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\eba_l.png", 3, 10, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::EnergyBar_Active_M:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\eba_m.png", 1, 10, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::EnergyBar_Active_R:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\eba_r.png", 3, 10, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::EnergyBar_Inactive_L:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\ebi_l.png", 3, 10, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::EnergyBar_Inactive_M:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\ebi_m.png", 1, 10, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::EnergyBar_Inactive_R:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\ebi_r.png", 3, 10, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::PU_Horseshoe:
		D3DXCreateTextureFromFile(Device, "data\\textures\\horseshoe.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::PU_Wings:
		D3DXCreateTextureFromFile(Device, "data\\textures\\wings.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::PU_Wand:
		D3DXCreateTextureFromFile(Device, "data\\textures\\wand.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::PU_Levit:
		D3DXCreateTextureFromFile(Device, "data\\textures\\levit.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Stars1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\stars1.png", 1500, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Moon:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\moon.png", 750, 750, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::GroundBox1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\ground.png", 1000, 500, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::GroundBox2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\ground.png", 2000, 500, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::GroundBox3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\ground.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Grass1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\grass1.png", 1000, 25, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Grass2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\grass2.png", 1000, 25, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Grass3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\grass3.png", 1000, 25, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Grass4:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\grass4.png", 1000, 25, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Grass5:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\grass5.png", 1000, 25, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Grass6:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\grass6.png", 1000, 25, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Grass7:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\grass7.png", 1000, 25, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Grass8:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\grass8.png", 1000, 25, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SmallRock:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\smallrock.png", 80, 80, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigTree:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigtree.png", 300, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigTree2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigtree2.png", 800, 1500, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Box01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\box.png", 105, 105, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar1:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star1.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar2:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star2.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar3:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star3.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar4:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star4.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar5:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star5.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar6:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star6.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar7:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star7.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar8:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star8.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MagicStar9:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star9.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl01.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl02.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl03.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_04:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl04.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_05:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl05.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_06:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl06.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_07:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl07.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_08:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl08.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_09:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl09.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_10:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl10.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BoxLevitate_11:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bl11.png", 150, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeathBox1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\red.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::TriggerBox:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\blu.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Cloud1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\cloud1.png", 400, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Cloud2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\cloud2.png", 350, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Cloud3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\cloud3.png", 300, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Cloud4:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\cloud4.png", 340, 120, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb01.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb02.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb03.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_04:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb04.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_05:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb05.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_06:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb06.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_07:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb07.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_08:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb08.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_09:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb09.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_10:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb10.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_11:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb11.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_12:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb12.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_13:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb13.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_14:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb14.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_15:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb15.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SleepBubble_16:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\sb16.png", 200, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree01.png", 230, 460, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree02.png", 220, 430, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree03.png", 250, 470, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_04:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree04.png", 240, 490, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_05:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree05.png", 240, 500, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_06:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree06.png", 240, 510, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_07:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree07.png", 240, 530, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_08:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree08.png", 230, 480, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_09:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree09.png", 240, 540, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AppleTree_10:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\appletree10.png", 270, 530, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree01.png", 250, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree02.png", 250, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree03.png", 220, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree04:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree04.png", 220, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree05:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree05.png", 220, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree06:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree06.png", 220, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree07:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree07.png", 220, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree08:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree08.png", 220, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree09:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree09.png", 220, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::DeadTree10:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\deadtree10.png", 220, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Stump:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\stump.png", 100, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::FallenTree:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\fallentree.png", 800, 115, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Lamppost1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\lamppost.png", 128, 180, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Lantern1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\lantern.png", 330, 330, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Building01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\building01.png", 550, 450, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Building02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\building02.png", 460, 405, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Building03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\building03.png", 560, 440, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Building04:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\building04.png", 490, 390, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Building05:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\building05.png", 340, 450, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Town_Hall:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\townhall.png", 660, 1150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Farmhouse:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\farmhouse.png", 940, 840, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::ChickenCoop:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\chickencoop.png", 490, 275, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Fence1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\fence1.png", 290, 60, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Fence2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\fence2.png", 280, 60, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Fence3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\fence3.png", 280, 60, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::HayBale1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\hay1.png", 175, 105, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::HayBale2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\hay2.png", 105, 65, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Shed:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\shed.png", 500, 330, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_whole:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_whole.png", 250, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_cracked:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_cracked.png", 250, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break01.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break02.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break03.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break04:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break04.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break05:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break05.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break06:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break06.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break07:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break07.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break08:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break08.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break09:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break09.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break10:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break10.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break11:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break11.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break12:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break12.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break13:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break13.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break14:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break14.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break15:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break15.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break16:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break16.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break17:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break17.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break18:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break18.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break19:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break19.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BigRock_break20:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\bigrock_break20.png", 500, 200, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Scaffolding01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\scaff1.png", 650, 330, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Scaffolding02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\scaff2.png", 800, 720, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Rope_segment:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\rope_segment.png", 8, 98, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Pulley_Rope:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\pulley_rope.png", 8, 20, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Rope_platform:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\rope_platform.png", 250, 230, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RopeBridge_segment:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\ropebridgesegment.png", 50, 20, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Water01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\water1.png", 1000, 300, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Water02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\water2.png", 1000, 300, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Water03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\water3.png", 1000, 300, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::MobileRock:
		D3DXCreateTextureFromFile(Device, "data\\textures\\mobilerock.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Platform1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\platform1.png", 300, 50, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Platform2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\platform2.png", 300, 20, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Platform3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\platform2.png", 150, 20, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::SeesawBase:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\ss.png", 128, 80, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BrokenPlatform1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\brokenplatform1.png", 600, 50, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BrokenPlatform2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\brokenplatform2.png", 600, 90, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::CrossSupports:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\cross_supports.png", 600, 250, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::VertPlank:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\vplank.png", 50, 500, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Ramp_left:
		D3DXCreateTextureFromFile(Device, "data\\textures\\ramp_l.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Ramp_right:
		D3DXCreateTextureFromFile(Device, "data\\textures\\ramp_r.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Palisade:
		D3DXCreateTextureFromFile(Device, "data\\textures\\palisade.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::GatePassage:
		D3DXCreateTextureFromFile(Device, "data\\textures\\gate.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::WaterWheel:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\wheel.png", 600, 600, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Mill:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\mill.png", 1500, 800, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::StarPillar:
		D3DXCreateTextureFromFile(Device, "data\\textures\\star_pillar.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::BallPillar:
		D3DXCreateTextureFromFile(Device, "data\\textures\\ball_pillar.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Mountains:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\mountains.png", 2000, 700, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Seth1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\s1.png", 1000, 1000, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Seth2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\s2.png", 140, 210, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Seth3_1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\s3.png", 70, 105, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Seth3_2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\s3a.png", 70, 105, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Seth3_3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\s3b.png", 70, 105, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Gray:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\gray.png", 600, 400, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Change:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\change.png", 550, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Draw:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\draw.png", 200, 50, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Shift:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\shift.png", 310, 60, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_End1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\end1.png", 700, 190, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_End2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\end2.png", 1000, 500, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_End3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\end3.png", 950, 190, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_End4:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\end4.png", 1000, 300, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Jump:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\jump.png", 300, 50, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Savepoint:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\savepoint.png", 350, 50, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Swim:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\swim.png", 340, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Buck1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\buck1.png", 300, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Buck2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\buck2.png", 500, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Fly:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\fly.png", 400, 128, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_IncBoxes:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\incboxes.png", 500, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Levit1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\levit1.png", 500, 128, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Text_Levit2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\levit2.png", 420, 150, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	// <-- Zombie -->
	case TexName::Zombie_left_01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left01.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left02.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left03.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_04:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left04.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_05:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left05.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_06:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left06.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_07:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left07.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_08:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left08.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_09:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left09.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_10:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left10.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_11:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left11.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_12:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left12.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_13:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left13.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_14:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left14.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_15:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left15.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_left_16:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\left16.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_01:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right01.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_02:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right02.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_03:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right03.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_04:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right04.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_05:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right05.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_06:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right06.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_07:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right07.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_08:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right08.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_09:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right09.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_10:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right10.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_11:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right11.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_12:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right12.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_13:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right13.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_14:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right14.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_15:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right15.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Zombie_right_16:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\zombie\\right16.png", 100, 100, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Parasprite1:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\parasprite1.png", 40, 35, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Parasprite2:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\parasprite2.png", 40, 35, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Parasprite3:
		D3DXCreateTextureFromFileEx(Device, "data\\textures\\parasprite3.png", 40, 35, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	// <-- Trixie -->
	case TexName::Trixie:
		{
			for (int i = TexName::Trixie_HUD_active; i < TexName::Trixie_END; ++i)
			{
				LoadTexture((TexName)i);
			}
			return NULL;
		}

	case TexName::Trixie_HUD_active:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_HUD_active.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Trixie_HUD_inactive:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_HUD_inactive.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Trixie_idle_left:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_idle_left.png", &nutex);
		//D3DXCreateTextureFromFileInMemory(...);
		//D3DXCreateTextureFromFileEx(Device, "data\\textures\\trixie\\trixie_idle_left.png", 128, 128, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Trixie_idle_right:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_idle_right.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Trixie_walk_left_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_left_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_left_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::Trixie_walk_right_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::Trixie_walk_right_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\trixie\\trixie_walk_right_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	// <-- AJ -->
	case TexName::AJ:
		{
			for (int i = TexName::AJ_HUD_active; i < TexName::AJ_END; ++i)
			{
				LoadTexture((TexName)i);
			}
			return NULL;
		}

	case TexName::AJ_HUD_active:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\aj_hud_a.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_HUD_inactive:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\aj_hud_i.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_idle_left:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\idle_left.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_idle_right:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\idle_right.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_walk_left_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_left_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_left_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_walk_right_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_walk_right_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\walk_right_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_run_left_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_left_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_left_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_run_right_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::AJ_run_right_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\run_right_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_left_1:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_left_1.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_left_2:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_left_2.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_left_3:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_left_3.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_left_4:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_left_4.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_left_5:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_left_5.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_left_6:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_left_6.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_left_7:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_left_7.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_left_8:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_left_8.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_right_1:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_right_1.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_right_2:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_right_2.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_right_3:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_right_3.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_right_4:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_right_4.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_right_5:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_right_5.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_right_6:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_right_6.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_right_7:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_right_7.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::AJ_buck_right_8:
		D3DXCreateTextureFromFile(Device, "data\\textures\\aj\\buck_right_8.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	// <-- RD -->
	case TexName::RD:
		{
			for (int i = TexName::RD_HUD_active; i < TexName::RD_END; ++i)
			{
				LoadTexture((TexName)i);
			}
			return NULL;
		}

	case TexName::RD_HUD_active:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\rd_hud_a.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_HUD_inactive:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\rd_hud_i.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_idle_left:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\idle_left.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_idle_right:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\idle_right.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_walk_left_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_left_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_left_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_walk_right_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_walk_right_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\walk_right_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_fly_left_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_left_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_left_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_fly_right_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_fly_right_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\fly_right_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_dash_left_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_left_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_left_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;

	case TexName::RD_dash_right_01:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_01.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_02:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_02.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_03:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_03.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_04:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_04.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_05:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_05.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_06:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_06.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_07:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_07.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_08:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_08.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_09:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_09.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_10:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_10.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_11:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_11.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_12:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_12.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_13:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_13.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_14:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_14.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_15:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_15.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
		
	case TexName::RD_dash_right_16:
		D3DXCreateTextureFromFile(Device, "data\\textures\\rd\\dash_right_16.png", &nutex);
		Textures->insert(std::pair<TexName, LPDIRECT3DTEXTURE9>(t, nutex));
		return nutex;
	}

	return NULL;
}

void TextureStorage::ReleaseTexture(TexName t)
{
	std::map<TexName, LPDIRECT3DTEXTURE9>::iterator it = Textures->find(t);
	if (it == Textures->end()) return;
	it->second->Release();
	Textures->erase(it);
}

void TextureStorage::ReleaseTextures(bool storeloadedtexnames)
{
	if (storeloadedtexnames)
	{
		if (LoadedTextures) delete LoadedTextures;
		LoadedTextures = new std::vector<TexName>();
	}

	for (std::map<TexName, LPDIRECT3DTEXTURE9>::iterator it = Textures->begin(); it != Textures->end(); ++it)
	{
		if (storeloadedtexnames) LoadedTextures->push_back(it->first);
		if (it->second) it->second->Release();
	}
	Textures->clear();
}

void TextureStorage::ReloadTextures()
{
	if (LoadedTextures)
	{
		for (std::vector<TexName>::iterator it = LoadedTextures->begin(); it != LoadedTextures->end(); it++)
			LoadTexture(*it);
		delete LoadedTextures;
		LoadedTextures = NULL;
	}
}

TextureStorage::~TextureStorage()
{
	//ReleaseTextures(false);
	delete Textures;
}