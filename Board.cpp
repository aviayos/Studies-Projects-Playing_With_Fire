#include "Board.h"

Board::Board()
{
	auto resize = [](vector<std::shared_ptr<Objects>>& line) {line.resize(WIDTH); };
	m_statics.resize(HEIGHT);
	std::for_each(m_statics.begin(), m_statics.end(), resize);
}


Board::~Board()
{
}

void Board::CreateFromFile(std::ifstream& file)
{
	char obj = ' ';
	std::string line;

	for (unsigned int y = 0; y < m_statics.size(); y++)
	{
		std::getline(file, line);
		for (unsigned int x = 0; x < line.size(); x++)
		{
			obj = line[x];
			m_statics[y][x] = std::move(Factory::create(obj));
			if (m_statics[y][x] != nullptr)
				m_statics[y][x].get()->setPosition(sf::Vector2f{ LEFT_FRAME + (x * STATIC_WIDTH) + (STATIC_WIDTH / 2) , OTHER_FRAME + (y * STATIC_HEIGHT) + (STATIC_HEIGHT / 2) });
		}
	}

}

void Board::draw(sf::RenderWindow & win)
{
	for (unsigned int y = 0; y < m_statics.size(); y++)
	{
		for (unsigned int x = 0; x < m_statics[y].size(); x++)
		{
			if (m_statics[y][x] != nullptr)
				m_statics[y][x].get()->draw(win);
		}
	}
}

Objects* Board::ObjAtPlace(sf::Vector2i place)
{
	if (place.x < WIDTH && place.x >= 0 && place.y < HEIGHT && place.y >= 0)
		return m_statics[place.y][place.x].get();
	return nullptr;
}


vector<sf::Vector2i> Board::getAllNeighbors(sf::Vector2i current)
{
	sf::Vector2i surrounding[8] = { { -1,-1 },{ -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 } };
	vector<sf::Vector2i> neighbors;

	for (int i = 0; i < 8; i++)
	{
		if (isValidPoint(current + surrounding[i]))
			neighbors.emplace_back(current + surrounding[i]);
	}
	return neighbors;
}

bool Board::isCleanPlace(sf::Vector2i place)
{
	if (place.x < WIDTH && place.x >= 0 && place.y < HEIGHT && place.y >=0 )
		return (m_statics[place.y][place.x] == nullptr);
	return false;
}

void Board::setObj(std::shared_ptr<Objects> obj, sf::Vector2f pos)
{
	if (obj != nullptr) {
		obj->setPosition(pos);

		sf::Vector2i place = obj->getPosOnBoard();

		if (isCleanPlace(obj->getPosOnBoard()))
		{
			m_statics[place.y][place.x] = obj;
		}
	}
}

void Board::delObjAtPlace(sf::Vector2i place)
{
	m_statics[place.y][place.x].reset();
}

int Board::GetX()
{
	return m_statics[0].size();
}

int Board::GetY()
{
	return m_statics.size();
}


bool Board::isValidPoint(sf::Vector2i coord)
{
	return (coord.x < m_statics[0].size() && coord.x >= 0 && coord.y < m_statics.size() && coord.y >= 0);
}