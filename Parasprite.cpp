#include<Parasprite.h>
#include<Game.h>

Parasprite::Parasprite(TextureStorage * ts, b2Vec2 pos, float xbound, float ybound, b2Vec2 awaypos)
{
	fps = 3;
	framesdrawn = 0;
	anchor = pos;
	position = pos;
	awayanchor = awaypos;
	flyaway = false;
	Xbound = xbound;
	Ybound = ybound;
	body = NULL;
	reconstruct = true;
	SetWidthHeight();

	LPDIRECT3DTEXTURE9 tex;
	imgs = new RoundList();
	tex = ts->GetTexture(TextureStorage::Parasprite1);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Parasprite2);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Parasprite3);
	imgs->Add(new Sprite(tex, false));
	tex = ts->GetTexture(TextureStorage::Parasprite2);
	imgs->Add(new Sprite(tex, false));
	sprite = imgs->First;
}

void Parasprite::GetTextures(TextureStorage * ts)
{
	Sprite * aux = imgs->First;
	aux->img = ts->GetTexture(TextureStorage::Parasprite1);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Parasprite2);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Parasprite3);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Parasprite2);
}

void Parasprite::NextSprite()
{
	if (sprite) sprite = sprite->next;
}

void Parasprite::ConstructBody(b2World *, b2Vec2)
{
	// nic se ve skuteènosti nerekonstruuje
	// jen nastavíme zpátky position a flyaway
	position = anchor;
	flyaway = false;
}

void Parasprite::SetWidthHeight()
{
	width = 40;
	height = 35;
}

void Parasprite::Draw(LPD3DXSPRITE D3DXsprite)
{
	D3DXVECTOR3 vec = Game::GetPosOnScreen(position);
	vec.x -= 20.0f;
	vec.y -= 17.5f;
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}

// vrácená hodnota je prvkem [0,1]
float RandFloat()
{
	return ((float)rand() / (float)RAND_MAX);
}

void Parasprite::Step()
{
	// lítat okolo position v mezích Xbound a Ybound
	// check distance from player
	// if (distance < lambda) nastavit position nìkam pryè
	//		- resetting to savepoint - jak se parasprite nastaví zpátky?
	//			-dát mu b2Body?
	//			-FakeObject?

	if (Game::player && Game::player->body)
	{
		float dist = (Game::player->body->GetPosition() - position).Length();
		if (dist < 1.0f) flyaway = true;
	}

	float dx = 0.0f;
	float dy = 0.0f;
	if (flyaway)
	{
		dx = position.x - awayanchor.x;
		dy = position.y - awayanchor.y;
	}
	else
	{
		dx = position.x - anchor.x;
		dy = position.y - anchor.y;
	}

	if (dx > Xbound / 2.0f)
	{
		// zaèít se vracet doleva
		direction.x += (RandFloat() - 0.9f);
	}
	else if (dx < Xbound / -2.0f)
	{
		// zaèít se vracet doprava
		direction.x += (RandFloat() + 0.9f);
	}
	else
	{
		// lehce zmìnit direction
		direction.x += (RandFloat() - 0.5f);
	}

	if (dy > Ybound / 2.0f)
	{
		// zaèít se vracet dolù
		direction.y += (RandFloat() - 0.9f);
	}
	else if (dy < Ybound / -2.0f)
	{
		// zaèít se vracet nahoru
		direction.y += (RandFloat() + 0.9f);
	}
	else
	{
		direction.y += (RandFloat() - 0.5f);
	}
	
	direction.Normalize();
	if ((flyaway) && (b2Vec2(dx, dy).Length() > b2Vec2(Xbound, Ybound).Length()))
	{
		position.x += direction.x / 50.0f;
		position.y += direction.y / 50.0f;
	}
	else
	{
		position.x += direction.x / 100.0f;
		position.y += direction.y / 100.0f;
	}
}