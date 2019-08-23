#pragma once
#include "Player.h"
#include "UserMovement.h"
#include "Factory.h"
#include <algorithm>
#include <functional>
#include "Wall.h"
#include "Level.h"
#include "Barrel.h"

class Wall;
class Barrel;

class UserPlayer : public Player
{
public:
	UserPlayer(int i, const int width, const int height);
	~UserPlayer(); 
	void getUserCommand(sf::Keyboard::Key);
private:
	std::map < sf::Keyboard::Key, std::function<void()>> m_orders;
	
};
