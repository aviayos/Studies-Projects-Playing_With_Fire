#include "Fire.h"


Fire::Fire(Player_t owner, Style_t dir,int x, int y):m_stop(false),m_owner(owner),m_dir(dir)
{
	m_char.setOrigin(SQUARE_SIZE / 2, SQUARE_SIZE / 2);
	m_char.setTexture(Singleton::instance().getPic(Fire_t));
	m_char.setPosition(x * SQUARE_SIZE + LEFT_FRAME + SQUARE_SIZE / 2, y * SQUARE_SIZE + OTHER_FRAME + SQUARE_SIZE / 2);
}


Fire::~Fire()
{
}

void Fire::stopSpread()
{
	m_stop = true;
}

void Fire::draw(sf::RenderWindow & win)
{
	m_char.setTextureRect(sf::IntRect(m_dir*SQUARE_SIZE, m_owner * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE));
	win.draw(m_char);
}

bool Fire::toStop()
{
	return m_stop;
}
