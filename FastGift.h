#pragma once
#include "Gifts.h"
#include "Factory.h"

class FastGift : public Gifts
{
public:
	FastGift();
	~FastGift();
private:
	static bool m_registerit;
};


