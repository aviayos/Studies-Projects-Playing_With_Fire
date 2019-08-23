#include "Menu.h"



Menu::Menu()
{
	m_screens.emplace("PlayersScreen",std::make_unique<PlayersScreen>());
	m_screens["OpponentsScreen"] = std::make_unique<OpponentsScreen>();
	m_screens["LevelsScreen"] = std::make_unique<LevelsScreen>();
	m_screens["Help1Screen"] = std::make_unique<Help1Screen>();
	m_screens["Help2Screen"] = std::make_unique<Help2Screen>();

}


void Menu::Action(sf::RenderWindow& win)
{
	
	std::string screenType = "PlayersScreen";
	while (screenType != "Exit")
	{
		m_screens[screenType].get()->draw(win);
		win.display();
		m_screens[screenType].get()->HandleEvent(win,screenType);
		win.clear();
	}
}

Menu::~Menu()
{
}
