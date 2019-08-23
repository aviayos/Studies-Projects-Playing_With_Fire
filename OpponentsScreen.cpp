#include "OpponentsScreen.h"



OpponentsScreen::OpponentsScreen()
{
	sf::Text temp;
	temp.setFont(Singleton::instance().getFont());
	temp.setColor(sf::Color::Black);
	temp.setCharacterSize(15.f);

	m_background.setTexture(Singleton::instance().getPic(menu_background_t));
	unsigned int i = 0;
	m_background.setTexture(Singleton::instance().getPic(menu_background_t));
	m_buttons.resize(4);
	m_texts.resize(m_buttons.size());

	for (i = 0; i < 3; i++) {
		m_buttons[i].setTexture(Singleton::instance().getPic(Menu_Buttons1_t));
		m_buttons[i].setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON, HEIGHT_BUTTON));
		m_buttons[i].setPosition(WIDTH_BUTTON_START - WIDTH_BUTTON / 4, HEIGHT_BUTTON_START + HEIGHT_BUTTON * i + SPACE * i);
		temp.setPosition(WIDTH_BUTTON_START - WIDTH_BUTTON / 4 + WIDTH_BUTTON / 4, HEIGHT_BUTTON_START + HEIGHT_BUTTON * i + HEIGHT_BUTTON / 4 + SPACE * i);
		m_texts[i] = temp;
	}
	for (; i < 4; i++) {
		m_buttons[i].setTexture(Singleton::instance().getPic(Menu_Buttons2_t));
		m_buttons[i].setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON, HEIGHT_BUTTON));
		m_buttons[i].setPosition(WIDTH_BUTTON_START - WIDTH_BUTTON / 4, HEIGHT_BUTTON_START + HEIGHT_BUTTON * i + SPACE * i);
		temp.setPosition(WIDTH_BUTTON_START - WIDTH_BUTTON / 4 + WIDTH_BUTTON / 4, HEIGHT_BUTTON_START + HEIGHT_BUTTON * i + HEIGHT_BUTTON / 4 + SPACE * i);
		m_texts[i] = temp;
	}
	m_texts[0].setString("1 Oponnent");
	m_texts[1].setString("2 Oponnents");
	m_texts[2].setString("3 Oponnents");
	m_texts[3].setString("Back");
}

OpponentsScreen::~OpponentsScreen()
{
}

void OpponentsScreen::checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string& screenType, bool& clicked)
{
	if (m_buttons[0].getGlobalBounds().contains(mouseCoords))
	{
		m_numOpponents = 1;
		screenType = "LevelsScreen";
		//	clicked = true;
	}
	else if (m_buttons[1].getGlobalBounds().contains(mouseCoords))
	{
		m_numOpponents = 2;
		screenType = "LevelsScreen";
		//clicked = true;
	}
	else if (m_buttons[2].getGlobalBounds().contains(mouseCoords))
	{
		m_numOpponents = 3;
		screenType = "LevelsScreen";
		//clicked = true;
	}
	else if (m_buttons[3].getGlobalBounds().contains(mouseCoords))
	{
		m_numOpponents = 3;
		screenType = "PlayersScreen";
	}
}