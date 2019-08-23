#include "Wall.h"

bool Wall::m_registerit = Factory::registerIt('w',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<Wall>(); });

Wall::Wall()
{
	m_char.setOrigin(SQUARE_SIZE / 2, SQUARE_SIZE / 2);
	m_char.setTexture(Singleton::instance().getPic(blocks_t));
	m_char.setTextureRect(sf::IntRect(0, 0, SQUARE_SIZE, SQUARE_SIZE));
}

Wall::~Wall()
{
}


