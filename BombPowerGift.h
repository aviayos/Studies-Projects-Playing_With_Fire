#pragma once
#include "Gifts.h"
#include "Factory.h"

class BombPowerGift : public Gifts
{
public:
	BombPowerGift();
	~BombPowerGift();
private:
	static bool m_registerit;
};


