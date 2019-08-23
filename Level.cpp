#include "Level.h"

int Level::m_numOfLevels = 1;

Level::Level(bool &keepRead)
{
	std::ifstream file;
	file.open("Levels//Level" + std::to_string(m_numOfLevels) + ".txt");//exception
	if (file.is_open())
	{
		m_board.CreateFromFile(file);
		m_numOfLevels++;
		file.close();
	}
	else
		keepRead = false;
}


Level::~Level()
{
	m_numOfLevels = 1;
}

void Level::CreateNewLevel(bool & keepRead)
{
	/*std::ifstream file;
	try
	{
		file.open("Levels//Level" + std::to_string(m_numOfLevels));//exception
		m_board.CreateFromFile(file);
		m_numOfLevels++;
	}
	catch (const std::exception& s)
	{
		keepRead = false;
	}*/
}

void Level::draw(sf::RenderWindow & win)
{
	m_board.draw(win);
}

Board & Level::getBoard()
{
	return m_board;
}

Objects * Level::getObjAtPlace(sf::Vector2i place)
{
	return m_board.ObjAtPlace(place);
}

void Level::delObjAtPlace(sf::Vector2i place)
{
	m_board.delObjAtPlace(place);
}

std::vector<sf::Vector2i> Level::getNeighboor(sf::Vector2i place)
{
	return m_board.getAllNeighbors(place);
}



