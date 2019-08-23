#include "LevelsScreen.h"



LevelsScreen::LevelsScreen()
{
	sf::Text temp;
	temp.setFont(Singleton::instance().getFont());
	temp.setColor(sf::Color::Black);
	temp.setCharacterSize(15.f);

	m_background.setTexture(Singleton::instance().getPic(menu_background_t));
	unsigned int i = 0;
	m_buttons.resize(5);
	m_texts.resize(m_buttons.size());
	for (i = 0; i < 4; i++) {
		m_buttons[i].setTexture(Singleton::instance().getPic(Menu_Buttons1_t));
		m_buttons[i].setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON, HEIGHT_BUTTON));
		m_buttons[i].setPosition(WIDTH_BUTTON_START - WIDTH_BUTTON / 4, HEIGHT_BUTTON_START + HEIGHT_BUTTON * i + SPACE * i);
		temp.setPosition(WIDTH_BUTTON_START - WIDTH_BUTTON / 4 + WIDTH_BUTTON / 4, HEIGHT_BUTTON_START + HEIGHT_BUTTON * i + HEIGHT_BUTTON / 4 + SPACE * i);
		m_texts[i] = temp;
	}
	for (; i < 5; i++) {
		m_buttons[i].setTexture(Singleton::instance().getPic(Menu_Buttons2_t));
		m_buttons[i].setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON, HEIGHT_BUTTON));
		m_buttons[i].setPosition(WIDTH_BUTTON_START - WIDTH_BUTTON / 4, HEIGHT_BUTTON_START + HEIGHT_BUTTON * i + SPACE * i);
		temp.setPosition(WIDTH_BUTTON_START - WIDTH_BUTTON / 4 + WIDTH_BUTTON / 4, HEIGHT_BUTTON_START + HEIGHT_BUTTON * i + HEIGHT_BUTTON / 4 + SPACE * i);
		m_texts[i] = temp;
	}
	m_texts[0].setString("Level 1");
	m_texts[1].setString("Level 2");
	m_texts[2].setString("Level 3");
	m_texts[3].setString("Level 4");
	m_texts[4].setString("Back");

}

LevelsScreen::~LevelsScreen()
{
}

void LevelsScreen::checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string & screenType, bool & clicked)
{
	if (m_buttons[0].getGlobalBounds().contains(mouseCoords))
	{
		m_numLevel = 1;
		clicked = true;
	}
	else if (m_buttons[1].getGlobalBounds().contains(mouseCoords))
	{
		m_numLevel = 2;
		screenType = "LevelsScreen";
		clicked = true;
	}
	else if (m_buttons[2].getGlobalBounds().contains(mouseCoords))
	{
		m_numLevel = 3;
		screenType = "LevelsScreen";
		clicked = true;
	}
	else if (m_buttons[3].getGlobalBounds().contains(mouseCoords))
	{
		m_numLevel = 4;
		screenType = "LevelsScreen";
		clicked = true;
	}

	if (clicked)
	{
		Controller controller;
		controller.runGame(win, m_numPlayers, m_numOpponents, m_numLevel);
		screenType = "PlayersScreen";
	}

}
