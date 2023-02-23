#include<SkillsText.h>
#include<Game.h>

SkillText::SkillText()
{
	visited = false;
	framesdrawn = 0;
}

void SkillText::SetVisited(bool value)
{
	visited = value;
}

//BuckText
BuckText::BuckText(TextureStorage * ts, b2Vec2 pos)
{
	fade = 0xFFFFFFFF;
	position = pos;
	GetTextures(ts);
	SetWidthHeight();
}

void BuckText::GetTextures(TextureStorage * ts)
{
	first = ts->GetTexture(TextureStorage::TexName::Text_Buck1);
	second = ts->GetTexture(TextureStorage::TexName::Text_Buck2);
}

void BuckText::SetWidthHeight()
{
	if (visited)
	{
		width = 300;
		height = 100;
	}
	else
	{
		width = 500;
		height = 100;
	}
}

void BuckText::SetVisited(bool value)
{
	if (!visited && value)
	{
		visited = value;
		framesdrawn = -1;
	}
	else
	{
		visited = value;
		framesdrawn = 0;
		fade = 0xFFFFFFFF;
		SetWidthHeight();
	}
}

void BuckText::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	if (visited)
	{
		if (framesdrawn == 0) D3DXsprite->Draw(second, NULL, NULL, &vec, 0xFFFFFFFF);
		if (framesdrawn < 0)  // means we're still drawing the previous sprite
		{
			if (fade == 0x0FFFFFFF)
			{
				framesdrawn = 1;
				return;
			}
			fade -= 0x10000000;
			D3DXsprite->Draw(first, NULL, NULL, &vec, fade);
			return;
		}
		if (framesdrawn > 0)  // new sprite is "fading in"
		{
			if (fade == 0xFFFFFFFF) framesdrawn = 0;
			else fade += 0x10000000;
			D3DXsprite->Draw(second, NULL, NULL, &vec, fade);
			return;
		}
	}
	else  // no need to control framesdrawn
	{
		D3DXsprite->Draw(first, NULL, NULL, &vec, 0xFFFFFFFF);
	}
}

//FlyText
FlyText::FlyText(TextureStorage * ts, b2Vec2 pos)
{
	fade = 0xFFFFFFFF;
	position = pos;
	GetTextures(ts);
	SetWidthHeight();
}

void FlyText::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Text_Fly);
}

void FlyText::SetWidthHeight()
{
	width = 400;
	height = 128;
}

void FlyText::SetVisited(bool value)
{
	if (!visited && value)
	{
		visited = value;
		framesdrawn = -1;
	}
	else
	{
		visited = value;
		framesdrawn = 0;
		fade = 0xFFFFFFFF;
	}
}

void FlyText::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (visited && (framesdrawn == 0)) return;
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	if (visited)
	{
		if (fade == 0x0FFFFFFF)
		{
			framesdrawn = 0;
			fade = 0xFFFFFFFF;
			return;
		}
		fade -= 0x10000000;
		D3DXsprite->Draw(img, NULL, NULL, &vec, fade);
	}
	else D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}

//IncBoxesText
IncBoxesText::IncBoxesText(TextureStorage * ts, b2Vec2 pos)
{
	fade = 0xFFFFFFFF;
	position = pos;
	GetTextures(ts);
	SetWidthHeight();
}

void IncBoxesText::GetTextures(TextureStorage * ts)
{
	img = ts->GetTexture(TextureStorage::TexName::Text_IncBoxes);
}

void IncBoxesText::SetWidthHeight()
{
	width = 500;
	height = 100;
}

void IncBoxesText::SetVisited(bool value)
{
	if (!visited && value)
	{
		visited = value;
		framesdrawn = -1;
	}
	else
	{
		visited = value;
		framesdrawn = 0;
		fade = 0xFFFFFFFF;
	}
}

void IncBoxesText::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (visited && (framesdrawn == 0)) return;
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	if (visited)
	{
		if (fade == 0x0FFFFFFF)
		{
			framesdrawn = 0;
			fade = 0xFFFFFFFF;
			return;
		}
		fade -= 0x10000000;
		D3DXsprite->Draw(img, NULL, NULL, &vec, fade);
	}
	else D3DXsprite->Draw(img, NULL, NULL, &vec, 0xFFFFFFFF);
}

//LevitText
LevitText::LevitText(TextureStorage * ts, b2Vec2 pos)
{
	fade = 0xFFFFFFFF;
	position = pos;
	GetTextures(ts);
	SetWidthHeight();
}

void LevitText::GetTextures(TextureStorage * ts)
{
	first = ts->GetTexture(TextureStorage::TexName::Text_Levit1);
	second = ts->GetTexture(TextureStorage::TexName::Text_Levit2);
}

void LevitText::SetWidthHeight()
{
	if (visited)
	{
		width = 500;
		height = 128;
	}
	else
	{
		width = 420;
		height = 150;
	}
}

void LevitText::SetVisited(bool value)
{
	if (!visited && value)
	{
		visited = value;
		framesdrawn = -1;
	}
	else
	{
		visited = value;
		framesdrawn = 0;
		fade = 0xFFFFFFFF;
		SetWidthHeight();
	}
}

void LevitText::Draw(LPD3DXSPRITE D3DXsprite)
{
	if (!Game::ShouldIDraw(this)) return;
	D3DXVECTOR3 vec = Game::GetPosOnScreen(this);
	if (visited)
	{
		if (framesdrawn == 0) D3DXsprite->Draw(second, NULL, NULL, &vec, 0xFFFFFFFF);
		if (framesdrawn < 0)
		{
			if (fade == 0x0FFFFFFF)
			{
				framesdrawn = 1;
				return;
			}
			fade -= 0x10000000;
			D3DXsprite->Draw(first, NULL, NULL, &vec, fade);
			return;
		}
		if (framesdrawn > 0)
		{
			if (fade == 0xFFFFFFFF) framesdrawn = 0;
			else fade += 0x10000000;
			D3DXsprite->Draw(second, NULL, NULL, &vec, fade);
			return;
		}
	}
	else D3DXsprite->Draw(first, NULL, NULL, &vec, 0xFFFFFFFF);
}