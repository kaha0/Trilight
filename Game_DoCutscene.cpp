#include<Game.h>

#include<Moon.h>
#include<SleepBubble.h>

void Game::DoCutscene(LPD3DXSPRITE sprite)
{
	switch (stateaux_l)
	{
	case 1:
		{
			if (stateaux_ul < 300)  // tohle pak udìlat delší
			{
				D3DXVECTOR3 ppos = GetPosOnScreen(player);
				if (ppos.y > ScreenHeight - 200) PositionY -= 0.02f;

				DrawActors(sprite);
				DrawVFX(sprite);
				++stateaux_ul;
				return;
			}

			if (stateaux_ul < 330)
			{
				// red flash
				if (stateaux_ul == 300)
				{
					std::multimap<int, Actor *>::iterator it = map->Actors.find(-53);
					while (it != map->Actors.end())
					{
						SleepBubble * sb = dynamic_cast<SleepBubble *>(it->second);
						if (sb)
						{
							delete sb;
							map->Actors.erase(it);
							// uvolnit textury SleepBubble_01 - SleepBubble_16 v Textures ?
							break;
						}
						it++;
					}
				}
				sprite->Draw(White, NULL, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0xFFFF0000);
				DrawVFX(sprite); // ?
				++stateaux_ul;
				return;
			}

			if (stateaux_ul < 360)
			{
				// red fade out
				if (stateaux_ul == 330) player->body->SetGravityScale(0.2f);
				if (stateaux_ul > 340) map->Step();
				DrawActors(sprite);
				unsigned long aux = (359 - stateaux_ul) << 27;
				sprite->Draw(White, NULL, NULL, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), aux | 0x00FF0000);  // <-- !!
				DrawVFX(sprite);
				++stateaux_ul;
				return;
			}

			if (stateaux_ul < 870)
			{
				map->Step();
				b2Vec2 pv = player->body->GetLinearVelocity();
				if (pv.y > 0.5f)
				{
					player->body->SetLinearVelocity(b2Vec2(pv.x, 0.5f));  // aby player nepadal moc rychle
					player->body->SetGravityScale(0.0f);
				}
				if (pv.y > 1.0f) player->body->SetLinearVelocity(b2Vec2(pv.x, 1.0f));
				
				DoPhysics();
				MoveScreen();

				DrawActors(sprite);
				DrawVFX(sprite);
				++stateaux_ul;
				return;
			}

			if (stateaux_ul == 870)
			{
				State = GameState::Running;
				player->body->SetGravityScale(1.0f);
				std::multimap<int, Actor *>::iterator it = map->Actors.find(-80);
				while (it != map->Actors.end())
				{
					Moon * moon = dynamic_cast<Moon *>(it->second);
					if (moon)
					{
						moon->coefY = 0.0f;
						moon->startpos = b2Vec2(3.0f, 12.0f);
						break;
					}
					it++;
				}
				map->Step();
				DoPhysics();
				CheckTriggers();

				MoveScreen();
				SubtractEnergy();
				FillEnergy();

				DrawActors(sprite);
				DrawVFX(sprite);
				DrawHUD(sprite);
				return;
			}
		}  // END stateaux_l == 1
	}  // END switch (stateaux_l)
}