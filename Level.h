#pragma once
#include "Board.h"
#include <fstream>
#include <vector>
#include <string>

using std::vector;

class Level
{
public:
	Level(bool &);
	~Level();
	void CreateNewLevel(bool& keepRead);
	void draw(sf::RenderWindow& win);
	Board & getBoard();
	Objects * getObjAtPlace(sf::Vector2i place);
	void delObjAtPlace(sf::Vector2i);
	std::vector<sf::Vector2i> getNeighboor(sf::Vector2i place);
private:
	static int m_numOfLevels;
	Board m_board;
};

