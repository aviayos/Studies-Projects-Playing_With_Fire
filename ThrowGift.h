#pragma once
#include "Gifts.h"
#include "Factory.h"

class ThrowGift : public Gifts
{
public:
	ThrowGift();
	~ThrowGift();
private:
	static bool m_registerit;
};

