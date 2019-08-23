#include "Help2Screen.h"



Help2Screen::Help2Screen()
{
	m_background.setTexture(Singleton::instance().getPic(Help2_t));

	sf::Text text;
	sf::Sprite button;

	text.setFont(Singleton::instance().getFont());
	text.setColor(sf::Color::Black);
	text.setCharacterSize(15.f);
	text.setPosition(1085 / 3 + WIDTH_BUTTON / 4, 810 - 2 * HEIGHT_BUTTON + HEIGHT_BUTTON / 4);
	text.setString("Play Now");

	button.setPosition(1085 / 3, 810 - 2 * HEIGHT_BUTTON);
	button.setTexture(Singleton::instance().getPic(Menu_Buttons1_t));
	button.setTextureRect(sf::IntRect(0, 0, WIDTH_BUTTON, HEIGHT_BUTTON));

	m_texts.push_back(text);
	m_buttons.push_back(button);


}

void Help2Screen::checkClick(sf::RenderWindow & win, sf::Vector2f mouseCoords, std::string & screenType, bool & clicked)
{
	if (m_buttons[0].getGlobalBounds().contains(mouseCoords)) {
		screenType = "PlayersScreen";
	}
}
Help2Screen::~Help2Screen()
{
}
