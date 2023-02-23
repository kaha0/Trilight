#include<PulleyPlatform.h>
#include<Game.h>

PulleyPlatform::PulleyPlatform(TextureStorage * ts)
{
	userope = false;
	width = 150;
	height = 12;
	fps = 0;
	framesdrawn = 0;
	reconstruct = true;
	GetTextures(ts);
}

PulleyPlatform::PulleyPlatform(TextureStorage * ts, float anchor)
{
	userope = true;
	ropeheight = anchor;
	width = 150;
	height = 12;
	fps = 0;
	framesdrawn = 0;
	reconstruct = true;
	GetTextures(ts);
}

void PulleyPlatform::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Platform3);
	rope = ts->GetTexture(TextureStorage::TexName::Pulley_Rope);
}

void PulleyPlatform::ConstructBody(b2World * w, b2Vec2 pos)
{
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position = pos;
	body = w->CreateBody(&def);
	b2PolygonShape shape;
	shape.SetAsBox(0.75f, 0.08f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 10.0f;
	fixtureDef.friction = 1.0f;
	body->CreateFixture(&fixtureDef);
	body->SetFixedRotation(true);
	body->SetUserData((void *)this);
}

bool PulleyPlatform::ShouldIDraw()
{
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	if (userope)
	{
		if (ropeheight < (body->GetPosition()).y)
		{
			float rh_scr = (Game::GetPosOnScreen(b2Vec2(0.0f, ropeheight))).y;
			if ((vec.x + width / 2.0f >= 0) && (vec.x - width / 2.0f < Game::ScreenWidth) && (rh_scr >= 0) && (vec.y - height / 2.0f < Game::ScreenHeight))
				return true;
			return false;
		}
		else
		{
			float rh_scr = (Game::GetPosOnScreen(b2Vec2(0.0f, ropeheight))).y;
			if ((vec.x + width / 2.0f >= 0) && (vec.x - width / 2.0f < Game::ScreenWidth) && (vec.y + height / 2.0f >= 0) && (rh_scr < Game::ScreenHeight))
				return true;
			return false;
		}
	}
	else
	{
		if ((vec.x + width / 2.0f >= 0) && (vec.x - width / 2.0f < Game::ScreenWidth) && (vec.y + height / 2.0f >= 0) && (vec.y - height / 2.0f < Game::ScreenHeight))
			return true;
		return false;
	}
}

void PulleyPlatform::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!ShouldIDraw()) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	D3DXVECTOR3 rope_vec = vec;
	vec.x -= 75.0f;
	vec.y -= 6.0f;
	D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);

	if (!userope) return;

	if (ropeheight < (body->GetPosition()).y)
	{
		float rh_scr = (Game::GetPosOnScreen(b2Vec2(0.0f, ropeheight))).y;
		rope_vec.x -= 4.0f;
		while (rope_vec.y < rh_scr)
		{
			if (rope_vec.y > Game::ScreenHeight) break;
			D3DXsprite->Draw(rope, NULL, NULL, &rope_vec, 0xFFFFFFFF);
			rope_vec.y += 20.0f;
		}
	}
	else
	{
		float rh_scr = (Game::GetPosOnScreen(b2Vec2(0.0f, ropeheight))).y;
		rope_vec.x -= 4.0f;
		rope_vec.y -= 20.0f;
		while (rope_vec.y >= rh_scr)
		{
			if (rope_vec.y < -20.0f) break;
			D3DXsprite->Draw(rope, NULL, NULL, &rope_vec, 0xFFFFFFFF);
			rope_vec.y -= 20.0f;
		}
	}
}