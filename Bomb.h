#pragma once
#include "Objects.h"
#include "Factory.h"
#include "Singleton.h"
#include <cmath>
#include "Fire.h"

class Board;
class Level;
class Player;

class Bomb : public Objects
{
public:
	Bomb();
	Bomb(Player_t holder, sf::Vector2i place, int radius = 2);
	~Bomb();
	virtual void draw(sf::RenderWindow& win);
	///bool canThrow(Player_t);
	void throwBomb(Direction_t dir);
	void move(Board&);
	void setThrow(Direction_t dir);
	bool exploded();
	Player_t getHolder();
	bool timeToClean();
	void createFire(Level &);
	bool fireIsCreate();
	bool explodeOn(Player &, Level & level);
	bool alreadyWounded(Player_t);
	int getRad();
private:
	bool checkOutOfBounds(Board &);
	static bool m_registerit;
	int m_radius;
	sf::Vector2f m_startPos;
	Player_t m_holder;
	sf::Clock m_timer;
	float timeToChange;
	float timeToExplode;
	float throwTimer;
	Direction_t m_bombDir;
	bool m_inThrow;
	std::vector<std::shared_ptr<Fire>> m_fires;
	bool m_fireCreated;
	std::vector<Player_t> m_wounded;

};

