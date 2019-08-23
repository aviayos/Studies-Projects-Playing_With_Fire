#pragma once
#include "Gifts.h"
#include "Factory.h"

class KickGift : public Gifts
{
public:
	KickGift();
	~KickGift();
private:
	static bool m_registerit;
};

