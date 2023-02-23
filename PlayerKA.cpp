#pragma warning( disable : 4482 )

#include<PlayerKA.h>
#include<Player.h>

PlayerKA<Player>::PlayerKA(Player * t) : jumpforce(62.5f), flyforcestrong(3.75f), flyforce(1.9f), dashforce(80.0f)
{
	hasOTM = false;
	IL = new Vertex(Movement::IdleL, "IL");
	IR = new Vertex(Movement::IdleR, "IR");
	FL = new Vertex(Movement::FallL, "FL");
	FR = new Vertex(Movement::FallR, "FR");
	JL = new Vertex(Movement::JumpL, "JL");
	JR = new Vertex(Movement::JumpR, "JR");
	FlyL = new Vertex(Movement::FlyL, "FlyL");
	FlyR = new Vertex(Movement::FlyR, "FlyR");
	DashL = new Vertex(Movement::DashL, "DashL");
	DashR = new Vertex(Movement::DashR, "DashR");
	WL = new Vertex(Movement::WalkL, "WL");
	WR = new Vertex(Movement::WalkR, "WR");
	DL = new Vertex(Movement::DeathL, "DL");
	DR = new Vertex(Movement::DeathR, "DR");
	BL = new Vertex(Movement::BuckL, "BL");
	BR = new Vertex(Movement::BuckR, "BR");

	IL2 = new Vertex(Movement::IdleL, "IL2");  // shift
	IR2 = new Vertex(Movement::IdleR, "IR2");  // shift
	WL2 = new Vertex(Movement::WalkL, "WL2");  // arrow in the opposite direction
	WR2 = new Vertex(Movement::WalkR, "WR2");  // -||-
	RL = new Vertex(Movement::RunL, "RL");
	RR = new Vertex(Movement::RunR, "RR");
	RL2 = new Vertex(Movement::RunL, "RL2");  // -||-
	RR2 = new Vertex(Movement::RunR, "RR2");  // -||-

	owner = t;
	EntryPoint = IR;
	Actual = IR;

	Edge<Vertex> *h = new Edge<Vertex>();
	h->type = EdgeType::SetVelocity;
	
	h->target = WL;
	h->amount = -2;
	std::pair<WPARAM, Edge<Vertex>> p(VK_LEFT, *h);
	IL->keydowntr->insert(p);

	h->target = IR;
	h->amount = 0;
	p.first = VK_RIGHT;
	p.second = *h;
	IL->keydowntr->insert(p);

	h->target = IL2;
	h->amount = 0;
	p.first = VK_SHIFT;
	p.second = *h;
	IL->keydowntr->insert(p);

	// Buck Left
	h->target = BL;
	p.first = 0x45;
	p.second = *h;
	IL->keydowntr->insert(p);

	h->target = RL;
	h->amount = -3;
	p.first = VK_LEFT;
	p.second = *h;
	IL2->keydowntr->insert(p);

	h->target = IR2;
	h->amount = 0;
	p.first = VK_RIGHT;
	p.second = *h;
	IL2->keydowntr->insert(p);

	h->target = IL;
	h->amount = 0;
	p.first = VK_SHIFT;
	p.second = *h;
	IL2->keyuptr->insert(p);

	h->target = WR;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	IR->keydowntr->insert(p);

	h->target = IL;
	h->amount = 0;
	p.first = VK_LEFT;
	p.second = *h;
	IR->keydowntr->insert(p);

	h->target = IR2;
	h->amount = 0;
	p.first = VK_SHIFT;
	p.second = *h;
	IR->keydowntr->insert(p);

	// Buck Right
	h->target = BR;
	p.first = 0x45;
	p.second = *h;
	IR->keydowntr->insert(p);

	h->target = IL2;
	h->amount = 0;
	p.first = VK_LEFT;
	p.second = *h;
	IR2->keydowntr->insert(p);

	h->target = RR;
	h->amount = 3;
	p.first = VK_RIGHT;
	p.second = *h;
	IR2->keydowntr->insert(p);

	h->target = IR;
	h->amount = 0;
	p.first = VK_SHIFT;
	p.second = *h;
	IR2->keyuptr->insert(p);

	h->target = IL;
	h->amount = 0;
	p.first = VK_LEFT;
	p.second = *h;
	WL->keyuptr->insert(p);

	h->target = IR;
	h->amount = 0;
	p.first = VK_RIGHT;
	p.second = *h;
	WR->keyuptr->insert(p);

	h->target = RL;
	h->amount = -3;
	p.first = VK_SHIFT;
	p.second = *h;
	WL->keydowntr->insert(p);

	h->target = RR;
	h->amount = 3;
	p.first = VK_SHIFT;
	p.second = *h;
	WR->keydowntr->insert(p);

	h->target = WL2;
	h->amount = -2;
	p.first = VK_RIGHT;
	p.second = *h;
	WL->keydowntr->insert(p);

	h->target = WR2;
	h->amount = 2;
	p.first = VK_LEFT;
	p.second = *h;
	WR->keydowntr->insert(p);

	// smyèka na WL
	h->target = WL;
	h->amount = -2;
	p.first = VK_LEFT;
	p.second = *h;
	WL->keydowntr->insert(p);

	// smyèka na WR
	h->target = WR;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	WR->keydowntr->insert(p);

	h->target = WL;
	h->amount = -2;
	p.first = VK_SHIFT;
	p.second = *h;
	RL->keyuptr->insert(p);

	h->target = IL2;
	h->amount = 0;
	p.first = VK_LEFT;
	p.second = *h;
	RL->keyuptr->insert(p);

	h->target = RL2;
	h->amount = -3;
	p.first = VK_RIGHT;
	p.second = *h;
	RL->keydowntr->insert(p);

	// smyèka na RL
	h->target = RL;
	h->amount = -3;
	p.first = VK_LEFT;
	p.second = *h;
	RL->keydowntr->insert(p);

	h->target = WR;
	h->amount = 2;
	p.first = VK_SHIFT;
	p.second = *h;
	RR->keyuptr->insert(p);

	h->target = IR2;
	h->amount = 0;
	p.first = VK_RIGHT;
	p.second = *h;
	RR->keyuptr->insert(p);

	h->target = RR2;
	h->amount = 3;
	p.first = VK_LEFT;
	p.second = *h;
	RR->keydowntr->insert(p);

	//smyèka na RR
	h->target = RR;
	h->amount = 3;
	p.first = VK_RIGHT;
	p.second = *h;
	RR->keydowntr->insert(p);

	// WL2
	h->target = WL;
	h->amount = -2;
	p.first = VK_RIGHT;
	p.second = *h;
	WL2->keyuptr->insert(p);

	h->target = WR;
	h->amount = 2;
	p.first = VK_LEFT;
	p.second = *h;
	WL2->keyuptr->insert(p);

	h->target = RL2;
	h->amount = -3;
	p.first = VK_SHIFT;
	p.second = *h;
	WL2->keydowntr->insert(p);

	// smyèka na WL2
	h->target = WL2;
	h->amount = -2;
	p.first = VK_LEFT;
	p.second = *h;
	WL2->keydowntr->insert(p);

	// WR2
	h->target = WR;
	h->amount = 2;
	p.first = VK_LEFT;
	p.second = *h;
	WR2->keyuptr->insert(p);

	h->target = WL;
	h->amount = -2;
	p.first = VK_RIGHT;
	p.second = *h;
	WR2->keyuptr->insert(p);

	h->target = RR2;
	h->amount = 3;
	p.first = VK_SHIFT;
	p.second = *h;
	WR2->keydowntr->insert(p);

	// smyèka na WR2
	h->target = WR2;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	WR2->keydowntr->insert(p);

	// RL2
	h->target = RL;
	h->amount = -3;
	p.first = VK_RIGHT;
	p.second = *h;
	RL2->keyuptr->insert(p);

	h->target = WL2;
	h->amount = -2;
	p.first = VK_SHIFT;
	p.second = *h;
	RL2->keyuptr->insert(p);

	h->target = RR;
	h->amount = 3;
	p.first = VK_LEFT;
	p.second = *h;
	RL2->keyuptr->insert(p);

	//smyèka
	h->target = RL2;
	h->amount = -3;
	p.first = VK_LEFT;
	p.second = *h;
	RL2->keydowntr->insert(p);

	// RR2
	h->target = RR;
	h->amount = 3;
	p.first = VK_LEFT;
	p.second = *h;
	RR2->keyuptr->insert(p);

	h->target = WR2;
	h->amount = 2;
	p.first = VK_SHIFT;
	p.second = *h;
	RR2->keyuptr->insert(p);

	h->target = RL;
	h->amount = -3;
	p.first = VK_RIGHT;
	p.second = *h;
	RR2->keyuptr->insert(p);

	//smyèka
	h->target = RR2;
	h->amount = 3;
	p.first = VK_RIGHT;
	p.second = *h;
	RR2->keydowntr->insert(p);

	// FlyL
	h->target = FlyL;
	h->amount = -2;
	p.first = VK_LEFT;
	p.second = *h;
	FlyL->keydowntr->insert(p);

	h->target = FlyL;
	h->amount = 0;
	p.first = VK_LEFT;
	p.second = *h;
	FlyL->keyuptr->insert(p);

	h->target = FlyR;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	FlyL->keydowntr->insert(p);

	// FlyR
	h->target = FlyR;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	FlyR->keydowntr->insert(p);

	h->target = FlyR;
	h->amount = 0;
	p.first = VK_RIGHT;
	p.second = *h;
	FlyR->keyuptr->insert(p);

	h->target = FlyL;
	h->amount = -2;
	p.first = VK_LEFT;
	p.second = *h;
	FlyR->keydowntr->insert(p);

	h->type = EdgeType::ApplyImpulse;

	// Dash keyup
	h->target = FL;
	h->amount = 0;
	p.first = 0x57;
	p.second = *h;
	DashL->keyuptr->insert(p);

	h->target = FR;
	h->amount = 0;
	p.first = 0x57;
	p.second = *h;
	DashR->keyuptr->insert(p);

	// Jump
	h->amount = jumpforce;

	h->target = JL;
	p.first = VK_SPACE;
	p.second = *h;
	IL->keydowntr->insert(p);
	WL->keydowntr->insert(p);
	RL->keydowntr->insert(p);

	h->target = JR;
	p.first = VK_SPACE;
	p.second = *h;
	IR->keydowntr->insert(p);
	WR->keydowntr->insert(p);
	RR->keydowntr->insert(p);

	h->type = EdgeType::SetVelocity;
	//ovládání ve skoku
	h->target = JL;
	h->amount = -2;
	p.first = VK_LEFT;
	p.second = *h;
	JL->keydowntr->insert(p);

	h->target = JL;
	h->amount = 0;
	p.first = VK_LEFT;
	p.second = *h;
	JL->keyuptr->insert(p);

	h->target = JR;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	JL->keydowntr->insert(p);

	h->target = JR;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	JR->keydowntr->insert(p);

	h->target = JR;
	h->amount = 0;
	p.first = VK_RIGHT;
	p.second = *h;
	JR->keyuptr->insert(p);

	h->target = JL;
	h->amount = -2;
	p.first = VK_LEFT;
	p.second = *h;
	JR->keydowntr->insert(p);

	//ovládání pøi pádu
	h->target = FL;
	h->amount = -2;
	p.first = VK_LEFT;
	p.second = *h;
	FL->keydowntr->insert(p);

	h->target = FL;
	h->amount = 0;
	p.first = VK_LEFT;
	p.second = *h;
	FL->keyuptr->insert(p);

	h->target = FR;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	FL->keydowntr->insert(p);

	h->target = FR;
	h->amount = 2;
	p.first = VK_RIGHT;
	p.second = *h;
	FR->keydowntr->insert(p);

	h->target = FR;
	h->amount = 0;
	p.first = VK_RIGHT;
	p.second = *h;
	FR->keyuptr->insert(p);

	h->target = FL;
	h->amount = -2;
	p.first = VK_LEFT;
	p.second = *h;
	FR->keydowntr->insert(p);

	delete h;
}

void PlayerKA<Player>::KeyDown(WPARAM key)
{
	if (owner->CurrentPony == owner->RD)
	{
		if (key == VK_SPACE)
		{
			b2Vec2 pvel = owner->body->GetLinearVelocity();

			if ((Actual == FL) || (Actual == FR) || (Actual == FlyL) || (Actual == FlyR))
			{
				if (owner->RD->Energy < 10.0f) return;
				if (Actual == FL) Actual = FlyL;
				if (Actual == FR) Actual = FlyR;
				owner->body->GetFixtureList()->SetFriction(0.0f);  // ve vzduchu nebude mít tøení
				if (pvel.y < -2) owner->body->ApplyLinearImpulse(b2Vec2(0.0f, flyforcestrong), b2Vec2(0.0f, 0.0f));
				else owner->body->ApplyLinearImpulse(b2Vec2(0.0f, flyforce), b2Vec2(0.0f, 0.0f));
				return;
			}
			if ((Actual == JL) || (Actual == JR))
			{
				if (owner->RD->Energy < 10.0f) return;
				if (pvel.y < 0.2f)
				{
					if (Actual == JL) Actual = FlyL;
					if (Actual == JR) Actual = FlyR;
					owner->body->GetFixtureList()->SetFriction(0.0f);
					owner->body->ApplyLinearImpulse(b2Vec2(0.0f, flyforce), b2Vec2(0.0f, 0.0f));
				}
				return;
			}
		}
		else if (key == 0x57)
		{
			// dash
			if (!owner->RD->candash) return;
			if (Actual == DashL || Actual == DashR) return;
			if (owner->RD->Energy < 50.0f) return;
			Movement m = Actual->mv;
			if (m == Movement::IdleL || m == Movement::WalkL || m == Movement::JumpL || m == Movement::FallL || m == Movement::FlyL)
			{
				Actual = DashL;
				owner->body->ApplyLinearImpulse(b2Vec2(-1.0f * dashforce, 0.0f), b2Vec2(0.0f, 0.0f));
			}
			else
			{
				Actual = DashR;
				owner->body->ApplyLinearImpulse(b2Vec2(dashforce, 0.0f), b2Vec2(0.0f, 0.0f));
			}
			owner->RD->Energy -= 50.0f;
			return;
		}
	}

	std::map<WPARAM, Edge<Vertex>>::iterator iter = Actual->keydowntr->find(key);
	if (iter == Actual->keydowntr->end()) return;

	Edge<Vertex> h = (*iter).second;
	if (h.target->mv == Movement::RunL || h.target->mv == Movement::RunR)
	{
		if (owner->CurrentPony != owner->AJ) return;
		if (owner->AJ->Energy < 20.0f) return;
	}
	if (h.target == BL || h.target == BR)
	{
		if (owner->CurrentPony != owner->AJ) return;
		if (!owner->AJ->canbuck) return;
		Actual = h.target;
		return;
	}

	Actual = h.target;
	if (h.type == EdgeType::ApplyImpulse)  // kydybysme potøebovali víc typù tak switch
	{
		owner->body->GetFixtureList()->SetFriction(0.0f);  // ve vzduchu nebude mít tøení
		owner->body->ApplyLinearImpulse(b2Vec2(0.0f, h.amount), b2Vec2(0.0f, 0.0f));
		return;
	}
	else
	{
		// tohle mùžu udìlat, protože h je lokální kopie
		if (h.target->mv == Movement::RunL || h.target->mv == Movement::RunR)
		{
			if (h.amount > 0.0f) h.amount = owner->AJ->runspeed;
			else h.amount = -(owner->AJ->runspeed);
		}
		if (h.target->mv == Movement::FlyL || h.target->mv == Movement::FlyR)
		{
			if (h.amount > 0.0f) h.amount = owner->RD->flyspeed;
			else h.amount = -(owner->RD->flyspeed);
		}
		b2Vec2 vel = owner->body->GetLinearVelocity();
		vel.x = h.amount;
		owner->body->SetLinearVelocity(vel);
		return;
	}
}

void PlayerKA<Player>::KeyUp(WPARAM key)
{
	if (key == VK_SPACE && ((Actual == FlyL) || (Actual == FlyR)) && owner->CurrentPony == owner->RD)
	{
		if (Actual == FlyL) Actual = FL;
		else Actual = FR;
		return;
	}

	std::map<WPARAM, Edge<Vertex>>::iterator iter = Actual->keyuptr->find(key);
	if (iter == Actual->keyuptr->end()) return;

	Edge<Vertex> h = (*iter).second;
	Actual = h.target;

	b2Vec2 vel = owner->body->GetLinearVelocity();
	vel.x = h.amount;
	owner->body->SetLinearVelocity(vel);
}

void PlayerKA<Player>::Fall(bool evenflying)
{
	if (Actual == FL || Actual == FR) return;
	if (Actual == DashL || Actual == DashR) return;  // ?
	if (!evenflying)
	{
		if (Actual == FlyL || Actual == FlyR) return;
	}

	Movement m = Actual->mv;
	if (m == Movement::BuckL || m == Movement::IdleL || m == Movement::JumpL || m == Movement::RunL || m == Movement::WalkL || m == Movement::FlyL)
		Actual = FL;
	else Actual = FR;
}

Movement PlayerKA<Player>::GetMovement()
{
	return Actual->mv;
}

PlayerKA<Player>::~PlayerKA()
{
	// smazat celej automat !
	delete IL;
	delete IR;
	delete FL;
	delete FR;
	delete JL;
	delete JR;
	delete FlyL;
	delete FlyR;
	delete WL;
	delete WR;
	delete DL;
	delete DR;
	delete BL;
	delete BR;
	delete IL2;
	delete IR2;
	delete WL2;
	delete WR2;
	delete RL;
	delete RR;
	delete RL2;
	delete RR2;
}