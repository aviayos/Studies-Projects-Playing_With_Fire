#pragma once
#include "IScreen.h"

class Help1Screen : public IScreen
{
public:
	Help1Screen();
	void checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string& screenType, bool& clicked);
	~Help1Screen();
};

