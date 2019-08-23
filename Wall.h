#pragma once
#include "Objects.h"
#include "Factory.h"
#include <iostream>
#include "Singleton.h"

class Wall : public Objects
{
public:
	Wall();
	~Wall();
	virtual void draw(sf::RenderWindow& win) { win.draw(m_char); };
private:
	static bool m_registerit;
};


