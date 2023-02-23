#include<Game.h>
#include<TriggerArea.h>

TriggerArea::TriggerArea(TriggerType tt)
{
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	enabled = false;  // switch pro rùzný typy?
	resetme = false;
	deleteme = false;
	isinactors = false;
	type = tt;
	img = NULL;
}

TriggerArea::TriggerArea(TextureStorage * ts, TriggerType tt)
{
	fps = 0;
	framesdrawn = 0;
	reconstruct = false;
	enabled = false;
	resetme = false;
	deleteme = false;
	isinactors = false;
	type = tt;
	GetTextures(ts);
	width = height = 100;
}


void TriggerArea::GetTextures(TextureStorage * ts)
{
#ifdef _DEBUG
	if ((type == TriggerType::Death) || (type == TriggerType::PutZombie)) img = ts->GetTexture(TextureStorage::TexName::DeathBox1);
	else img = ts->GetTexture(TextureStorage::TexName::TriggerBox);
#endif
}

void TriggerArea::Draw(LPD3DXSPRITE D3DXsprite)
{
#ifdef _DEBUG
	if (!Game::ShouldIDraw(this)) return;

	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= 50.0f;
	vec.y -= 50.0f;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
#endif
}

void TriggerArea::ConstructBody(b2World * w, b2Vec2 pos)
{
	ConstructBody(w, pos, b2Vec2(0.5f, 0.5f));
}

void TriggerArea::ConstructBody(b2World * w, b2Vec2 pos, b2Vec2 size)
{
	b2BodyDef def;
	def.type = b2_staticBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(size.x, size.y);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.0f;
	fixtureDef.isSensor = true;
	body->CreateFixture(&fixtureDef);
	body->SetUserData((void *)this);
}

//DeleteBodyTA
DeleteBodyTA::DeleteBodyTA() : TriggerArea(TriggerType::DeleteBody)
{
	todelete = NULL;
}

DeleteBodyTA::DeleteBodyTA(TextureStorage * ts) : TriggerArea(ts, TriggerType::DeleteBody)
{
	todelete = NULL;
}

//ActorTA
ActorTA::ActorTA(TriggerType tt) : TriggerArea(tt)
{
	isinactors = true;
}

//SavePointTA
SavePointTA::SavePointTA(TextureStorage * ts) : ActorTA(TriggerType::SavePoint)
{
	SetWidthHeight();
	GetTextures(ts);
}

void SavePointTA::SetWidthHeight()
{
	width = 64;
	height = 128;
}

void SavePointTA::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::BallPillar);
}

void SavePointTA::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;

	D3DXVECTOR3 vec = Game::GetPosOnScreen(actorpos);
	//if (useactorpos) vec = Game::GetPosOnScreen(actorpos);
	//else
	//{
	//	vec = Game::GetPosOnScreen(this);
	//	vec.x -= 32.0f;
	//	vec.y -= 64.0f;
	//}
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}

//LevelExitTA
LevelExitTA::LevelExitTA(TextureStorage * ts) : ActorTA(TriggerType::LevelExit)
{
	SetWidthHeight();
	GetTextures(ts);
}

void LevelExitTA::SetWidthHeight()
{
	width = 64;
	height = 128;
}

void LevelExitTA::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::StarPillar);
}

void LevelExitTA::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;

	D3DXVECTOR3 vec = Game::GetPosOnScreen(actorpos);
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}

//PlaySoundTA
PlaySoundTA::PlaySoundTA(SoundStorage * ss, SoundStorage::SoundName sn) : TriggerArea(TriggerType::PlaySoundTrig)
{
	sound = ss->GetSound(sn);
}

PlaySoundTA::PlaySoundTA(TextureStorage * ts, SoundStorage * ss, SoundStorage::SoundName sn) : TriggerArea(ts, TriggerType::PlaySoundTrig)
{
	sound = ss->GetSound(sn);
}

//PutZombieTA
PutZombieTA::PutZombieTA(TextureStorage * ts) : TriggerArea(ts, TriggerType::PutZombie)
{}

PutZombieTA::PutZombieTA(TextureStorage * ts, b2Vec2 position, float Lbound, float Rbound, int Layer) : TriggerArea(ts, TriggerType::PutZombie)
{
	pos = position;
	bounds = b2Vec2(Lbound, Rbound);
	layer = Layer;
}

//PowerUpTA
PowerUpTA::PowerUpTA(TriggerType tt) : ActorTA(tt)
{
	fps = 5;
	framesdrawn = 0;
	state = 0;
	resetme = true;
	text = NULL;
	SetWidthHeight();
}

void PowerUpTA::SetWidthHeight()
{
	width = height = 64;
}

void PowerUpTA::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_staticBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(0.1f, 0.1f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.0f;
	fixtureDef.isSensor = true;
	body->CreateFixture(&fixtureDef);
	body->SetUserData((void *)this);
}

void PowerUpTA::NextSprite()
{
	if (state == 13) state = 0;
	else ++state;
}

void PowerUpTA::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!enabled) return;
	if (!Game::ShouldIDraw((Object *)this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	vec.x -= (float)width / 2.0f;
	vec.y -= (float)height / 2.0f;

	// poletování nahoru a dolù pomocí state
	switch (state)
	{
	case 0:
	case 1:
		break;
	case 2:
	case 3:
		vec.y += 1.0f;
		break;
	case 4:
		vec.y += 2.0f;
		break;
	case 5:
	case 6:
		vec.y += 1.0f;
		break;
	case 7:
	case 8:
		break;
	case 9:
	case 10:
		vec.y -= 1.0f;
		break;
	case 11:
		vec.y -= 2.0f;
		break;
	case 12:
	case 13:
		vec.y -= 1.0f;
		break;
	//case 14:
	//	state = 0;
	//	break;
	}
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}

//EnableBuckTA
EnableBuckTA::EnableBuckTA(TextureStorage * ts) : PowerUpTA(TriggerType::EnableBuck)
{
	GetTextures(ts);
}

void EnableBuckTA::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::PU_Horseshoe);
}

//DecFlyCost
DecFlyCostTA::DecFlyCostTA(TextureStorage * ts) : PowerUpTA(TriggerType::DecFlyCost)
{
	GetTextures(ts);
}

void DecFlyCostTA::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::PU_Wings);
}

//IncMaxBoxesTA
IncMaxBoxesTA::IncMaxBoxesTA(TextureStorage * ts) : PowerUpTA(TriggerType::IncMaxBoxes)
{
	GetTextures(ts);
}

void IncMaxBoxesTA::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::PU_Wand);
}

//EnableLevitTA
EnableLevitTA::EnableLevitTA(TextureStorage * ts) : PowerUpTA(TriggerType::EnableLevit)
{
	GetTextures(ts);
}

void EnableLevitTA::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::PU_Levit);
}