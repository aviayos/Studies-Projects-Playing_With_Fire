#pragma once
#include "IScreen.h"
#include "Controller.h"

class LevelsScreen : public IScreen
{
public:
	LevelsScreen();
	~LevelsScreen();

private:
	void checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string& screenType, bool& clicked);
};

