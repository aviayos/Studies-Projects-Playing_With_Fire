#pragma once
#include "IScreen.h"
class PlayersScreen :public IScreen
{
public:
	PlayersScreen();
	void checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string& screenType, bool& clicked);
	~PlayersScreen();
};

