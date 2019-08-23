#pragma once
//design pattern of strategy
#include <SFML/Graphics.hpp>
#include "Objects.h"
#include "Level.h"
#include <memory>
#include <vector>
#include "CollisionHandling.h"

class Player;

class MoveBehavior
{
public:
	MoveBehavior(Player *player = nullptr);
	~MoveBehavior();
	virtual void MoveTo(Direction_t) = 0;
	virtual Direction_t MoveSmart(vector<std::shared_ptr<Bomb>> &, vector<sf::Vector2f> & , Board &) = 0;
protected:
	Player & m_obj;
	sf::Clock clock;
};

