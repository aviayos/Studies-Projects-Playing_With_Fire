#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

const float PLAYER_WIDTH = 50;
const float PLAYER_HEIGHT = 60;
const float SQUARE_SIZE = 60;
const float LEFT_FRAME = 168;
const float OTHER_FRAME = 13;

enum Player_t { Blue_t, Red_t, Green_t, Purple_t };
enum Direction_t { Right_t, Down_t, Up_t, Left_t };

class Objects
{
public:
	Objects();
	~Objects();
	void setPosition(sf::Vector2f pos);
	virtual void draw(sf::RenderWindow& win)=0;
	sf::Vector2f getPosition();
	void incStep();
	void setPrePos(sf::Vector2f place);
	sf::FloatRect getCharFloatRect();
	sf::Vector2f getPrePos();
	sf::Vector2i getPosOnBoard();
protected:
	sf::Sprite m_char;
	int m_stepChar;
	sf::Vector2f m_pre_pos;
};

