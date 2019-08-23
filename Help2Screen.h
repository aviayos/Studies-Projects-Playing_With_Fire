#pragma once
#include "IScreen.h"

class Help2Screen : public IScreen
{
public:
	Help2Screen();
	void checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string& screenType, bool& clicked);
	~Help2Screen();
};

