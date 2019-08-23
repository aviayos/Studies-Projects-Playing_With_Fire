#pragma once
#include <vector>
#include "Objects.h"
#include <memory>
#include <fstream>
#include <algorithm>
#include "Factory.h"
#include <istream>
#include "Bomb.h"

const int WIDTH = 15;
const int HEIGHT = 13;
const float STATIC_WIDTH = 60;
const float STATIC_HEIGHT = 60;

//class Objects;

using std::vector;

class Board
{
public:
	Board();
	~Board();
	void CreateFromFile(std::ifstream& file);
	void draw(sf::RenderWindow& win);
	Objects * ObjAtPlace(sf::Vector2i place);
	vector<sf::Vector2i> getAllNeighbors(sf::Vector2i current);
	bool isCleanPlace(sf::Vector2i);
	void setObj(std::shared_ptr<Objects> obj, sf::Vector2f pos);
	void delObjAtPlace(sf::Vector2i);
	int GetX();
	int GetY();
private:
	vector<vector<std::shared_ptr<Objects>>> m_statics;//וקטור שמחזיק אובייקטים סטטיים
	bool isValidPoint(sf::Vector2i coord);
};

