#pragma once
#include "MoveBehavior.h"
#include <time.h>

class Player;

class CompMovement : public MoveBehavior
{
public:
	CompMovement(Player* obj = nullptr);
	~CompMovement();
	virtual void MoveTo(Direction_t);
	Direction_t MoveSmart(vector<std::shared_ptr<Bomb>> & bombs, vector<sf::Vector2f> & places, Board & board);
private:
	int calculateDistance(sf::Vector2f place1, sf::Vector2f place2);
	Direction_t getTheObjDirection(sf::Vector2f place, int opt);
	//float m_startMoveSmart;
	bool sameLine(sf::Vector2i place1, sf::Vector2i place2);
	Direction_t getAway(Bomb &, Board &);
	float timeTochange;
};

