#ifdef _DEBUG

#pragma warning( disable : 4482 )

#include<Logger.h>
#include<Game.h>
#include<sstream>

std::string MovementToStr(std::string prefix, Movement m);

Logger<Game>::Logger(Game * t, LPDIRECT3DDEVICE9 device)
{
	owner = t;
	log = false;
	lasttime = GetTickCount();
	framesdrawn = 0;
	lastfps = 0;

	 // -MulDiv(16, 96, 72)
	D3DXCreateFont(device, 13, 0, 0, 0, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, "Lucida Console", &fontSmall);
	D3DXCreateFont(device, 18, 0, 0, 0, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, "Lucida Console", &fontBig);

	msgs = new std::queue<std::string>();
}

void Logger<Game>::Draw(LPDIRECT3DDEVICE9 device)
{
	if (!log)
	{
		while (!msgs->empty()) msgs->pop();
		return;
	}

	RECT textRect = {2, 2, 400, 20};  // top, left, WIDTH, HEIGHT
	std::string pmv1 = "player->playerKA->Actual: ";
	if (owner->player->playerKA->Actual->name == "") pmv1 += MovementToStr("", owner->player->playerKA->Actual->mv);
	else pmv1 += owner->player->playerKA->Actual->name;
	std::string pmv2 = MovementToStr("player->movement: ", owner->player->movement);
	std::stringstream ss1, ss2, ss3;
	ss1 << "Body: X: " << owner->player->pBodyX << ", Y: " << owner->player->pBodyY;
	ss2 << "Draw: X: " << owner->player->drawX << ", Y: " << owner->player->drawY;
	ss3 << "Friction: " << owner->player->body->GetFixtureList()->GetFriction();

	fontSmall->DrawText(NULL, pmv1.c_str(), -1, &textRect, DT_LEFT, D3DCOLOR_XRGB(0,255,0));
	textRect.top += 20;
	textRect.bottom += 20;
	fontSmall->DrawText(NULL, pmv2.c_str(), -1, &textRect, DT_LEFT, D3DCOLOR_XRGB(0,255,0));
	textRect.top += 20;
	textRect.bottom += 20;
	fontSmall->DrawText(NULL, ss1.str().c_str(), -1, &textRect, DT_LEFT, D3DCOLOR_XRGB(0,255,0));
	textRect.top += 20;
	textRect.bottom += 20;
	fontSmall->DrawText(NULL, ss2.str().c_str(), -1, &textRect, DT_LEFT, D3DCOLOR_XRGB(0,255,0));
	textRect.top += 20;
	textRect.bottom += 20;
	fontSmall->DrawText(NULL, ss3.str().c_str(), -1, &textRect, DT_LEFT, D3DCOLOR_XRGB(0,255,0));

	textRect.top = 2;
	textRect.left = owner->ScreenWidth - 120;
	textRect.right = owner->ScreenWidth;
	textRect.bottom = 800;
	while (!msgs->empty())
	{
		std::string msg = msgs->front();
		msgs->pop();
		fontSmall->DrawText(NULL, msg.c_str(), -1, &textRect, DT_LEFT, D3DCOLOR_XRGB(0,255,0));
		textRect.top += 20;
	}

	// FPS
	if (GetTickCount() - lasttime >= 1000)
	{
		lasttime = GetTickCount();
		lastfps = framesdrawn;
		framesdrawn = 0;
	}
	++framesdrawn;
	std::stringstream ssfps;
	ssfps << "FPS: " << lastfps;
	textRect.top = 100;
	fontBig->DrawText(NULL, ssfps.str().c_str(), -1, &textRect, DT_LEFT, D3DCOLOR_XRGB(255,0,0));
}

void Logger<Game>::LogMsg(const char * s, WPARAM k)
{
	std::stringstream ss;
	ss << s << k;
	msgs->push(ss.str());
}

std::string MovementToStr(std::string s, Movement m)
{
	switch (m)
	{
	case Movement::BuckL:
		s += "BuckL";
		return s;
	case Movement::BuckR:
		s += "BuckR";
		return s;
	case Movement::FallL:
		s += "FallL";
		return s;
	case Movement::FallR:
		s += "FallR";
		return s;
	case Movement::FlyL:
		s += "FlyL";
		return s;
	case Movement::FlyR:
		s += "FlyR";
		return s;
	case Movement::IdleL:
		s += "IdleL";
		return s;
	case Movement::IdleR:
		s += "IdleR";
		return s;
	case Movement::JumpL:
		s += "JumpL";
		return s;
	case Movement::JumpR:
		s += "JumpR";
		return s;
	case Movement::RunL:
		s += "RunL";
		return s;
	case Movement::RunR:
		s += "RunR";
		return s;
	case Movement::WalkL:
		s += "WalkL";
		return s;
	case Movement::WalkR:
		s += "WalkR";
		return s;
	case Movement::DashL:
		s += "DashL";
		return s;
	case Movement::DashR:
		s += "DashR";
		return s;
	}
	return "MISSINGSTR";
}

Logger<Game>::~Logger()
{
	fontSmall->Release();
	fontBig->Release();
	delete msgs;
}

#endif