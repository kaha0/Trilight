#pragma warning( disable : 4482 )

#include<Game.h>

int Game::ScreenHeight;
int Game::ScreenWidth;
float Game::PositionX;
float Game::PositionY;
Player * Game::player;

Game::Game(int W, int H)
{
	Game::ScreenWidth = W;
	Game::ScreenHeight = H;
	Game::PositionX = 0.0f;
	Game::PositionY = 0.0f;

	devicelost = false;
	map = NULL;
	player = NULL;
	points = NULL;
	Textures = NULL;
	Sounds = NULL;
	vfx = NULL;
	LevitAura = NULL;
	drawing = false;
	levitating = false;
	Savestate = new SaveState();
	stateaux_ul = 0;
	stateaux_l = 0;
}

void Game::InitGame(LPDIRECT3DDEVICE9 device, LPDIRECTSOUND8 dsound)
{
	Sounds = new SoundStorage(dsound);
	Textures = new TextureStorage(device);
	MainMenu_ng = Textures->LoadTexture(TextureStorage::TexName::MainMenu_newgame);
	MainMenu_l = Textures->LoadTexture(TextureStorage::TexName::MainMenu_load);
	MainMenu_q = Textures->LoadTexture(TextureStorage::TexName::MainMenu_quit);
	LoadMenu_n = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_none);
	LoadMenu_11 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_1_1);
	LoadMenu_21 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_2_1);
	LoadMenu_22 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_2_2);
	LoadMenu_31 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_3_1);
	LoadMenu_32 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_3_2);
	LoadMenu_33 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_3_3);

	GameMenu_r = Textures->LoadTexture(TextureStorage::TexName::GameMenu_resume);
	GameMenu_q = Textures->LoadTexture(TextureStorage::TexName::GameMenu_quit);
	Black = Textures->LoadTexture(TextureStorage::TexName::Black);
	White = Textures->LoadTexture(TextureStorage::TexName::White);

	EBAL = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Active_L);
	EBAM = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Active_M);
	EBAR = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Active_R);
	EBIL = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Inactive_L);
	EBIM = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Inactive_M);
	EBIR = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Inactive_R);

	vfx = new GameVFX(Textures);
	LevitAura = new BoxLevitateAura(Textures);
	
	Device = device;
	Dsound = dsound;
#ifdef _DEBUG
	logger = new Logger<Game>(this, device);
#endif
	State = Game::GameState::MainMenu_newgame;
}

void Game::Render(LPDIRECT3DDEVICE9 device)
{
    if (device == NULL) return;

	device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	if(SUCCEEDED(device->BeginScene()))
	{
		LPD3DXSPRITE sprite = NULL;
		if (SUCCEEDED(D3DXCreateSprite(device, &sprite)))
		{
			sprite->Begin(D3DXSPRITE_ALPHABLEND);

			switch (State)
			{
			case GameState::Running:
				{
					map->Step();
					DoPhysics();
					CheckTriggers();

					MoveScreen();
					SubtractEnergy();
					FillEnergy();

					if (player->playerKA->Actual == player->playerKA->DL || player->playerKA->Actual == player->playerKA->DR)
					{
						stateaux_ul = 0x0FFFFFFF;
						stateaux_l = 0;
						State = GameState::DeathReset;
					}

					DrawActors(sprite);
					DrawVFX(sprite);
					DrawHUD(sprite);
#ifdef _DEBUG
					DrawTriggers(sprite);  // DEBUG
#endif
					break;
				}
			case GameState::Cutscene:
				{
//					map->Step();
//					DoPhysics();
//					CheckTriggers();
//					MoveScreen();
//					SubtractEnergy();
//					FillEnergy();
//
//					DrawActors(sprite);
//					DrawVFX(sprite);
//					DrawHUD(sprite);
//#ifdef _DEBUG
//					DrawTriggers(sprite);  // DEBUG
//#endif
					DoCutscene(sprite);
					break;
				}
			case GameState::DeathReset:
				{
					if (stateaux_ul == 0xFFFFFFFF) // FadeOut
					{
						if (stateaux_l == 30)  // ještì nìkolikrát vykreslit èernou obrazovku
						{
							map->ResetToSavestate(Savestate);
							PositionX = Savestate->screenpos.x;
							PositionY = Savestate->screenpos.y;
							//FadeOut = 0x0FFFFFFF;
							//stateaux_l = 0;
							State = GameState::Running;
						}
						else
						{
							++stateaux_l;
						}
					}
					else
					{
						map->Step();
						DrawActors(sprite);
						DrawVFX(sprite);
						DrawHUD(sprite);
#ifdef _DEBUG
						DrawTriggers(sprite);  // DEBUG
#endif

						sprite->Draw(Black, NULL, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), stateaux_ul);
						stateaux_ul += 0x10000000;
					}
					break;
				}
			case GameState::MainMenu_newgame:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 185;
					vec.y = (float)ScreenHeight / 2.0f - 165;
					vec.z = 0.0f;
					sprite->Draw(MainMenu_ng, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::MainMenu_load:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 185;
					vec.y = (float)ScreenHeight / 2.0f - 165;
					vec.z = 0.0f;
					sprite->Draw(MainMenu_l, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::MainMenu_quit:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 185;
					vec.y = (float)ScreenHeight / 2.0f - 165;
					vec.z = 0.0f;
					sprite->Draw(MainMenu_q, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::LoadMenu_none:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 256;
					vec.y = (float)ScreenHeight / 2.0f - 64;
					vec.z = 0.0f;
					sprite->Draw(LoadMenu_n, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::LoadMenu_1_1:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 256;
					vec.y = (float)ScreenHeight / 2.0f - 256;
					vec.z = 0.0f;
					sprite->Draw(LoadMenu_11, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::LoadMenu_2_1:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 256;
					vec.y = (float)ScreenHeight / 2.0f - 256;
					vec.z = 0.0f;
					sprite->Draw(LoadMenu_21, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::LoadMenu_2_2:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 256;
					vec.y = (float)ScreenHeight / 2.0f - 256;
					vec.z = 0.0f;
					sprite->Draw(LoadMenu_22, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::LoadMenu_3_1:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 256;
					vec.y = (float)ScreenHeight / 2.0f - 256;
					vec.z = 0.0f;
					sprite->Draw(LoadMenu_31, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::LoadMenu_3_2:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 256;
					vec.y = (float)ScreenHeight / 2.0f - 256;
					vec.z = 0.0f;
					sprite->Draw(LoadMenu_32, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::LoadMenu_3_3:
				{
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 256;
					vec.y = (float)ScreenHeight / 2.0f - 256;
					vec.z = 0.0f;
					sprite->Draw(LoadMenu_33, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::NextLevel:
				{
					if (stateaux_ul == 0xFFFFFFFF)
					{
						if (stateaux_l == 30)  // ještì nìkolikrát vykreslit èernou obrazovku
						{
							int nextlevel = map->level + 1;
							map->SkillsToState(Savestate);
							delete map;
							Savestate->Reset();
							if (nextlevel < 4)
							{
								if (!SaveSkills(Savestate, nextlevel)) MessageBox(NULL, "Error while writing data to file. You should probably exit to main menu and reload your game.", "Error", NULL);
							}
							map = Map::LoadMap(nextlevel, Textures, Sounds, Savestate, true);
							PositionX = Savestate->screenpos.x;
							PositionY = Savestate->screenpos.y;
							State = GameState::Running;
						}
						else
						{
							++stateaux_l;
						}
					}
					else
					{
						map->Step();
						DrawActors(sprite);
						DrawVFX(sprite);
						DrawHUD(sprite);
#ifdef _DEBUG
						DrawTriggers(sprite);  // DEBUG
#endif

						sprite->Draw(Black, NULL, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), stateaux_ul);
						stateaux_ul += 0x10000000;
					}
					break;
				}
			case GameState::Paused:
				{
					DrawActors(sprite);
					DrawVFX(sprite);
					DrawHUD(sprite);
#ifdef _DEBUG
					DrawTriggers(sprite);  // DEBUG
#endif
					sprite->Draw(Black, NULL, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0x80FFFFFF);
					break;
				}
			case GameState::GameMenu_resume:
				{
					DrawActors(sprite);
					DrawVFX(sprite);
					DrawHUD(sprite);
#ifdef _DEBUG
					DrawTriggers(sprite);  // DEBUG
#endif
					sprite->Draw(Black, NULL, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0x80FFFFFF);
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 128;
					vec.y = (float)ScreenHeight / 2.0f - 128;
					vec.z = 0.0f;
					sprite->Draw(GameMenu_r, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			case GameState::GameMenu_quit:
				{
					DrawActors(sprite);
					DrawVFX(sprite);
					DrawHUD(sprite);
#ifdef _DEBUG
					DrawTriggers(sprite);  // DEBUG
#endif
					sprite->Draw(Black, NULL, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0x80FFFFFF);
					D3DXVECTOR3 vec;
					vec.x = (float)ScreenWidth / 2.0f - 128;
					vec.y = (float)ScreenHeight / 2.0f - 128;
					vec.z = 0.0f;
					sprite->Draw(GameMenu_q, NULL, NULL, &vec, 0xFFFFFFFF);
					break;
				}
			}

			sprite->End();
			sprite->Release();

#ifdef _DEBUG
			logger->Draw(device);
#endif
		}
		device->EndScene();
	}
	if (device->Present( NULL, NULL, NULL, NULL ) == D3DERR_DEVICELOST)
		devicelost = true;

//D3DXVECTOR2 spriteCentre=D3DXVECTOR2(50.0f,100.0f);
//D3DXVECTOR2 trans=D3DXVECTOR2(100.0f,100.0f);
//D3DXMATRIX mat;
//D3DXVECTOR2 scaling(1.0f,1.0f);
//// out, scaling centre, scaling rotation, scaling, rotation centre, rotation, translation
//D3DXMatrixTransformation2D(&mat, NULL, 0.0f, &scaling, NULL, 0.0f, &trans);
//sprite->SetTransform(&mat);
//sprite->Draw(pTexture, NULL, NULL, NULL, 0xFFFFFFFF);   <-- takhle vykreslit rotující

//D3DXVECTOR3 vec;
//vec.x = 100.0f;
//vec.y = 100.0f;
//vec.z = 0.0f;
//sprite->Draw(pTexture, NULL, NULL, &vec, 0xFFFFFFFF);  //  <-- takhle nerotující

//PAUSED
//======
//LPDIRECT3DSURFACE9 INsurface;   //takhle to nejde :/
//LPDIRECT3DSURFACE9 OUTsurface;
//LPDIRECT3DTEXTURE9 shadTEMP;
//device->CreateOffscreenPlainSurface(ScreenWidth, ScreenHeight, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &INsurface, NULL);
////device->GetRenderTarget(0, &surface);
//device->ColorFill(INsurface, NULL, D3DCOLOR_ARGB(0x80, 0, 0, 0));  // proè nefunguje alpha channel ?
//shadTEMP->GetSurfaceLevel(0, &OUTsurface);
//device->UpdateSurface(INsurface, NULL, OUTsurface, NULL);
//OUTsurface->Release();
//sprite->Draw(shadTEMP, NULL, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0xFFFFFFFF);
}

void Game::DrawActors(LPD3DXSPRITE sprite)
{
	for (std::multimap<int, Actor*>::iterator it = map->Actors.begin(); it != map->Actors.end(); ++it)
	{
		Actor * a = (*it).second;
		if (State == GameState::Running || State == GameState::Cutscene)
		{
			Breakable * b = dynamic_cast<Breakable *>(a);
			if (b)
			{
				if (b->sprite->terminal)
				{
					b->Draw(sprite);  // naposledy se vykreslí ta terminal sprite
					b->drawenabled = false;
					map->DestroyBody(b);
					continue;
				}
			}

			NPC * npc = dynamic_cast<NPC *>(a);
			if (npc) npc->Step();

			if (levitBody && (a == levitBody))
			{
				MagicBox * mb = dynamic_cast<MagicBox *>(a);
				if (mb)
				{
					//LevitAura->box = mb;  // tohle je zbyteèný
					if (LevitAura->framesdrawn == LevitAura->fps)
					{
						LevitAura->framesdrawn = 1;
						LevitAura->NextSprite();
					}
					else LevitAura->framesdrawn++;
					LevitAura->Draw(sprite);
				}
			}

			if (a->fps == 1) a->NextSprite();
			if (a->fps > 1)
			{
				if (a->framesdrawn == a->fps)
				{
					a->framesdrawn = 1;
					a->NextSprite();
				}
				else a->framesdrawn++;
			}
		}
		a->Draw(sprite);
	}
}

void Game::DrawTriggers(LPD3DXSPRITE sprite)
{
#ifdef _DEBUG
	for (std::vector<TriggerArea *>::iterator it = map->Triggers.begin(); it != map->Triggers.end(); it++)
	{
		TriggerArea * ta = (*it);
		ta->Draw(sprite);
	}
#endif
}

void Game::DrawVFX(LPD3DXSPRITE sprite)
{
	if (vfx->framesdrawn == vfx->fps)
	{
		vfx->framesdrawn = 0;
		vfx->NextSprite();
	}
	else vfx->framesdrawn++;

	vfx->Draw(sprite);
}

void Game::MoveScreen()
{
	D3DXVECTOR3 ppos = GetPosOnScreen(player);
	Movement pmv = player->movement;
	if (pmv == Movement::FallL || pmv == Movement::FlyL || pmv == Movement::IdleL || pmv == Movement::JumpL
		|| pmv == Movement::RunL || pmv == Movement::BuckL || pmv == Movement::WalkL || pmv == Movement::DashL || pmv == Movement::DeathL)
	{  // facing left
		if (ppos.x < 300) PositionX -= 0.1f;  // posunout ještì víc?
		else if (ppos.x < 500) PositionX -= 0.045f;
		else if (ppos.x < 700) PositionX -= 0.03f;

		if (ppos.x > ScreenWidth - 100) PositionX += 0.1f;
		if (ppos.x > ScreenWidth - 200) PositionX += 0.045f;
		else if (ppos.x > ScreenWidth - 300) PositionX += 0.03f;
	}
	else  // facing right
	{
		if (ppos.x > ScreenWidth - 300) PositionX += 0.1f;  // posunout ještì víc?
		else if (ppos.x > ScreenWidth - 500) PositionX += 0.045f;
		else if (ppos.x > ScreenWidth - 700) PositionX += 0.03f;

		if (ppos.x < 100) PositionX -= 0.1f;
		else if (ppos.x < 200) PositionX -= 0.045f;
		else if (ppos.x < 300) PositionX -= 0.03f;
	}

	//nahoøe a dole
	if (ppos.y < 200) PositionY += 0.2f;
	else if (ppos.y < 300) PositionY += 0.1f;
	else if (ppos.y < 400) PositionY += 0.05f;

	if (ppos.y > ScreenHeight - 50) PositionY -= 0.4f;
	else if (ppos.y > ScreenHeight - 100) PositionY -= 0.2f;
	else if (ppos.y > ScreenHeight - 150) PositionY -= 0.1f;
	else if (ppos.y > ScreenHeight - 200) PositionY -= 0.05f;
}

void Game::KeyDown(WPARAM key)
{
#ifdef _DEBUG
	logger->LogMsg("keydown ", key);
#endif

	switch (State)
	{
		case GameState::MainMenu_newgame:
		{
			if (key == VK_DOWN) State = GameState::MainMenu_load;
			if (key == VK_RETURN)
			{
				map = Map::LoadMap(1, Textures, Sounds, Savestate, false);
				if (!SaveSkills(Savestate, 1)) MessageBox(NULL, "Error while writing data to file. You should probably exit to main menu and reload your game.", "Error", NULL);
				PositionX = Savestate->screenpos.x;
				PositionY = Savestate->screenpos.y;
				//State = GameState::Running;

				stateaux_l = 1;
				stateaux_ul = 0;
				State = GameState::Cutscene;
			}
			return;
		}

		case GameState::MainMenu_load:
		{
			if (key == VK_DOWN) State = GameState::MainMenu_quit;
			if (key == VK_UP) State = GameState::MainMenu_newgame;
			if (key == VK_RETURN)
			{
				std::ifstream r;
				try
				{
					r.open("data\\data.sav", std::ios::binary);
					if (!r.is_open()) throw std::exception();
					if (r.peek() == -1) throw std::exception();
				}
				catch (...)
				{
					State = GameState::LoadMenu_none;
					return;
				}

				r >> std::noskipws;
				unsigned char l;
				r >> l;
				r.close();
				switch (l)
				{
				case 1:
					State = GameState::LoadMenu_1_1;
					return;
				case 2:
					State = GameState::LoadMenu_2_1;
					return;
				case 3:
					State = GameState::LoadMenu_3_1;
					return;
				// etc.

				default:
					// tohle by se nemìlo stát
					//MessageBox(NULL, "Someone tampered with my savedata!", "Error", NULL);
					r.close();
					TruncSaveFile();
					//remove("data\\data.sav");
					State = GameState::LoadMenu_none;
					break;
				}
			}
			return;
		}

		case GameState::MainMenu_quit:
		{
			if (key == VK_UP) State = GameState::MainMenu_load;
			if (key == VK_RETURN) State = GameState::Quit;
			return;
		}

		case GameState::LoadMenu_none:
		{
			if (key == VK_ESCAPE) State = GameState::MainMenu_newgame;
			return;
		}

		case GameState::LoadMenu_1_1:
		{
			if (key == VK_ESCAPE) State = GameState::MainMenu_newgame;
			if (key == VK_RETURN)
			{
				if (LoadSavedSkills(Savestate, 1) == false)
				{
					MessageBox(NULL, "Error while loading savedata: file is corrupt, removing.", "Error", NULL);
					Savestate->Reset();
					State = GameState::LoadMenu_none;
					TruncSaveFile();  // ?
					return;
				}
				map = Map::LoadMap(1, Textures, Sounds, Savestate, true);
				PositionX = Savestate->screenpos.x;
				PositionY = Savestate->screenpos.y;
				//State = GameState::Running;
				stateaux_l = 1;
				stateaux_ul = 0;
				State = GameState::Cutscene;
			}
			return;
		}

		case GameState::LoadMenu_2_1:
		{
			if (key == VK_DOWN) State = GameState::LoadMenu_2_2;
			if (key == VK_ESCAPE) State = GameState::MainMenu_newgame;
			if (key == VK_RETURN)
			{
				if (LoadSavedSkills(Savestate, 1) == false)
				{
					MessageBox(NULL, "Error while loading savedata: file is corrupt, removing.", "Error", NULL);
					Savestate->Reset();
					State = GameState::LoadMenu_none;
					TruncSaveFile();  // ?
					return;
				}
				map = Map::LoadMap(1, Textures, Sounds, Savestate, true);
				PositionX = Savestate->screenpos.x;
				PositionY = Savestate->screenpos.y;
				//State = GameState::Running;
				stateaux_l = 1;
				stateaux_ul = 0;
				State = GameState::Cutscene;
			}
			return;
		}

		case GameState::LoadMenu_2_2:
		{
			if (key == VK_UP) State = GameState::LoadMenu_2_1;
			if (key == VK_ESCAPE) State = GameState::MainMenu_newgame;
			if (key == VK_RETURN)
			{
				if (LoadSavedSkills(Savestate, 2) == false)
				{
					MessageBox(NULL, "Error while loading savedata: file is corrupt, removing.", "Error", NULL);
					Savestate->Reset();
					State = GameState::LoadMenu_none;
					TruncSaveFile();  // ?
					return;
				}
				map = Map::LoadMap(2, Textures, Sounds, Savestate, true);
				PositionX = Savestate->screenpos.x;
				PositionY = Savestate->screenpos.y;
				State = GameState::Running;
			}
			return;
		}

		case GameState::LoadMenu_3_1:
		{
			if (key == VK_DOWN) State = GameState::LoadMenu_3_2;
			if (key == VK_ESCAPE) State = GameState::MainMenu_newgame;
			if (key == VK_RETURN)
			{
				if (LoadSavedSkills(Savestate, 1) == false)
				{
					MessageBox(NULL, "Error while loading savedata: file is corrupt, removing.", "Error", NULL);
					Savestate->Reset();
					State = GameState::LoadMenu_none;
					TruncSaveFile();  // ?
					return;
				}
				map = Map::LoadMap(1, Textures, Sounds, Savestate, true);
				PositionX = Savestate->screenpos.x;
				PositionY = Savestate->screenpos.y;
				//State = GameState::Running;
				stateaux_l = 1;
				stateaux_ul = 0;
				State = GameState::Cutscene;
			}
			return;
		}

		case GameState::LoadMenu_3_2:
		{
			if (key == VK_UP) State = GameState::LoadMenu_3_1;
			if (key == VK_DOWN) State = GameState::LoadMenu_3_3;
			if (key == VK_ESCAPE) State = GameState::MainMenu_newgame;
			if (key == VK_RETURN)
			{
				if (LoadSavedSkills(Savestate, 2) == false)
				{
					MessageBox(NULL, "Error while loading savedata: file is corrupt, removing.", "Error", NULL);
					Savestate->Reset();
					State = GameState::LoadMenu_none;
					TruncSaveFile();  // ?
					return;
				}
				map = Map::LoadMap(2, Textures, Sounds, Savestate, true);
				PositionX = Savestate->screenpos.x;
				PositionY = Savestate->screenpos.y;
				State = GameState::Running;
			}
			return;
		}

		case GameState::LoadMenu_3_3:
		{
			if (key == VK_UP) State = GameState::LoadMenu_3_2;
			if (key == VK_ESCAPE) State = GameState::MainMenu_newgame;
			if (key == VK_RETURN)
			{
				if (LoadSavedSkills(Savestate, 3) == false)
				{
					MessageBox(NULL, "Error while loading savedata: file is corrupt, removing.", "Error", NULL);
					Savestate->Reset();
					State = GameState::LoadMenu_none;
					TruncSaveFile();  // ?
					return;
				}
				map = Map::LoadMap(3, Textures, Sounds, Savestate, true);
				PositionX = Savestate->screenpos.x;
				PositionY = Savestate->screenpos.y;
				State = GameState::Running;
			}
			return;
		}

		case GameState::GameMenu_resume:
		{
			if (key == VK_ESCAPE) State = GameState::Running;
			if (key == VK_RETURN) State = GameState::Running;
			if (key == VK_DOWN) State = GameState::GameMenu_quit;
			return;
		}

		case GameState::GameMenu_quit:
		{
			if (key == VK_ESCAPE) State = GameState::Running;
			if (key == VK_UP) State = GameState::GameMenu_resume;
			if (key == VK_RETURN)
			{
				delete map;
#ifdef _DEBUG
				logger->log = false;
#endif
				map = NULL;
				Savestate->Reset();
				State = GameState::MainMenu_newgame;
			}
			return;
		}

		case GameState::Running:
		{
			switch (key)  // for key-codes see "C:\PRGII\C++\virtual key-codes.txt"
			{
				#ifdef _DEBUG
				case VK_F1:
					logger->log = !(logger->log);
					return;

				case 0x56:  // V
					PositionX += 0.1f;
					return;

				case 0x42:  // B
					PositionX -= 0.1f;
					return;

				case 0x4E:  // N
					PositionY += 0.1f;
					return;

				case 0x4D:  // M
					PositionY -= 0.1f;
					return;

				case 0x4C:  // L
					player->playerKA->Actual = player->playerKA->DR;
					return;
				#endif

				case 0x50:
					Pause();
					return;

				case VK_ESCAPE:
					if (drawing)
					{
						drawing = false;
						DeletePoints();
					}
					if (levitating) RMBup(0, 0);
					State = GameState::GameMenu_resume;
					return;

				case 0x31:  //  num 1
				{
					if (player->CurrentPony == player->AJ) return;
					if (map->CanBeAJ)
					{
						if ((player->CurrentPony == player->RD) && (player->playerKA->Actual == player->playerKA->FlyL || player->playerKA->Actual == player->playerKA->FlyR))
							player->Fall(true);
						if (player->CurrentPony == player->Trixie)
						{
							if (drawing)
							{
								drawing = false;
								DeletePoints();
							}
							if (levitating) RMBup(0, 0);
						}

						player->SwitchToAJ();
					}
					return;
				}

				case 0x32:  //  num 2
				{
					if (player->CurrentPony == player->RD) return;
					if (map->CanBeRD)
					{
						if (player->CurrentPony == player->AJ)
						{
							if (player->playerKA->Actual->mv == Movement::RunL)
								player->playerKA->Actual = player->playerKA->WL;
							if (player->playerKA->Actual->mv == Movement::RunR)
								player->playerKA->Actual = player->playerKA->WR;
							if (player->playerKA->Actual->mv == Movement::BuckL)
								player->playerKA->Actual = player->playerKA->IL;
							if (player->playerKA->Actual->mv == Movement::BuckR)
								player->playerKA->Actual = player->playerKA->IR;
						}
						if (player->CurrentPony == player->Trixie)
						{
							if (drawing)
							{
								drawing = false;
								DeletePoints();
							}
							if (levitating) RMBup(0, 0);
						}

						player->SwitchToRD();
					}
					return;
				}

				case 0x33:  //  num 3
				{
					if (player->CurrentPony == player->Trixie) return;
					if (map->CanBeTrixie)
					{
						if (player->CurrentPony == player->AJ)
						{
							if (player->playerKA->Actual->mv == Movement::RunL)
								player->playerKA->Actual = player->playerKA->WL;
							if (player->playerKA->Actual->mv == Movement::RunR)
								player->playerKA->Actual = player->playerKA->WR;
							if (player->playerKA->Actual->mv == Movement::BuckL)
								player->playerKA->Actual = player->playerKA->IL;
							if (player->playerKA->Actual->mv == Movement::BuckR)
								player->playerKA->Actual = player->playerKA->IR;
						}
						if ((player->CurrentPony == player->RD) && (player->playerKA->Actual == player->playerKA->FlyL || player->playerKA->Actual == player->playerKA->FlyR))
							player->Fall(true);

						player->SwitchToTrixie();
					}
					return;
				}

				case 0x45:
				{
					if (player->CurrentPony == player->Trixie)
					{  // try to unsummon box
						IsMagicboxQueryCallback imqc = IsMagicboxQueryCallback();
						POINT p;
						GetCursorPos(&p);
						b2Vec2 pos = Game::GetPosInWorld(p.x, p.y);
						b2AABB aabb;
						aabb.lowerBound.Set(pos.x - 0.02f, pos.y - 0.02f);
						aabb.upperBound.Set(pos.x + 0.02f, pos.y + 0.02f);
						map->world->QueryAABB(&imqc, aabb);

						if (imqc.box)
						{
							if (levitating && (levitBody == imqc.box)) RMBup(0, 0);
							player->Trixie->RemoveBox(imqc.box);
							map->DeleteActor(imqc.box);
						}
					}
					else player->KeyDown(key);
					return;
				}

				default:
				{
					player->KeyDown(key);
					return;
				}
			}  //  END switch(key)
			return;

		}	   //  END case GameState::Running

		case GameState::Paused:
			if (key == 0x50) Pause();
			return;

	}		   //  END switch(State)
}

void Game::KeyUp(WPARAM key)
{
#ifdef _DEBUG
	logger->LogMsg("keyup ", key);
#endif

	if (State == GameState::Running || State == GameState::Paused || State == GameState::GameMenu_quit || State == GameState::GameMenu_resume)
	{
		player->KeyUp(key);
	}
}

void Game::LMBdown(int x, int y)
{
	if (State == GameState::Running && player->CurrentPony == player->Trixie)
	{
		if (levitating) return;
		if (!drawing)
		{
			drawing = true;
			points = new std::vector<PointMagicStar>();
		}
		b2Vec2 pos = Game::GetPosInWorld(x, y);
		PointMagicStar p;
		p.x = x;
		p.y = y;
		p.ActorKey = map->PutMagicStar(Textures, pos);
		points->push_back(p);
	}
}

void Game::MouseMove(int x, int y)
{
	if (State == Game::GameState::Running)
	{
		if (drawing)
		{
			b2Vec2 pos = Game::GetPosInWorld(x, y);
			PointMagicStar p;
			p.x = x;
			p.y = y;
			p.ActorKey = map->PutMagicStar(Textures, pos);
			points->push_back(p);
		}
		else if (levitating)
		{
			levitTargetPoint = Game::GetPosInWorld(x, y);
		}
	}
}

void Game::LMBup(int x, int y)
{
	if ((State == Game::GameState::Running) && drawing)
	{
		drawing = false;
		b2Vec2 pos = Game::GetPosInWorld(x, y);
		PointMagicStar p;
		p.x = x;
		p.y = y;
		p.ActorKey = map->PutMagicStar(Textures, pos);
		points->push_back(p);

		AnalyzePoints();
	}
}

void Game::RMBdown(int x, int y)
{
	if (State == GameState::Running && player->CurrentPony == player->Trixie)
	{
		if (drawing) return;
		if (!player->Trixie->canlevitate) return;
		if (!levitating)
		{
			IsLevitableQueryCallback ilqc = IsLevitableQueryCallback();
			b2Vec2 pos = Game::GetPosInWorld(x, y);
			b2AABB aabb;
			aabb.lowerBound.Set(pos.x - 0.02f, pos.y - 0.02f);
			aabb.upperBound.Set(pos.x + 0.02f, pos.y + 0.02f);
			map->world->QueryAABB(&ilqc, aabb);

			if (ilqc.body)
			{
				levitating = true;
				points = new std::vector<PointMagicStar>();
				levitStarCounter = 0;
				levitBody = ilqc.body;

				// MagicBox
				MagicBox * mb = dynamic_cast<MagicBox *>(levitBody);
				if (mb)
				{
					LevitAura->Reset();
					LevitAura->box = mb;
				}

				// TEST
				levitBody->body->SetGravityScale(0.2f);

				levitTargetPoint = pos;

				// MagicStar
				PointMagicStar p;
				p.ActorKey = map->PutMagicStar(Textures, pos);
				points->push_back(p);
			}
		}
	}
}

void Game::RMBup(int x, int y)
{
	if ((State == Game::GameState::Running) && levitating)
	{
		levitating = false;

		// TEST
		if (levitBody) levitBody->body->SetGravityScale(1.0f);

		levitBody = NULL;
		LevitAura->box = NULL;
		DeletePoints();
	}
}

void Game::AnalyzePoints()
{
	//int count = points->size();
	
	int maxX, maxY, minX, minY;
	maxX = minX = points->at(0).x;
	maxY = minY = points->at(0).y;
	for (std::vector<PointMagicStar>::iterator it = points->begin(); it != points->end(); ++it)
	{
		if ((*it).x > maxX) maxX = (*it).x;   // lepší algoritmus !!
		if ((*it).x < minX) minX = (*it).x;
		if ((*it).y > maxY) maxY = (*it).y;
		if ((*it).y < minY) minY = (*it).y;
	}
	if ((maxX - minX < 200) && (maxY - minY < 200) && (maxX - minX > 50) && (maxY - minY > 50))
	{
		if (player->Trixie->Energy > 50)
		{
			int posx = (maxX + minX) / 2;
			int posy = (maxY + minY) / 2;
			b2Vec2 pos = Game::GetPosInWorld(posx, posy);

			IsBodyQueryCallback ibqc = IsBodyQueryCallback();  // kontrola, jestli tam nìco je
			b2AABB aabb;
			aabb.lowerBound.Set(pos.x - 0.4f, pos.y - 0.4f);
			aabb.upperBound.Set(pos.x + 0.4f, pos.y + 0.4f);
			map->world->QueryAABB(&ibqc, aabb);
			if (ibqc.body)
			{
				// failed
				DeletePoints();
				return;
			}

			if (player->Trixie->BoxCount < player->Trixie->MaxBoxes)
			{
				MagicBox * mb = map->PutBox(Textures, pos);
				player->Trixie->AddBox(mb);
			}
			else
			{
				MagicBox * destr = player->Trixie->RemoveFrontBox();
				map->DeleteActor(destr);
				MagicBox * mb = map->PutBox(Textures, pos);
				player->Trixie->AddBox(mb);
			}
			player->Trixie->Energy -= player->Trixie->boxcost;
		}
		// else failed
	}

	DeletePoints();
}

void Game::DeletePoints()
{
	if (points == NULL) return;
	for (std::vector<PointMagicStar>::iterator it = points->begin(); it != points->end(); ++it)
	{
		std::multimap<int, Actor*>::iterator mit = map->Actors.find((*it).ActorKey);
		if (mit != map->Actors.end())
		{
			Actor * a = (*mit).second;
			delete a;
			map->Actors.erase(mit);
		}
	}
	map->mslayer = 5000;
	delete points;
	points = NULL;
}

void Game::DoPhysics()
{
	// bucking
	if (player->CurrentPony == player->AJ)
	{
		if ((player->sprite == player->dobuckL) && (player->framesdrawn == 0))
		{
			b2Vec2 p1 = player->body->GetPosition();
			b2Vec2 p2(p1.x - 0.6f, p1.y);
			BuckRayCastCallback brc(player);
			map->world->RayCast(&brc, p1, p2);
		}
		else if ((player->sprite == player->dobuckR) && (player->framesdrawn == 0))
		{
			b2Vec2 p1 = player->body->GetPosition();
			b2Vec2 p2(p1.x + 0.6f, p1.y);
			BuckRayCastCallback brc(player);
			map->world->RayCast(&brc, p1, p2);
		}
		// else NIC
	}

	if (levitating)
	{
		if (levitBody == NULL)
		{
			RMBup(0, 0);
			return;
		}

		//b2Vec2 v = levitTargetPoint - levitBody->body->GetWorldPoint(levitLocalPoint);
		b2Vec2 v(levitTargetPoint);
		v -= levitBody->body->GetPosition();
		v.Normalize();
		//v.x *= 150;
		//v.y *= 400;
		v.x *= 100;
		v.y *= 120;
		levitBody->body->ApplyForceToCenter(v);
		++levitStarCounter;

		if (levitStarCounter == 15)
		{
			levitStarCounter = 0;
			PointMagicStar p;
			p.ActorKey = map->PutMagicStar(Textures, levitBody->body->GetPosition());
			points->push_back(p);
		}
	}

	b2Vec2 pvel = player->body->GetLinearVelocity();
	if (pvel.y < -1.0) player->Fall();
	
	if ((player->playerKA->Actual == player->playerKA->JL) || (player->playerKA->Actual == player->playerKA->JR))
	{
		if (pvel.y <= 0.0f)
		{
			IsBodyRayCastCallback ibrccb;
			b2Vec2 p1 = player->body->GetPosition();
			b2Vec2 p2(p1.x, p1.y - 0.6f);
			map->world->RayCast(&ibrccb, p1, p2);
			if (ibrccb.body) player->Land();
		}
	}
	else if ((player->playerKA->Actual == player->playerKA->FL) || (player->playerKA->Actual == player->playerKA->FR))
	{
		if (pvel.y > -0.05f) player->Land();
	}

	Movement m = player->playerKA->Actual->mv;
	b2ContactEdge * contact = player->body->GetContactList();
	while (contact)
	{
		if (!contact->contact->IsTouching())
		{
			contact = contact->next;
			continue;
		}

		// kontrola deathboxù
		Object * o = (Object *)contact->other->GetUserData();
		DeathBox * db = dynamic_cast<DeathBox *>(o);
		if (db)
		{
			if (m == Movement::BuckL || m == Movement::IdleL || m == Movement::JumpL || m == Movement::RunL ||
				m == Movement::WalkL || m == Movement::FallL || m == Movement::FlyL || m == Movement::DashL)
				player->playerKA->Actual = player->playerKA->DL;
			else player->playerKA->Actual = player->playerKA->DR;
			return;
		}
		Mob * mob = dynamic_cast<Mob *>(o);
		if (mob)
		{
			if (m == Movement::BuckL || m == Movement::IdleL || m == Movement::JumpL || m == Movement::RunL ||
				m == Movement::WalkL || m == Movement::FallL || m == Movement::FlyL || m == Movement::DashL)
				player->playerKA->Actual = player->playerKA->DL;
			else player->playerKA->Actual = player->playerKA->DR;
			return;
		}

	//	// kontrola pro Land()
	//	if (pvel.y <= 0.0f)
	//	{
	//		if ((m == Movement::FallL) || (m == Movement::FallR) || (m == Movement::FlyL) || (m == Movement::FlyR) ||
	//			(m == Movement::JumpL) || (m == Movement::JumpR))
	//		{
	//			b2WorldManifold wm;
	//			contact->contact->GetWorldManifold(&wm);
	//			if (contact->contact->GetManifold()->pointCount == 1)
	//			{
	//				b2Vec2 point = player->body->GetLocalPoint(wm.points[0]);
	//				if (point.y > -0.55f && point.y < 0.0f && point.x >= -0.5f && point.x <= 0.5f)
	//					player->Land();
	//			}
	//			else
	//			{
	//				b2Vec2 point1 = player->body->GetLocalPoint(wm.points[0]);
	//				b2Vec2 point2 = player->body->GetLocalPoint(wm.points[1]);
	//				if ((point1.y > -0.55f && point1.y < 0.0f && point1.x >= -0.5f && point1.x <= 0.5f)
	//					|| (point2.y > -0.55f && point2.y < 0.0f && point2.x >= -0.5f && point2.x <= 0.5f))
	//					player->Land();
	//			}
	//			
	//			//if (point.y > -0.55f && point.y < 0.0f && point.x >= -0.5f && point.x <= 0.5f)
	//			//	player->Land();
	//			//else
	//			//{
	//			//	point = contact->other->GetWorldPoint(point);
	//			//	point = player->body->GetLocalPoint(point);
	//			//	if (point.y > -0.55f && point.y < 0.0f && point.x >= -0.5f && point.x <= 0.5f)
	//			//	player->Land();
	//			//}
	//		}
	//	}
		contact = contact->next;
	}
}

void Game::SubtractEnergy()
{
	if (levitating)
	{
		if (player->Trixie->Energy < 5.0f) RMBup(0, 0);
		else player->Trixie->Energy -= player->Trixie->levitatecost;
		return;
	}

	switch (player->playerKA->Actual->mv)
	{
	case Movement::FlyL:
	{
		if (player->RD->Energy < 5.0f) player->playerKA->Actual = player->playerKA->FL;
		else player->RD->Energy -= player->RD->flycost;
		return;
	}
	case Movement::FlyR:
	{
		if (player->RD->Energy < 5.0f) player->playerKA->Actual = player->playerKA->FR;
		else player->RD->Energy -= player->RD->flycost;
		return;
	}
	case Movement::RunL:
	{
		if (player->AJ->Energy < 5.0f) player->playerKA->Actual = player->playerKA->WL;
		else player->AJ->Energy -= player->AJ->runcost;
		return;
	}
	case Movement::RunR:
	{
		if (player->AJ->Energy < 5.0f) player->playerKA->Actual = player->playerKA->WR;
		else player->AJ->Energy -= player->AJ->runcost;
		return;
	}
	default:
		return;
	}
}

void Game::FillEnergy()
{
	if (player->Trixie->Energy < player->Trixie->MaxEnergy)
		player->Trixie->Energy += player->Trixie->FillRate;
	if (player->Trixie->Energy > player->Trixie->MaxEnergy)
		player->Trixie->Energy = player->Trixie->MaxEnergy;

	if (player->RD->Energy < player->RD->MaxEnergy)
		player->RD->Energy += player->RD->FillRate;
	if (player->RD->Energy > player->RD->MaxEnergy)
		player->RD->Energy = player->RD->MaxEnergy;

	if (player->AJ->Energy < player->AJ->MaxEnergy)
		player->AJ->Energy += player->AJ->FillRate;
	if (player->AJ->Energy > player->AJ->MaxEnergy)
		player->AJ->Energy = player->AJ->MaxEnergy;
}

void Game::Pause()
{
	if (State == Game::GameState::Running)
	{
		if (drawing)
		{
			drawing = false;
			DeletePoints();
		}
		if (levitating) RMBup(0, 0);
		State = Game::GameState::Paused;
		return;
	}
	if (State == Game::GameState::Paused)
	{
		State = Game::GameState::Running;
		return;
	}
}

void Game::CheckTriggers()
{
	if (player->playerKA->Actual == player->playerKA->DL || player->playerKA->Actual == player->playerKA->DR) return;

	bool save = false;
	Movement m = player->playerKA->Actual->mv;
	for (std::vector<TriggerArea *>::iterator it = map->Triggers.begin(); it != map->Triggers.end(); it++)
	{
		TriggerArea * ta = (*it);
		if (!ta->enabled) continue;
		b2ContactEdge * ce = ta->body->GetContactList();
		while (ce)
		{
			Object * o = (Object *)ce->other->GetUserData();
			if (o == player)
			{
				ce = NULL;
				switch (ta->type)
				{
				case TriggerType::Death:
					{
						if (m == Movement::BuckL || m == Movement::IdleL || m == Movement::JumpL || m == Movement::RunL ||
							m == Movement::WalkL || m == Movement::FallL || m == Movement::FlyL  || m == Movement::DashL)
							player->playerKA->Actual = player->playerKA->DL;
						else player->playerKA->Actual = player->playerKA->DR;
						return;
					}
				case TriggerType::SavePoint:
					{
						//map->GetSaveState(Savestate); // NE! tahle fce se nesmí volat v cyklu, kterej prochází map::Triggers
						ta->enabled = false;			// protože mùže modifikovat kontejner a pak budou iterátory invalidní
						save = true;
						break;
					}
				case TriggerType::LevelExit:
					{
						State = GameState::NextLevel;
						stateaux_ul = 0x0FFFFFFF;
						stateaux_l = 0;
						return;
					}
				case TriggerType::PlaySoundTrig:
					{
						ta->enabled = false;
						PlaySoundTA * psta = dynamic_cast<PlaySoundTA *>(ta);
						//PlaySound(psta->file, 0, SND_ASYNC | SND_FILENAME | SND_NODEFAULT);
						psta->sound->SetCurrentPosition(0);
						psta->sound->Play(0, 0, 0);
						break;
					}
				case TriggerType::PutZombie:
					{
						ta->enabled = false;
						ta->deleteme = true;
						PutZombieTA * pzta = dynamic_cast<PutZombieTA *>(ta);
						map->PutZombie(Textures, pzta->pos, pzta->bounds.x, pzta->bounds.y, pzta->layer);
						break;
					}
				case TriggerType::DeleteBody:
					{
						ta->enabled = false;
						ta->deleteme = true;
						DeleteBodyTA * dbta = dynamic_cast<DeleteBodyTA *>(ta);
						if (dbta && dbta->todelete) map->DestroyBody(dbta->todelete);
						//dbta->todelete->body = NULL;  zbyteèné, dìlá se v DestroyBody()
						break;
					}
				case TriggerType::EnableBuck:
					{
						PowerUpTA * pu = dynamic_cast<PowerUpTA *>(ta);
						if (pu && pu->text) pu->text->SetVisited(true);
						if (player->AJ) player->AJ->canbuck = true;
						ta->enabled = false;
						ta->deleteme = true;
						break;
					}
				case TriggerType::DecFlyCost:
					{
						PowerUpTA * pu = dynamic_cast<PowerUpTA *>(ta);
						if (pu && pu->text) pu->text->SetVisited(true);
						if (player->RD) player->RD->flycost -= 0.2f;
						ta->enabled = false;
						ta->deleteme = true;
						break;
					}
				case TriggerType::IncMaxBoxes:
					{
						PowerUpTA * pu = dynamic_cast<PowerUpTA *>(ta);
						if (pu && pu->text) pu->text->SetVisited(true);
						if (player->Trixie) player->Trixie->MaxBoxes += 1;
						ta->enabled = false;
						ta->deleteme = true;
						break;
					}
				case TriggerType::EnableLevit:
					{
						PowerUpTA * pu = dynamic_cast<PowerUpTA *>(ta);
						if (pu && pu->text) pu->text->SetVisited(true);
						if (player->Trixie) player->Trixie->canlevitate = true;
						ta->enabled = false;
						ta->deleteme = true;
						break;
					}
				}
			}
			if (ce == NULL) break;
			ce = ce->next;
		}
	}

	if (save) map->GetSaveState(Savestate);  // !
}

void Game::DrawHUD(LPD3DXSPRITE D3DXsprite)
{
	D3DXVECTOR3 vec(50.0f, 10.0f, 0.0f);
	if (map->CanBeAJ)
	{
		D3DXVECTOR3 e(vec);
		e.x += 10.0f;
		e.y += 135.0f;
		if (player->CurrentPony == (Pony *)player->AJ)
		{
			D3DXsprite->Draw(player->AJ->HUDa, NULL, NULL, &vec, 0xFFFFFFFF);
			D3DXsprite->Draw(EBAL, NULL, NULL, &e, 0xFFFFFFFF);
			e.x += 3.0f;
			for (int i = 0; i < player->AJ->Energy; ++i)
			{
				D3DXsprite->Draw(EBAM, NULL, NULL, &e, 0xFFFFFFFF);
				e.x += 1.0f;
			}
			D3DXsprite->Draw(EBAR, NULL, NULL, &e, 0xFFFFFFFF);
		}
		else
		{
			D3DXsprite->Draw(player->AJ->HUDi, NULL, NULL, &vec, 0xFFFFFFFF);
			D3DXsprite->Draw(EBIL, NULL, NULL, &e, 0xFFFFFFFF);
			e.x += 3.0f;
			for (int i = 0; i < player->AJ->Energy; ++i)
			{
				D3DXsprite->Draw(EBIM, NULL, NULL, &e, 0xFFFFFFFF);
				e.x += 1.0f;
			}
			D3DXsprite->Draw(EBIR, NULL, NULL, &e, 0xFFFFFFFF);
		}
		vec.x += 130.0f;
	}
	if (map->CanBeRD)
	{
		D3DXVECTOR3 e(vec);
		e.x += 10.0f;
		e.y += 135.0f;
		if (player->CurrentPony == (Pony *)player->RD)
		{
			D3DXsprite->Draw(player->RD->HUDa, NULL, NULL, &vec, 0xFFFFFFFF);
			D3DXsprite->Draw(EBAL, NULL, NULL, &e, 0xFFFFFFFF);
			e.x += 3.0f;
			for (int i = 0; i < player->RD->Energy; ++i)
			{
				D3DXsprite->Draw(EBAM, NULL, NULL, &e, 0xFFFFFFFF);
				e.x += 1.0f;
			}
			D3DXsprite->Draw(EBAR, NULL, NULL, &e, 0xFFFFFFFF);
		}
		else
		{
			D3DXsprite->Draw(player->RD->HUDi, NULL, NULL, &vec, 0xFFFFFFFF);
			D3DXsprite->Draw(EBIL, NULL, NULL, &e, 0xFFFFFFFF);
			e.x += 3.0f;
			for (int i = 0; i < player->RD->Energy; ++i)
			{
				D3DXsprite->Draw(EBIM, NULL, NULL, &e, 0xFFFFFFFF);
				e.x += 1.0f;
			}
			D3DXsprite->Draw(EBIR, NULL, NULL, &e, 0xFFFFFFFF);
		}
		vec.x += 130.0f;
	}
	if (map->CanBeTrixie)
	{
		D3DXVECTOR3 e(vec);
		e.x += 10.0f;
		e.y += 135.0f;
		if (player->CurrentPony == (Pony *)player->Trixie)
		{
			D3DXsprite->Draw(player->Trixie->HUDa, NULL, NULL, &vec, 0xFFFFFFFF);
			D3DXsprite->Draw(EBAL, NULL, NULL, &e, 0xFFFFFFFF);
			e.x += 3.0f;
			for (int i = 0; i < player->Trixie->Energy; ++i)
			{
				D3DXsprite->Draw(EBAM, NULL, NULL, &e, 0xFFFFFFFF);
				e.x += 1.0f;
			}
			D3DXsprite->Draw(EBAR, NULL, NULL, &e, 0xFFFFFFFF);
		}
		else
		{
			D3DXsprite->Draw(player->Trixie->HUDi, NULL, NULL, &vec, 0xFFFFFFFF);
			D3DXsprite->Draw(EBIL, NULL, NULL, &e, 0xFFFFFFFF);
			e.x += 3.0f;
			for (int i = 0; i < player->Trixie->Energy; ++i)
			{
				D3DXsprite->Draw(EBIM, NULL, NULL, &e, 0xFFFFFFFF);
				e.x += 1.0f;
			}
			D3DXsprite->Draw(EBIR, NULL, NULL, &e, 0xFFFFFFFF);
		}
		vec.x += 130.0f;
	}
}

unsigned int ReadUINT(std::ifstream * r)
{
	unsigned char c;
	unsigned int res = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (r->peek() == -1) throw std::exception();
		res = res << 8;
		(*r) >> c;
		res += c;
	}
	return res;
}

void WriteUINT(std::ofstream * w, unsigned int i)
{
	for (int j = 3; j >= 0; --j)
	{
		unsigned char c = (unsigned char)(i >> (j * 8));
		(*w) << c;
	}
}

float ReadFloat(std::ifstream * r)
{
	union
	{
		float f;
		struct
		{
			unsigned char b1;
			unsigned char b2;
			unsigned char b3;
			unsigned char b4;
		} b;
	} convert;
	unsigned char c;
	if (r->peek() == -1) throw std::exception();
	(*r) >> c;
	convert.b.b4 = c;
	if (r->peek() == -1) throw std::exception();
	(*r) >> c;
	convert.b.b3 = c;
	if (r->peek() == -1) throw std::exception();
	(*r) >> c;
	convert.b.b2 = c;
	if (r->peek() == -1) throw std::exception();
	(*r) >> c;
	convert.b.b1 = c;

	return convert.f;
}

void WriteFloat(std::ofstream * w, float f)
{
	union
	{
		float f;
		struct
		{
			unsigned char b1;
			unsigned char b2;
			unsigned char b3;
			unsigned char b4;
		} b;
	} convert;
	convert.f = f;
	(*w) << convert.b.b4;
	(*w) << convert.b.b3;
	(*w) << convert.b.b2;
	(*w) << convert.b.b1;
}

void PushUINT(std::vector<unsigned char> * v, unsigned int i)
{
	union
	{
		unsigned int ui;
		struct
		{
			unsigned char b1;
			unsigned char b2;
			unsigned char b3;
			unsigned char b4;
		} b;
	} convert;
	convert.ui = i;
	v->push_back(convert.b.b4);
	v->push_back(convert.b.b3);
	v->push_back(convert.b.b2);
	v->push_back(convert.b.b1);
}

void PushFloat(std::vector<unsigned char> * v, float f)
{
	union
	{
		float f;
		struct
		{
			unsigned char b1;
			unsigned char b2;
			unsigned char b3;
			unsigned char b4;
		} b;
	} convert;
	convert.f = f;
	v->push_back(convert.b.b4);
	v->push_back(convert.b.b3);
	v->push_back(convert.b.b2);
	v->push_back(convert.b.b1);
}

bool Game::LoadSavedSkills(SaveState * savestate, int level)
{
	std::ifstream r;
	try
	{
		r.open("data\\data.sav", std::ios::binary);
		if (!r.is_open()) throw std::exception();
		if (r.peek() == -1)
		{
			r.close();
			throw std::exception();
		}
	}
	catch (...)
	{ return false; }

	try
	{
		r >> std::noskipws;
		unsigned char c;
		r >> c;
		--level;
		while (level)
		{
			for (int i = 0; i < 32; ++i)
			{
				if (r.peek() == -1) throw std::exception();
				r >> c;
			}
			--level;
		}

		savestate->runcost = ReadFloat(&r);
		savestate->runspeed = ReadFloat(&r);
		if (r.peek() == -1) throw std::exception();
		r >> c;
		savestate->canbuck = (bool)c;

		savestate->flycost = ReadFloat(&r);
		savestate->flyspeed = ReadFloat(&r);
		if (r.peek() == -1) throw std::exception();
		r >> c;
		savestate->candash = (bool)c;

		savestate->boxcost = ReadFloat(&r);
		savestate->maxboxes = ReadUINT(&r);
		savestate->levitcost = ReadFloat(&r);
		if (r.peek() == -1) throw std::exception();
		r >> c;
		savestate->canlevitate = (bool)c;
		r.close();
	}
	catch (...)
	{
		if (r.is_open()) r.close();
		return false;
	}

	return true;
}

bool Game::SaveSkills(SaveState * savestate, int level)
{
	std::ifstream r;
	try
	{
		r.open("data\\data.sav", std::ios::binary);
		if ((!r.is_open()) || (r.peek() == -1))
		{
			if (level == 1)
			{
				r.close();
				std::ofstream w;
				w.open("data\\data.sav", std::ios::binary);
				if (!w.is_open()) throw std::exception();
				w << (unsigned char)1;
				WriteSkills(&w, savestate);
				w.close();
				return true;
			}
			else throw std::exception();
		}

		r >> std::noskipws;
		unsigned char c;
		r >> c;  // nejvyšší odemèenej level
		if (level > c + 1) throw std::exception();
		if (c == level - 1)
		{
			std::vector<unsigned char> data;
			while (r.peek() != -1)
			{
				r >> c;
				data.push_back(c);
			}
			r.close();
			std::ofstream w;
			w.open("data\\data.sav", std::ios::binary | std::ios::trunc);
			if (!w.is_open()) throw std::exception();
			w << (unsigned char)level;
			for (std::vector<unsigned char>::iterator it = data.begin(); it != data.end(); it++)
			{
				w << (*it);
			}
			w << (unsigned char)0;
			WriteSkills(&w, savestate);
			w.close();
			return true;
		}
		else
		{
			int maxlevel = c;
			std::vector<unsigned char> data;

			int currentlevel = 1;
			while (currentlevel <= maxlevel)
			{
				if (currentlevel == level) // pøeèíst, rozhodnout, výsledek nacpat do data
				{
					float rc = ReadFloat(&r);  // má to rozhodování vùbec smysl ??
					float rs = ReadFloat(&r);
					if (r.peek() == -1) throw std::exception();
					unsigned char cb;
					r >> cb;

					float fc = ReadFloat(&r);
					float fs = ReadFloat(&r);
					if (r.peek() == -1) throw std::exception();
					unsigned char cd;
					r >> cd;

					float bc = ReadFloat(&r);
					int mb = ReadUINT(&r);
					float lc = ReadFloat(&r);
					if (r.peek() == -1) throw std::exception();
					unsigned char cl;
					r >> cl;

					char balance = 0;  // balance ve prospìch savestate
					if (rc > savestate->runcost) ++balance;
					else --balance;
					if (rs < savestate->runspeed) ++balance;
					else --balance;
					if (!cb && savestate->canbuck) ++balance;
					if (cb && !savestate->canbuck) --balance;
					if (fc > savestate->flycost) ++balance;
					else --balance;
					if (fs < savestate->flyspeed) ++balance;
					else --balance;
					if (!cd && savestate->candash) ++balance;
					if (cd && !savestate->candash) --balance;
					if (bc > savestate->boxcost) ++balance;
					else --balance;
					if (mb < savestate->maxboxes) ++balance;
					else --balance;
					if (lc > savestate->levitcost) ++balance;
					else --balance;
					if (!cl && savestate->canlevitate) ++balance;
					if (cl && !savestate->canlevitate) --balance;

					if (balance > 0)
					{
						// savestate -> data
						PushFloat(&data, savestate->runcost);
						PushFloat(&data, savestate->runspeed);
						data.push_back((unsigned char)savestate->canbuck);
						PushFloat(&data, savestate->flycost);
						PushFloat(&data, savestate->flyspeed);
						data.push_back((unsigned char)savestate->candash);
						PushFloat(&data, savestate->boxcost);
						PushUINT(&data, savestate->maxboxes);
						PushFloat(&data, savestate->levitcost);
						data.push_back((unsigned char)savestate->canlevitate);
					}
					else
					{
						// lok. promìnné -> data
						PushFloat(&data, rc);
						PushFloat(&data, rs);
						data.push_back(cb);
						PushFloat(&data, fc);
						PushFloat(&data, fs);
						data.push_back(cd);
						PushFloat(&data, bc);
						PushUINT(&data, mb);
						PushFloat(&data, lc);
						data.push_back(cl);
					}
					if (r.peek() == 0)
					{
						r >> c;
						data.push_back(0);
					}
				}
				else
				{
					for (int i = 0; i < 31; ++i)
					{
						if (r.peek() == -1) throw std::exception();
						r >> c;
						data.push_back(c);
					}
					if (currentlevel < maxlevel)  // je tam ukonèovací nula
					{
						if (r.peek() == -1) throw std::exception();
						r >> c;
						data.push_back(c);
					}
				}
				++currentlevel;
			}

			r.close();
			std::ofstream w;
			w.open("data\\data.sav", std::ios::binary | std::ios::trunc);
			if (!w.is_open()) throw std::exception();
			w << (unsigned char)maxlevel;
			for (std::vector<unsigned char>::iterator it = data.begin(); it != data.end(); it++)
			{
				w << (*it);
			}
			w.close();
			return true;
		}
	}
	catch (...)
	{
		if (r.is_open()) r.close();
		return false;
	}

	return false;  // tohle by mìlo bejt zbyteèný
}

void Game::WriteSkills(std::ofstream * w, SaveState * savestate)
{
	WriteFloat(w, savestate->runcost);
	WriteFloat(w, savestate->runspeed);
	(*w) << (unsigned char)(savestate->canbuck);
	WriteFloat(w, savestate->flycost);
	WriteFloat(w, savestate->flyspeed);
	(*w) << (unsigned char)(savestate->candash);
	WriteFloat(w, savestate->boxcost);
	WriteUINT(w, savestate->maxboxes);
	WriteFloat(w, savestate->levitcost);
	(*w) << (unsigned char)(savestate->canlevitate);
}

void Game::TruncSaveFile()
{
	std::ofstream tr;
	tr.open("data\\data.sav", std::ios::trunc);
	tr.close();
}

// must be called before device::Reset()
void Game::ReleaseTextures()
{
	if (Textures) Textures->ReleaseTextures(true);
}

void Game::ReloadTextures()
{
	Textures->ReloadTextures();
	Black = Textures->GetTexture(TextureStorage::TexName::Black);
	White = Textures->GetTexture(TextureStorage::TexName::White);
	EBAL = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Active_L);
	EBAM = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Active_M);
	EBAR = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Active_R);
	EBIL = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Inactive_L);
	EBIM = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Inactive_M);
	EBIR = Textures->GetTexture(TextureStorage::TexName::EnergyBar_Inactive_R);

	MainMenu_ng = Textures->GetTexture(TextureStorage::TexName::MainMenu_newgame);
	MainMenu_l = Textures->LoadTexture(TextureStorage::TexName::MainMenu_load);
	MainMenu_q = Textures->GetTexture(TextureStorage::TexName::MainMenu_quit);
	LoadMenu_n = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_none);
	LoadMenu_11 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_1_1);
	LoadMenu_21 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_2_1);
	LoadMenu_22 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_2_2);
	LoadMenu_31 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_3_1);
	LoadMenu_32 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_3_2);
	LoadMenu_33 = Textures->LoadTexture(TextureStorage::TexName::LoadMenu_3_3);
	GameMenu_r = Textures->LoadTexture(TextureStorage::TexName::GameMenu_resume);
	GameMenu_q = Textures->LoadTexture(TextureStorage::TexName::GameMenu_quit);

	if (map) map->ResetTextures(Textures);
	if (LevitAura) LevitAura->GetTextures(Textures);
	if (vfx) vfx->GetTextures(Textures);
}

D3DXVECTOR3 Game::GetPosOnScreen(b2Vec2 v)
{
	v.x = v.x - PositionX;
	v.y = PositionY - v.y;
	v.x *= 100;
	v.y *= 100;
	return D3DXVECTOR3(v.x, v.y, 0.0f);
}

D3DXVECTOR3 Game::GetPosOnScreen(Object * o)
{
	b2Vec2 pos = o->body->GetPosition();
	pos.x = pos.x - PositionX;
	pos.y = PositionY - pos.y;
	pos.x *= 100;
	pos.y *= 100;
	return D3DXVECTOR3(pos.x, pos.y, 0.0f);
}

D3DXVECTOR3 Game::GetPosOnScreen(StaticDecor * sd)
{
	b2Vec2 pos = sd->position;
	pos.x = pos.x - PositionX;
	pos.y = PositionY - pos.y;
	pos.x *= 100;
	pos.y *= 100;
	return D3DXVECTOR3(pos.x, pos.y, 0.0f);
}

D3DXVECTOR3 Game::GetPosOnScreen(ParallaxDecor * pd)
{
	b2Vec2 playerpos = player->body->GetPosition();
	b2Vec2 pos = pd->startpos;
	//pos.x += (PositionX - pos.x) * pd->coefX;
	//pos.y += (PositionY - pos.y) * pd->coefY;
	pos.x += (playerpos.x - pos.x) * pd->coefX;
	pos.y += (playerpos.y - pos.y) * pd->coefY;

	pos.x = pos.x - PositionX;  // mìlo by to spíš záležet na pozici playera
	pos.y = PositionY - pos.y;

	pos.x *= 100;
	pos.y *= 100;
	return D3DXVECTOR3(pos.x, pos.y, 0.0f);
}

b2Vec2 Game::GetPosInWorld(int x, int y)
{
	b2Vec2 pos;
	pos.x = PositionX + (float)x / 100.0f;
	pos.y = PositionY - (float)y / 100.0f;
	return pos;
}

bool Game::ShouldIDraw(Object * o)
{
	D3DXVECTOR3 vec = GetPosOnScreen(o);
	float halfdiag = sqrt((float)((o->height * o->height) + (o->width * o->width)));
	halfdiag /= 2.0f;
	if ((vec.x + halfdiag >= 0) && (vec.x - halfdiag < Game::ScreenWidth) && (vec.y + halfdiag >= 0) && (vec.y - halfdiag < Game::ScreenHeight))
		return true;

	return false;
}

bool Game::ShouldIDraw(StaticDecor * sd)
{
	D3DXVECTOR3 vec = Game::GetPosOnScreen(sd);
	if ((vec.x + sd->width >= 0) && (vec.x < Game::ScreenWidth) && (vec.y + sd->height >= 0) && (vec.y < Game::ScreenHeight))
		return true;

	return false;
}

bool Game::ShouldIDraw(ParallaxDecor * pd)
{
	D3DXVECTOR3 vec = GetPosOnScreen(pd);
	//float halfdiag = sqrt((float)((pd->height * pd->height) + (pd->width * pd->width)));  // halfdiag? bude se otáèet??
	//halfdiag /= 2.0f;
	//if ((vec.x + halfdiag >= 0) && (vec.x - halfdiag < Game::ScreenWidth) && (vec.y + halfdiag >= 0) && (vec.y - halfdiag < Game::ScreenHeight))
	//	return true;

	if ((vec.x + pd->width >= 0) && (vec.x < Game::ScreenWidth) && (vec.y + pd->height >= 0) && (vec.y < Game::ScreenHeight))
		return true;

	return false;
}

bool Game::ShouldIDraw(ActorTA * ata)
{
	D3DXVECTOR3 vec = GetPosOnScreen(ata->actorpos);
	if ((vec.x + ata->width >= 0) && (vec.x < Game::ScreenWidth) && (vec.y + ata->height >= 0) && (vec.y < Game::ScreenHeight))
		return true;

	return false;
}

Game::~Game()
{
	delete Savestate;
	if (points) delete points;
	delete Textures;
	delete Sounds;
	delete vfx;
	delete LevitAura;
	//if (map) delete map;  NE! ~Game() nemaže mapu!
	if (player) delete player;
}