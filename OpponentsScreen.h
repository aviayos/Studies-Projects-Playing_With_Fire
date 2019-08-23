#pragma once
#include "IScreen.h"
#include <iostream>

class OpponentsScreen : public IScreen
{
public:
	OpponentsScreen();
	~OpponentsScreen();
private:
	void checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string& screenType, bool& clicked);

};

