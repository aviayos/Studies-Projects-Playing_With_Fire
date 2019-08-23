#pragma once
#include "Objects.h"
#include "Factory.h"

class Teleport : public Objects
{
public:
	Teleport();
	~Teleport();
	virtual void draw(sf::RenderWindow& win) { win.draw(m_char); };
private:
	static bool m_registerit;
};
