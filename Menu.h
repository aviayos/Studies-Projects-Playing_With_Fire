#pragma once
#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Singleton.h"
#include "PlayersScreen.h"
#include "OpponentsScreen.h"
#include "LevelsScreen.h"
#include "IScreen.h"
#include "Help1Screen.h"
#include "Help2Screen.h"

//const float WIDTH_BOTTON = 264;
//const float HEIGHT_BOTTON = 40;


class Menu
{
public:
	Menu();
	void Action(sf::RenderWindow& win);
	~Menu();
private:
	std::map<std::string, std::unique_ptr<IScreen>> m_screens;
};
