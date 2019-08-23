#pragma once
#include <SFML/Graphics.hpp>
#include "Singleton.h"

const float WIDTH_BUTTON = 264;
const float HEIGHT_BUTTON = 40;
const float HEIGHT_BUTTON_START = 400;
const float WIDTH_BUTTON_START = 500;
const float SPACE = 10;

class IScreen
{

public:
	IScreen();
	void HandleEvent(sf::RenderWindow& win, std::string& screenType);
	void draw(sf::RenderWindow& win);
	virtual ~IScreen();


protected:
	sf::Sprite m_background;
	std::vector<sf::Sprite> m_buttons;
	std::vector<sf::Text> m_texts;
	static int m_numPlayers;
	static int m_numOpponents;
	static int m_numLevel;
	virtual void checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string& screenType, bool& clicked) = 0;

};
