#include "Objects.h"




Objects::Objects():
	m_stepChar(0)
{
	
}


Objects::~Objects()
{
}

void Objects::setPosition(sf::Vector2f pos)
{
	m_char.setPosition(pos);
}


sf::Vector2f Objects::getPosition()
{
	return m_char.getPosition();
}

void Objects::incStep()
{
	m_stepChar++;
}

void Objects::setPrePos(sf::Vector2f place)
{
	////LEFT_FRAME + SQUARE_SIZE + PLAYER_WIDTH / 2, OTHER_FRAME + SQUARE_SIZE + PLAYER_HEIGHT / 2;
	//place.x = (place.x-LEFT_FRAME) / SQUARE_SIZE * SQUARE_SIZE  + LEFT_FRAME;
	//place.y = (place.y / PLAYER_HEIGHT) * PLAYER_HEIGHT + PLAYER_HEIGHT / 2;
	m_pre_pos = place;
}

sf::FloatRect Objects::getCharFloatRect()
{
	return m_char.getGlobalBounds();
}

sf::Vector2f Objects::getPrePos()
{
	return m_pre_pos;
}

sf::Vector2i Objects::getPosOnBoard()
{
	int x = (m_char.getPosition().x - LEFT_FRAME) / SQUARE_SIZE;
	int y = (m_char.getPosition().y - OTHER_FRAME) / SQUARE_SIZE;

	return sf::Vector2i({ x,y });
}
