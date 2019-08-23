#include "Gifts.h"



Gifts::Gifts() :m_change(0), m_transparency(0)
{

	m_char.setTexture(Singleton::instance().getPic(Gifts_t));
	m_background.setTexture(Singleton::instance().getPic(B_Gifts_t));

	m_char.setOrigin(SQUARE_SIZE / 2, SQUARE_SIZE / 2);
	m_background.setOrigin(SQUARE_SIZE / 2, SQUARE_SIZE / 2);


}

void Gifts::draw(sf::RenderWindow & win)
{
	m_background.setPosition(m_char.getPosition());
	m_char.setTextureRect(sf::IntRect(0, m_type*SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE));
	m_change += m_timer.restart().asSeconds();

	if (m_change > 0.001)
	{
		m_transparency++;
		m_background.setColor(sf::Color(255, 255, 255, m_transparency));
		m_change = 0;

	}

	win.draw(m_background);
	win.draw(m_char);
}


Gifts::~Gifts()
{
}

