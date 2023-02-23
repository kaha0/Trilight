#pragma warning( disable : 4482 )

#include<TrixiePony.h>

TrixiePony::TrixiePony(TextureStorage * ts)
{
	Energy = 100.0f;
	MaxEnergy = 100.0f;
	FillRate = 0.5f;
	BoxCount = 0;
	Boxes = new std::queue<MagicBox *>();
	MaxBoxes = 3;  // skills by se nem�ly nastavovat v konstruktoru
	boxcost = 50.0f;
	levitatecost = 1.0f;
	canlevitate = true;

	HUDa = ts->GetTexture(TextureStorage::TexName::Trixie_HUD_active);
	HUDi = ts->GetTexture(TextureStorage::TexName::Trixie_HUD_inactive);

	LPDIRECT3DTEXTURE9 ptex;

	IdleL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_idle_left);
	IdleL->Add(new Sprite(ptex, true));

	IdleR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_idle_right);
	IdleR->Add(new Sprite(ptex, true));

	WalkL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_01);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_02);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_03);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_04);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_05);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_06);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_07);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_08);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_09);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_10);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_11);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_12);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_13);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_14);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_15);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_16);
	WalkL->Add(new Sprite(ptex, true));

	WalkR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_01);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_02);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_03);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_04);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_05);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_06);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_07);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_08);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_09);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_10);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_11);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_12);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_13);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_14);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_15);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_16);
	WalkR->Add(new Sprite(ptex, true));

	JumpL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_11);
	JumpL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_12);
	JumpL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_13);
	JumpL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_14);
	JumpL->Add(new Sprite(ptex, true));

	JumpR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_11);
	JumpR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_12);
	JumpR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_13);
	JumpR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_14);
	JumpR->Add(new Sprite(ptex, true));

	FallL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_14);
	FallL->Add(new Sprite(ptex, true));

	FallR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_14);
	FallR->Add(new Sprite(ptex, true));
}

void TrixiePony::GetTextures(TextureStorage * ts)
{
	HUDa = ts->GetTexture(TextureStorage::TexName::Trixie_HUD_active);
	HUDi = ts->GetTexture(TextureStorage::TexName::Trixie_HUD_inactive);

	Sprite * aux;

	IdleL->First->img = ts->GetTexture(TextureStorage::TexName::Trixie_idle_left);

	IdleR->First->img = ts->GetTexture(TextureStorage::TexName::Trixie_idle_right);

	aux = WalkL->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_14);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_15);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_16);

	aux = WalkR->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_14);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_15);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_16);

	aux = JumpL->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_14);

	aux = JumpR->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_14);

	FallL->First->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_left_14);

	FallR->First->img = ts->GetTexture(TextureStorage::TexName::Trixie_walk_right_14);
}

void TrixiePony::AddBox(MagicBox * mb)  // pouze p�id�v� box, pokud je jich moc, mus� se p�edt�m n�jakej box odstranit ru�n�
{
	//if (BoxCount == MaxBoxes) throw exception();
	Boxes->push(mb);
	++BoxCount;
}

void TrixiePony::RemoveBox(MagicBox * mb)
{
	std::queue<MagicBox *> aux;
	while (!Boxes->empty())
	{
		MagicBox * p = Boxes->front();
		Boxes->pop();
		if (p == mb)
		{
			--BoxCount;
			continue;
		}
		aux.push(p);
	}

	while (!aux.empty())
	{
		MagicBox * p = aux.front();
		aux.pop();
		Boxes->push(p);
	}
}

MagicBox * TrixiePony::RemoveFrontBox()
{
	MagicBox * p = Boxes->front();
	Boxes->pop();
	--BoxCount;
	return p;
}