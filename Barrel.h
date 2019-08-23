#pragma once
#include "Objects.h"
#include "Factory.h"
#include "Singleton.h"

class Barrel : public Objects
{
public:
	Barrel();
	~Barrel();
	std::shared_ptr<Objects> randGift();
	virtual void draw(sf::RenderWindow& win) { win.draw(m_char); };

private:
	static bool m_registerit;
};



