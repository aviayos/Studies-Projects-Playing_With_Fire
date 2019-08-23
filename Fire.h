#pragma once
#include "Objects.h"
#include "Factory.h"
#include "Singleton.h"

enum Style_t { Mixed_t, Horizontal_t, Vertical_t
};

class Fire : public Objects
{
public:
	Fire(Player_t owner, Style_t dir,int x = 0, int y = 0);
	~Fire();
	void stopSpread();
	virtual void draw(sf::RenderWindow& win);
	bool toStop();
private:
	bool m_stop;
	Player_t m_owner;
	Style_t m_dir;

};