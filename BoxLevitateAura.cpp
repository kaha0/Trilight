#include<BoxLevitateAura.h>
#include<Game.h>

BoxLevitateAura::BoxLevitateAura(TextureStorage * ts)
{
	fps = 3;
	framesdrawn = 0;
	width = height = 150;

	imgs = new RoundList();
	LPDIRECT3DTEXTURE9 tex;
	tex = ts->GetTexture(TextureStorage::BoxLevitate_01);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_02);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_03);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_04);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_05);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_06);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_07);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_08);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_09);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_10);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::BoxLevitate_11);
	imgs->Add(new Sprite(tex, false));

	sprite = imgs->First;
}

void BoxLevitateAura::GetTextures(TextureStorage * ts)
{
	Sprite * aux = imgs->First;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::BoxLevitate_11);
}

void BoxLevitateAura::NextSprite()
{
	sprite = sprite->next;
}

void BoxLevitateAura::Reset()
{
	framesdrawn = 0;
	sprite = imgs->First;
}

bool BoxLevitateAura::ShouldIDraw()
{
	if (box && box->body)
	{
		D3DXVECTOR3 vec = Game::GetPosOnScreen(box);
		float halfdiag = sqrt((float)((height * height) + (width * width)));
		halfdiag /= 2.0f;
		if ((vec.x + halfdiag >= 0) && (vec.x - halfdiag < Game::ScreenWidth) && (vec.y + halfdiag >= 0) && (vec.y - halfdiag < Game::ScreenHeight))
			return true;

		return false;
	}
	else return false;
}

void BoxLevitateAura::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (ShouldIDraw())
	{
		float angle = -1.0f * box->body->GetAngle();
		D3DXVECTOR3 coord = Game::GetPosOnScreen(box);
		coord.x -= (float)width / 2.0f;
		coord.y -= (float)height / 2.0f;
		D3DXVECTOR2 spriteCenter = D3DXVECTOR2((float)width / 2.0f, (float)height / 2.0f);
		D3DXVECTOR2 trans(coord.x, coord.y);
		D3DXMATRIX mat;
		D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, &spriteCenter, angle, &trans);
		D3DXsprite->SetTransform(&mat);
		D3DXsprite->Draw(sprite->img, NULL, NULL, NULL, 0xFFFFFFFF);

		D3DXMatrixTransformation2D(&mat, NULL, 0.0f, NULL, NULL, 0.0f, NULL);
		D3DXsprite->SetTransform(&mat);
	}
	else return;
}

BoxLevitateAura::~BoxLevitateAura()
{
	delete imgs;
}