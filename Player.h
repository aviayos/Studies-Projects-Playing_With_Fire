#pragma once
#include "Objects.h"
#include "Singleton.h"
#include "MoveBehavior.h"
#include "Bomb.h"
#include <stack>
const int NUM_STEPS = 3;
const int MAX_RADIUS = 8;
const float MAX_SPEED = 0.7f;

class Board;

class Player : public Objects
{
public:
	Player(int i=0,const int width=15, const int height=13);
	virtual ~Player();
	void draw(sf::RenderWindow & win);
	void decLives();
	void setDir(Direction_t);
	void incBombs();
	void DecBombs();
	void incRadius();
	void incSpeed();
	int getLives();
	//void ActivateAttack(Board&);
	std::shared_ptr<Bomb> createBomb();
	int availableBombs();
	bool throwAble();
	void activateThrow();
	void activateKick();
	int getRad();
	float getSpeed();
	Player_t getType() { return m_type; }
	Direction_t getDirection() { return m_dir; }

protected:
	int m_totalBombs;
	int m_usedBombs;
	int m_bombRadius;
	float m_speed;
	int m_lives;
	bool m_thorwBomb;
	bool m_kickBomb;
	Player_t m_type;
	std::unique_ptr<MoveBehavior> m_move;
//	std::unique_ptr<AttackBehavior> m_attack;
	Direction_t m_dir;
	sf::Clock clock;
};

