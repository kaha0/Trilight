#pragma warning( disable : 4482 )

#include<MessageWrapper.h>

MessageWrapper::MessageWrapper(Game * g)
{
	game = g;

	filter.insert(VK_F1);
	filter.insert(VK_ESCAPE);
	filter.insert(0x50);  // 'P'
	filter.insert(0x45);  // 'E'
	filter.insert(0x57);  // 'W'
}

void MessageWrapper::AddMessage(WPARAM key)
{
	if (filter.find(key) != filter.end())
	{
		game->KeyDown(key);
		return;
	}
	if (game->State == Game::GameState::Running)
	{
		switch (key)
		{
		case 0x41:  // A
			keys.insert(VK_LEFT);
			break;
		case 0x44:  // D
			keys.insert(VK_RIGHT);
			break;
		default:
			keys.insert(key);
			break;
		}
	}
	else game->KeyDown(key);
}

void MessageWrapper::RemoveMessage(WPARAM key)
{
	switch (key)
	{
	case 0x41:  // A
		keys.erase(VK_LEFT);
		game->KeyUp(VK_LEFT);
		break;
	case 0x44:  // D
		keys.erase(VK_RIGHT);
		game->KeyUp(VK_RIGHT);
		break;
	default:
		keys.erase(key);
		game->KeyUp(key);
		break;
	}
}

void MessageWrapper::Step()
{
	if (game->State == Game::GameState::Running)
	{
		for (std::set<WPARAM>::iterator it = keys.begin(); it != keys.end(); it++)
		{
			game->KeyDown(*it);
		}
	}
	else
	{
		if (!keys.empty()) keys.clear();
	}
}