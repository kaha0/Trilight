#pragma warning( disable : 4482 )

#include<Player.h>
#include<Game.h>

Player::Player(TextureStorage * ts)
{
	playerKA = new PlayerKA<Player>(this);
	SetWidthHeight();
	fps = 3;
	framesdrawn = 0;
	reconstruct = true;
	dobuckL = dobuckR = NULL;
	AJ = NULL;
	RD = NULL;
	Trixie = NULL;
	CurrentPony = NULL;

	GetTextures(ts);
}

void Player::GetTextures(TextureStorage * ts)
{
	if (AJ) AJ->GetTextures(ts);
	else
	{
		AJ = new AJPony(ts);
		dobuckL = AJ->BuckL->First->next->next->next->next;
		dobuckR = AJ->BuckR->First->next->next->next->next;
	}

	if (RD) RD->GetTextures(ts);
	else RD = new RDPony(ts);

	if (Trixie) Trixie->GetTextures(ts);
	else Trixie = new TrixiePony(ts);
}

void Player::SetState(int state)
{
	switch (state)
	{
	case 0:
		playerKA->Actual = playerKA->IL;
		movement = Movement::IdleL;
		sprite = CurrentPony->IdleL->First;
		break;

	case 1:
		playerKA->Actual = playerKA->IR;
		movement = Movement::IdleR;
		sprite = CurrentPony->IdleR->First;
		break;
	}
}

void Player::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	def.allowSleep = false;  // POKUS
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	b2Vec2 vertices[5];
	vertices[0].Set(0.0f, 0.5f);
	vertices[1].Set(-0.4f, 0.0f);
	vertices[2].Set(-0.4f, -0.5f);
	vertices[3].Set(0.4f, -0.5f);
	vertices[4].Set(0.4f, 0.0f);
	shape.Set(vertices, 5);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	//fixtureDef.density = 8.0f;
	//fixtureDef.density = 16.0f;
	fixtureDef.density = 20.0f;
	fixtureDef.friction = 1.0f;
	fixtureDef.filter.groupIndex = -1;  // všechny bodies který nebudou kolidovat s playerem by mìly mít groupIndex = -1;
	body->CreateFixture(&fixtureDef);
	body->SetFixedRotation(true);  // <-- nebude se otáèet
	body->SetUserData((void *)this);
}

void Player::SetWidthHeight()
{
	height = 128;  // podle konstant nebo automaticky ?
	width = 128;   // C:\PRGII\directx\dimensions of a texture.txt
}

bool Player::ShouldIDraw()
{
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	//float halfdiag = sqrt((float)((height * height) + (width * width)));  // ale zrovna u playera je halfdiag zbyteèná protože se netoèí
	//halfdiag /= 2.0f;
	if ((vec.x + width / 2.0f >= 0) && (vec.x - width / 2.0f < Game::ScreenWidth) && (vec.y + height / 2.0f >= 0) && (vec.y - height / 2.0f < Game::ScreenHeight))
		return true;

	return false;
}

void Player::Draw(LPD3DXSPRITE D3DXsprite)
{
	//if (!Game::ShouldIDraw(this)) return;
	if (!ShouldIDraw()) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 64;							//
	vec.y -= 64;							//
#ifdef _DEBUG
	b2Vec2 bp = body->GetPosition();		// DEBUG
	pBodyX = bp.x;							//
	pBodyY = bp.y;							//
	drawX = vec.x;							//
	drawY = vec.y;							//
#endif
	D3DXsprite->Draw(sprite->img, NULL, NULL, &vec, 0xFFFFFFFF);
}

void Player::NextSprite()
{
	if (sprite->terminal)
	{
		Movement m = playerKA->GetMovement();
		if (m == movement)
		{
			if (m == Movement::JumpL || m == Movement::JumpR) return;
			if (m == Movement::BuckL)
			{
				playerKA->Actual = playerKA->IL;
				movement = Movement::IdleL;
				sprite = CurrentPony->IdleL->First;
				return;
			}
			if (m == Movement::BuckR)
			{
				playerKA->Actual = playerKA->IR;
				movement = Movement::IdleR;
				sprite = CurrentPony->IdleR->First;
				return;
			}
			if (m == Movement::DashL)
			{
				playerKA->Actual = playerKA->FL;
				movement = Movement::FallL;
				sprite = CurrentPony->FallL->First;
				return;
			}
			if (m == Movement::DashR)
			{
				playerKA->Actual = playerKA->FR;
				movement = Movement::FallR;
				sprite = CurrentPony->FallR->First;
				return;
			}
			sprite = sprite->next;
			return;
		}

		movement = m;
		switch (m)
		{
			case Movement::IdleL:
				sprite = CurrentPony->IdleL->First;
				break;
			case Movement::IdleR:
				sprite = CurrentPony->IdleR->First;
				break;
			case Movement::WalkL:
				sprite = CurrentPony->WalkL->First;
				break;
			case Movement::WalkR:
				sprite = CurrentPony->WalkR->First;
				break;
			case Movement::RunL:
				sprite = AJ->RunL->First;
				break;
			case Movement::RunR:
				sprite = AJ->RunR->First;
				break;
			case Movement::JumpL:
				sprite = CurrentPony->JumpL->First;
				break;
			case Movement::JumpR:
				sprite = CurrentPony->JumpR->First;
				break;
			case Movement::FallL:
				sprite = CurrentPony->FallL->First;
				break;
			case Movement::FallR:
				sprite = CurrentPony->FallR->First;
				break;
			case Movement::FlyL:
				sprite = RD->FlyL->First;
				break;
			case Movement::FlyR:
				sprite = RD->FlyR->First;
				break;
			case Movement::BuckL:
				sprite = AJ->BuckL->First;
				break;
			case Movement::BuckR:
				sprite = AJ->BuckR->First;
				break;
			case Movement::DashL:
				sprite = RD->DashL->First;
				break;
			case Movement::DashR:
				sprite = RD->DashR->First;
				break;
		}
	}
	else
	{
		if (((movement == Movement::DashL) && (playerKA->Actual != playerKA->DashL))
			|| ((movement == Movement::DashR) && (playerKA->Actual != playerKA->DashR)))
		{
			movement = playerKA->GetMovement();
			switch (movement)
			{
				case Movement::IdleL:
					sprite = CurrentPony->IdleL->First;
					break;
				case Movement::IdleR:
					sprite = CurrentPony->IdleR->First;
					break;
				case Movement::WalkL:
					sprite = CurrentPony->WalkL->First;
					break;
				case Movement::WalkR:
					sprite = CurrentPony->WalkR->First;
					break;
				case Movement::RunL:
					sprite = AJ->RunL->First;
					break;
				case Movement::RunR:
					sprite = AJ->RunR->First;
					break;
				case Movement::JumpL:
					sprite = CurrentPony->JumpL->First;
					break;
				case Movement::JumpR:
					sprite = CurrentPony->JumpR->First;
					break;
				case Movement::FallL:
					sprite = CurrentPony->FallL->First;
					break;
				case Movement::FallR:
					sprite = CurrentPony->FallR->First;
					break;
				case Movement::FlyL:
					sprite = RD->FlyL->First;
					break;
				case Movement::FlyR:
					sprite = RD->FlyR->First;
					break;
				case Movement::BuckL:
					sprite = AJ->BuckL->First;
					break;
				case Movement::BuckR:
					sprite = AJ->BuckR->First;
					break;
				case Movement::DashL:
					sprite = RD->DashL->First;
					break;
				case Movement::DashR:
					sprite = RD->DashR->First;
					break;
			}
			return;
		}
		sprite = sprite->next;
	}
}

void Player::Fall(bool evenflying)
{
	body->GetFixtureList()->SetFriction(0.0f);
	playerKA->Fall(evenflying);
}

void Player::Land()
{
	body->GetFixtureList()->SetFriction(1.0f);  // po dopadu vrátit tøení na nìjakou kladnou hodnotu
	switch (playerKA->Actual->mv)
	{
	case Movement::FallL:
		{
			playerKA->Actual = playerKA->IL; // stavy LandL, LandR ??
			return;
		}
	case Movement::FallR:
		{
			playerKA->Actual = playerKA->IR;
			return;
		}
	case Movement::FlyL:
		{
			playerKA->Actual = playerKA->IL;
			playerKA->KeyUp(VK_SPACE);
			return;
		}
	case Movement::FlyR:
		{
			playerKA->Actual = playerKA->IR;
			playerKA->KeyUp(VK_SPACE);
			return;
		}
	case Movement::JumpL:
		{
			playerKA->Actual = playerKA->IL;
			return;
		}
	case Movement::JumpR:
		{
			playerKA->Actual = playerKA->IR;
			return;
		}
	}
}

void Player::SwitchToAJ()
{
	CurrentPony = AJ;
	movement = playerKA->GetMovement();
	switch (movement)
	{
	case Movement::FlyL:  // to by snad mìlo bejt zbyteèný
	case Movement::DashL:
	case Movement::FallL:
		sprite = AJ->FallL->First;
		break;

	case Movement::FlyR:  // to by snad mìlo bejt zbyteèný
	case Movement::DashR:
	case Movement::FallR:
		sprite = AJ->FallR->First;
		break;

	case Movement::IdleL:
		sprite = AJ->IdleL->First;
		break;

	case Movement::IdleR:
		sprite = AJ->IdleR->First;
		break;

	case Movement::JumpL:
		sprite = AJ->JumpL->First;
		break;

	case Movement::JumpR:
		sprite = AJ->JumpR->First;
		break;

	case Movement::WalkL:
		sprite = AJ->WalkL->First;
		break;

	case Movement::WalkR:
		sprite = AJ->WalkR->First;
		break;
	}
}

void Player::SwitchToRD()
{
	CurrentPony = RD;
	movement = playerKA->GetMovement();
	switch (movement)
	{
	case Movement::FallL:
		sprite = RD->FallL->First;
		break;

	case Movement::FallR:
		sprite = RD->FallR->First;
		break;

	case Movement::IdleL:
		sprite = RD->IdleL->First;
		break;

	case Movement::IdleR:
		sprite = RD->IdleR->First;
		break;

	case Movement::JumpL:
		sprite = RD->JumpL->First;
		break;

	case Movement::JumpR:
		sprite = RD->JumpR->First;
		break;

	case Movement::RunL:  // zbyteèný
	case Movement::WalkL:
		sprite = RD->WalkL->First;
		break;

	case Movement::RunR:  // zbyteèný
	case Movement::WalkR:
		sprite = RD->WalkR->First;
		break;
	}
}

void Player::SwitchToTrixie()
{
	CurrentPony = Trixie;
	movement = playerKA->GetMovement();
	switch (movement)
	{
	case Movement::FlyL:  // zbyteèný
	case Movement::DashL:
	case Movement::FallL:
		sprite = Trixie->FallL->First;
		break;

	case Movement::FlyR:  // zbyteèný
	case Movement::DashR:
	case Movement::FallR:
		sprite = Trixie->FallR->First;
		break;

	case Movement::IdleL:
		sprite = Trixie->IdleL->First;
		break;

	case Movement::IdleR:
		sprite = Trixie->IdleR->First;
		break;

	case Movement::JumpL:
		sprite = Trixie->JumpL->First;
		break;

	case Movement::JumpR:
		sprite = Trixie->JumpR->First;
		break;

	case Movement::RunL:  // zbyteèný
	case Movement::WalkL:
		sprite = Trixie->WalkL->First;
		break;

	case Movement::RunR:  // zbyteèný
	case Movement::WalkR:
		sprite = Trixie->WalkR->First;
		break;
	}
}

void Player::SetEnergyToMax()
{
	if (AJ) AJ->Energy = AJ->MaxEnergy;
	if (RD) RD->Energy = RD->MaxEnergy;
	if (Trixie) Trixie->Energy = Trixie->MaxEnergy;
}

void Player::KeyDown(WPARAM key)
{
	playerKA->KeyDown(key);
}

void Player::KeyUp(WPARAM key)
{
	playerKA->KeyUp(key);
}

Player::~Player()
{
	delete playerKA;
	delete AJ;
	delete RD;
	delete Trixie;
}