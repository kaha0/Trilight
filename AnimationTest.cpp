#ifdef _DEBUG

#include<AnimationTest.h>
#include<Game.h>

AnimationTest::AnimationTest(LPDIRECT3DDEVICE9 device)
{
	fps = 6;
	framesdrawn = 0;

	width = 300;
	height = 300;

	sprites = new RoundList();
	LPDIRECT3DTEXTURE9 tex;

	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl1.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl2.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl3.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl4.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl5.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl6.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl7.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl8.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl9.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl10.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));
	D3DXCreateTextureFromFileEx(device, "G:\\t\\dev\\bl11.png", width, height, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, NULL, NULL, &tex);
	sprites->Add(new Sprite(tex, false));

	sprite = sprites->First;
}

void AnimationTest::NextSprite()
{
	if (sprite) sprite = sprite->next;
}

void AnimationTest::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}

#endif