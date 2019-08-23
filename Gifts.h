#pragma once
#include "Objects.h"
#include "Singleton.h"
#include "Factory.h"

enum PowerUps_t { Bomb_t, Lightning_t, Speed_t, Kick_t, Throw_t };

class Gifts : public Objects
{
public:
	Gifts();
	void draw(sf::RenderWindow& win);
	~Gifts();
protected:
	PowerUps_t m_type;
	sf::Clock m_timer;
	float m_change;
	int m_transparency;
	sf::Sprite m_background;
	

};

