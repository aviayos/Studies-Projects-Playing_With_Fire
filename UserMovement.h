#pragma once
#include "MoveBehavior.h"

class Player;

class UserMovement : public MoveBehavior
{
public:
	UserMovement(Player *p = nullptr);
	~UserMovement();
	virtual void MoveTo(Direction_t);
	Direction_t MoveSmart(vector<std::shared_ptr<Bomb>> & bombs, vector<sf::Vector2f> & places, Board &) { return Up_t; };
private:
	


};

