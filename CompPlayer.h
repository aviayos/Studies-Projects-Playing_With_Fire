#pragma once
#include "CompMovement.h"
#include "Player.h"
#include "Factory.h"
#include <vector> 


class CompPlayer : public Player
{
public:
	CompPlayer(int i, const int width, const int height);
	~CompPlayer();
	void setRadius(int r);
	void move(Direction_t);
	Direction_t getDirFromSmart(vector<std::shared_ptr<Bomb>> & bombs, vector<sf::Vector2f> & places, Board &);
private:
	int m_radius;
	std::vector<sf::Vector2f> m_playerplace;
};

