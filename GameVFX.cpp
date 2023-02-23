#include<Game.h>
#include<GameVFX.h>

GameVFX::GameVFX(TextureStorage * ts)
{
	if ((Game::ScreenWidth == 1280) && (Game::ScreenHeight == 960))
	{
		offset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}
	else if ((Game::ScreenWidth == 1280) && (Game::ScreenHeight == 800))
	{
		offset = D3DXVECTOR3(0.0f, -80.0f, 0.0f);
	}
	else if ((Game::ScreenWidth == 1280) && (Game::ScreenHeight == 720))
	{
		offset = D3DXVECTOR3(0.0f, -120.0f, 0.0f);
	}
	else if ((Game::ScreenWidth == 1024) && (Game::ScreenHeight == 768))
	{
		offset = D3DXVECTOR3(-128.0f, -96.0f, 0.0f);
	}
	//else throw exception, neni potøeba
	
	fps = 10;
	framesdrawn = 0;

	imgs = new RoundList();
	LPDIRECT3DTEXTURE9 ptex;
	ptex = ts->GetTexture(TextureStorage::TexName::VFX1);
	imgs->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::VFX2);
	imgs->Add(new Sprite(ptex, false));
	ptex = ts->GetTexture(TextureStorage::TexName::VFX3);
	imgs->Add(new Sprite(ptex, false));
	current = imgs->First;
}

void GameVFX::GetTextures(TextureStorage * ts)
{
	Sprite * aux = imgs->First;
	aux->img = ts->GetTexture(TextureStorage::TexName::VFX1);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::VFX2);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::TexName::VFX3);
}

void GameVFX::Draw(LPD3DXSPRITE D3DXsprite)
{
	D3DXsprite->Draw(current->img, NULL, NULL, &offset, 0xFFFFFFFF);
}

void GameVFX::NextSprite()
{
	if (current) current = current->next;
}

GameVFX::~GameVFX()
{
	delete imgs;
}