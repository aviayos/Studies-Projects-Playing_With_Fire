#pragma once
#include "Gifts.h"
#include "Factory.h"

class BombGift : public Gifts
{
public:
	BombGift();
	~BombGift();
private:
	static bool m_registerit;
};
