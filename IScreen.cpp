#include "IScreen.h"


int IScreen::m_numLevel = 0;
int IScreen::m_numPlayers = 0;
int IScreen::m_numOpponents = 0;

IScreen::IScreen()
{
	m_numLevel = 0;
}

void IScreen::HandleEvent(sf::RenderWindow & win, std::string & screenType)
{
	bool clicked = false;
	sf::Vector2f mouseCoords;
	sf::Event user_event;
	while (win.pollEvent(user_event) && !clicked)
	{
		switch (user_event.type)
		{
		case sf::Event::MouseButtonPressed:
		{
			mouseCoords.x = (float)user_event.mouseButton.x;
			mouseCoords.y = (float)user_event.mouseButton.y;
			checkClick(win, mouseCoords, screenType, clicked);
			break;
		}
		}



	}
}

void IScreen::draw(sf::RenderWindow & win)
{
	win.draw(m_background);

	for (unsigned int i = 0; i < m_buttons.size(); i++)
	{
		win.draw(m_buttons[i]);
		win.draw(m_texts[i]);
	}
}

IScreen::~IScreen()
{
}
