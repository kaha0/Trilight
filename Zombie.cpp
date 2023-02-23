#include<Game.h>
#include<Zombie.h>

Zombie::Zombie(TextureStorage * ts)
{
	fps = 3;
	framesdrawn = 0;
	reconstruct = true;
	SetWidthHeight();

	LPDIRECT3DTEXTURE9 tex;

	Wleft = new RoundList();
	tex = ts->GetTexture(TextureStorage::Zombie_left_01);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_02);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_03);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_04);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_05);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_06);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_07);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_08);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_09);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_10);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_11);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_12);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_13);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_14);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_15);
	Wleft->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_left_16);
	Wleft->Add(new Sprite(tex, true));

	Wright = new RoundList();
	tex = ts->GetTexture(TextureStorage::Zombie_right_01);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_02);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_03);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_04);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_05);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_06);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_07);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_08);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_09);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_10);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_11);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_12);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_13);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_14);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_15);
	Wright->Add(new Sprite(tex, true));
	tex = ts->GetTexture(TextureStorage::Zombie_right_16);
	Wright->Add(new Sprite(tex, true));

	left = false;
	sprite = Wright->First;
}

void Zombie::GetTextures(TextureStorage * ts)
{
	Sprite * aux = Wleft->First;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_14);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_15);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_left_16);

	aux = Wright->First;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_01);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_02);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_03);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_04);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_05);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_06);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_07);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_08);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_09);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_10);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_11);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_12);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_13);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_14);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_15);
	aux = aux->next;
	aux->img = ts->GetTexture(TextureStorage::Zombie_right_16);
}

void Zombie::NextSprite()
{
	sprite = sprite->next;
}

void Zombie::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(0.4f, 0.4f);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &shape;
	boxFixtureDef.density = 10.0f;
	boxFixtureDef.friction = 1.0f;
	body->CreateFixture(&boxFixtureDef);
	body->SetFixedRotation(true);
	body->SetUserData((void *)this);
}

void Zombie::SetWidthHeight()
{
	width = height = 100;
}

void Zombie::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 50;
	vec.y -= 50;
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}

void Zombie::Step()
{
	if (body)
	{
		// <AI>
		if (Game::player && Game::player->body)
		{
			IsBodyRayCastCallback ibrc;
			b2Vec2 ppos = Game::player->body->GetPosition();
			b2Vec2 mpos = body->GetPosition();
			body->GetWorld()->RayCast(&ibrc, mpos, ppos);
			if (ibrc.body)
			{
				Object * o = (Object *)ibrc.body->GetUserData();
				Player * pp = dynamic_cast<Player *>(o);
				if (pp)
				{
					if ((mpos.x >= ppos.x) && (!left))
					{
						left = true;
						sprite = Wleft->First;
					}
					if ((mpos.x < ppos.x) && (left))
					{
						left = false;
						sprite = Wright->First;
					}

					b2Vec2 vel = body->GetLinearVelocity();
					if (left) body->SetLinearVelocity(b2Vec2(-2.5f, vel.y));
					else body->SetLinearVelocity(b2Vec2(2.5f, vel.y));
					return;
				}
			}
		}
		//</AI>

		b2Vec2 pos = body->GetPosition();
		if ((pos.x < Lbound) && left)
		{
			left = false;
			sprite = Wright->First;
		}
		if ((pos.x > Rbound) && (!left))
		{
			left = true;
			sprite = Wleft->First;
		}

		b2Vec2 vel = body->GetLinearVelocity();
		if (left) body->SetLinearVelocity(b2Vec2(-2.5f, vel.y));
		else body->SetLinearVelocity(b2Vec2(2.5f, vel.y));
	}
}