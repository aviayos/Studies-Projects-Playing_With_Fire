#include "PlayersScreen.h"

PlayersScreen::PlayersScreen()
{
	sf::Text temp;
	temp.setFont(Singleton::instance().getFont());
	temp.setColor(sf::Color::Black);
	temp.setCharacterSize(15.f);

	unsigned int i = 0;
	m_background.setTexture(Singleton::instance().getPic(menu_background_t));
	m_buttons.resize(4);
	m_texts.resize(m_buttons.size());

	for (i = 0; i < 2; i++) {
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
	m_texts[0].setString("1 Player");
	m_texts[1].setString("2 Player");
	m_texts[2].setString("Instructions");
	m_texts[3].setString("Exit");



}

PlayersScreen::~PlayersScreen()
{
}

void PlayersScreen::checkClick(sf::RenderWindow& win, sf::Vector2f mouseCoords, std::string& screenType, bool& clicked)
{
	if (m_buttons[0].getGlobalBounds().contains(mouseCoords)) {
		m_numPlayers = 1;
		screenType = "OpponentsScreen";
	}
	else if (m_buttons[1].getGlobalBounds().contains(mouseCoords)) {
		m_numPlayers = 2;
		screenType = "OpponentsScreen";
	}
	else if (m_buttons[2].getGlobalBounds().contains(mouseCoords)) {
		screenType = "Help1Screen";
	}
	else if (m_buttons[3].getGlobalBounds().contains(mouseCoords))
		screenType = "Exit";
}

