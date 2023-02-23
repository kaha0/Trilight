#pragma warning( disable : 4482 )

#include<AJPony.h>

AJPony::AJPony(TextureStorage * ts)
{
	Energy = 100.0f;
	MaxEnergy = 100.0f;
	FillRate = 0.5f;
	runcost = 1.0f;  // skills by se nemìly nastavovat v konstruktoru

	HUDa = ts->GetTexture(TextureStorage::TexName::AJ_HUD_active);
	HUDi = ts->GetTexture(TextureStorage::TexName::AJ_HUD_inactive);

	LPDIRECT3DTEXTURE9 ptex;

	IdleL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_idle_left);
	IdleL->Add(new Sprite(ptex, true));

	IdleR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_idle_right);
	IdleR->Add(new Sprite(ptex, true));

	WalkL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_01);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_02);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_03);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_04);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_05);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_06);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_07);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_08);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_09);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_10);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_11);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_12);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_13);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_14);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_15);
	WalkL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_16);
	WalkL->Add(new Sprite(ptex, true));

	WalkR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_01);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_02);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_03);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_04);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_05);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_06);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_07);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_08);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_09);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_10);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_11);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_12);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_13);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_14);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_15);
	WalkR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_16);
	WalkR->Add(new Sprite(ptex, true));

	RunL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_01);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_02);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_03);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_04);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_05);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_06);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_07);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_08);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_09);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_10);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_11);
	RunL->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_left_12);
	RunL->Add(new Sprite(ptex, true));

	RunR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_01);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_02);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_03);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_04);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_05);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_06);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_07);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_08);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_09);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_10);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_11);
	RunR->Add(new Sprite(ptex, true));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_run_right_12);
	RunR->Add(new Sprite(ptex, true));

	JumpL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_11);
	JumpL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_12);
	JumpL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_13);
	JumpL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_14);
	JumpL->Add(new Sprite(ptex, true));

	JumpR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_11);
	JumpR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_12);
	JumpR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_13);
	JumpR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_14);
	JumpR->Add(new Sprite(ptex, true));

	FallL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_14);
	FallL->Add(new Sprite(ptex, true));

	FallR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_14);
	FallR->Add(new Sprite(ptex, true));

	BuckL = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_1);
	BuckL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_2);
	BuckL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_3);
	BuckL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_4);
	BuckL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_5);
	BuckL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_6);
	BuckL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_7);
	BuckL->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_8);
	BuckL->Add(new Sprite(ptex, true));

	BuckR = new RoundList();
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_1);
	BuckR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_2);
	BuckR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_3);
	BuckR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_4);
	BuckR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_5);
	BuckR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_6);
	BuckR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_7);
	BuckR->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_8);
	BuckR->Add(new Sprite(ptex, true));
}

void AJPony::GetTextures(TextureStorage * ts)
{
	HUDa = ts->GetTexture(TextureStorage::TexName::AJ_HUD_active);
	HUDi = ts->GetTexture(TextureStorage::TexName::AJ_HUD_inactive);

	Sprite * aux;

	//if ((IdleL) && (IdleL->count == 1))
	IdleL->First->img = ts->GetTexture(TextureStorage::TexName::AJ_idle_left);
	// else throw exception();

	IdleR->First->img = ts->GetTexture(TextureStorage::TexName::AJ_idle_right);

	aux = WalkL->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_14);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_15);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_16);

	aux = WalkR->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_14);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_15);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_16);

	aux = RunL->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_left_12);

	aux = RunR->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_run_right_12);

	aux = JumpL->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_14);

	aux = JumpR->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_14);
	aux = aux->next;

	FallL->First->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_left_14);

	FallR->First->img = ts->GetTexture(TextureStorage::TexName::AJ_walk_right_14);

	aux = BuckL->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_1);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_2);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_3);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_4);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_5);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_6);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_7);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_left_8);

	aux = BuckR->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_1);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_2);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_3);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_4);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_5);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_6);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_7);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::AJ_buck_right_8);
}