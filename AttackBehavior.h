#pragma once
#include "Objects.h"
#include "Board.h"

class AttackBehavior
{
public:
	AttackBehavior(Player *player = nullptr);
	~AttackBehavior();
	virtual std::shared_ptr<Bomb> PerformAttack(Board &) = 0 ;

protected:
	Player & m_obj;
};

