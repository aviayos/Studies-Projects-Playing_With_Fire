#include "Help1Screen.h"



Help1Screen::Help1Screen()
{
	sf::Text temp;
	temp.setFont(Singleton::instance().getFont());
	temp.setColor(sf::Color::Black);
	temp.setCharacterSize(15.f);
	m_background.setTexture(Singleton::instance().getPic(Help1_t));

	m_buttons.resize(2);
	m_texts.resize(2);
	m_buttons[0].setTexture(Singleton::instance().getPic(Menu_Buttons1_t));
	m_buttons[0].setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON, HEIGHT_BUTTON));
	m_buttons[0].setPosition(1085 / 3, 810 - 2 * HEIGHT_BUTTON);
	temp.setPosition(1085 / 3 + WIDTH_BUTTON / 4, 810 - 2 * HEIGHT_BUTTON + HEIGHT_BUTTON / 4);
	m_texts[0] = temp;

	m_buttons[1].setTexture(Singleton::instance().getPic(Menu_Buttons2_t));
	m_buttons[1].setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON, HEIGHT_BUTTON));
	m_buttons[1].setPosition(1085 / 3 + 1.5*WIDTH_BUTTON, 810 - 2 * HEIGHT_BUTTON);
	temp.setPosition(1085 / 3 + 1.5*WIDTH_BUTTON + WIDTH_BUTTON / 4, 810 - 2 * HEIGHT_BUTTON + HEIGHT_BUTTON / 4);
	m_texts[1] = temp;

	m_texts[0].setString("Play Now");
	m_texts[1].setString("Next Page");




}

void Help1Screen::checkClick(sf::RenderWindow & win, sf::Vector2f mouseCoords, std::string & screenType, bool & clicked)
{
	if (m_buttons[0].getGlobalBounds().contains(mouseCoords)) {
		screenType = "PlayersScreen";
	}
	else if (m_buttons[1].getGlobalBounds().contains(mouseCoords)) {
		screenType = "Help2Screen";
	}
}


Help1Screen::~Help1Screen()
{
}
