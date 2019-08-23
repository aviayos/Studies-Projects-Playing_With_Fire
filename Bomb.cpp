#include "Bomb.h"
#include "Level.h"
#include "CollisionHandling.h"
#include "Player.h"

bool Bomb::m_registerit = Factory::registerIt('b',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<Bomb>(); });

Bomb::Bomb() :timeToChange(0), timeToExplode(0)
{

}

Bomb::Bomb(Player_t holder, sf::Vector2i place, int radius)
	: m_radius(radius), m_holder(holder), timeToChange(0), timeToExplode(0), m_inThrow(false), m_fireCreated(false)
{
	m_char.setOrigin(SQUARE_SIZE / 2, SQUARE_SIZE / 2);
	m_char.setTexture(Singleton::instance().getPic(Bombs_t));
	m_char.setPosition(place.x * SQUARE_SIZE + LEFT_FRAME + SQUARE_SIZE / 2, place.y * SQUARE_SIZE + OTHER_FRAME + SQUARE_SIZE / 2);
	m_startPos = m_char.getPosition();
	timeToExplode = m_timer.getElapsedTime().asSeconds();
	timeToChange = m_timer.getElapsedTime().asSeconds();
}


Bomb::~Bomb()
{
}

void Bomb::draw(sf::RenderWindow & win)
{


	if (m_timer.getElapsedTime().asSeconds() - timeToExplode > 2)
	{
		if (m_timer.getElapsedTime().asSeconds() - timeToExplode > 4)//הפצצה התפוצצה
		{
			for (int i = 0; i < m_fires.size(); i++)
				m_fires[i]->draw(win);
			

		}
		else//הפצצה עדיין לא התפוצצה
			m_stepChar = 2;
		

	}
	else if (m_timer.getElapsedTime().asSeconds() - timeToChange > 0.5)
	{
		if (m_stepChar == 0)
			m_stepChar = 1;
		else
			m_stepChar = 0;

		timeToChange = m_timer.getElapsedTime().asSeconds();
	}

	if (!m_fireCreated)
	{
		m_char.setTextureRect(sf::IntRect(m_stepChar*SQUARE_SIZE, m_holder * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE));
		win.draw(m_char);
	}
	
}

void Bomb::throwBomb(Direction_t dir)
{
	if (m_inThrow)
	{
		if (m_timer.getElapsedTime().asSeconds() - throwTimer > 3)
		{
			m_inThrow = false;
		}

	}

}

void Bomb::move(Board& board)
{
	int x = std::abs((m_char.getPosition().x - m_startPos.x) / SQUARE_SIZE);
	int y = std::abs((m_char.getPosition().y - m_startPos.y) / SQUARE_SIZE);
	sf::Vector2i pl = getPosOnBoard();

	if (sqrt(pow(x, 2.0) + std::pow(y, 2.0)) > 2)
	{
		if (!checkOutOfBounds(board)) {
			if (board.isCleanPlace(pl)) {
				m_inThrow = false;
				m_char.setPosition(pl.x * SQUARE_SIZE + LEFT_FRAME + SQUARE_SIZE / 2, pl.y * SQUARE_SIZE + OTHER_FRAME + SQUARE_SIZE / 2);
				m_startPos = m_char.getPosition();
			}
		}
	}
	if (m_inThrow)
	{
		sf::Vector2f new_pos = getPosition();

		switch (m_bombDir)
		{

		case Right_t: new_pos += {0.8f, 0};
					  break;
		case Left_t: new_pos += {-0.8f, 0};
					 break;
		case Up_t: new_pos += {0, -0.8f};
				   break;
		case Down_t: new_pos += {0, 0.8f};
					 break;

		}
		m_char.setPosition(new_pos);
	}
	/*if()
	else if()*/
}

void Bomb::setThrow(Direction_t dir)
{
	m_inThrow = true;
	m_bombDir = dir;
	throwTimer = m_timer.getElapsedTime().asSeconds();
}

bool Bomb::exploded()
{
	return (m_timer.getElapsedTime().asSeconds() - timeToExplode > 4 );
}

Player_t Bomb::getHolder()
{
	return m_holder;
}

bool Bomb::timeToClean()
{
	return (m_timer.getElapsedTime().asSeconds() - timeToExplode > 6);
}

/*float Bomb::getTime()
{
	
}*/

void Bomb::createFire(Level & level)
{
	m_fireCreated = true;
	int x = getPosOnBoard().x;
	int y = getPosOnBoard().y;
	
	m_fires.emplace_back(std::make_shared<Fire>(m_holder,Mixed_t,x, y));

	while (y < getPosOnBoard().y + m_radius)//down screen
	{
		if (y >= 0 && y < level.getBoard().GetY())
		{
			if (sf::Vector2i{ x,y } == getPosOnBoard()) {
				y++;
				continue;
			}
			
			std::shared_ptr<Fire> f = std::make_shared<Fire>(m_holder,Vertical_t,x,y);
			Objects * obj = level.getBoard().ObjAtPlace(f->getPosOnBoard());
			
			if (!processCollision(*f, *obj, level))
				m_fires.emplace_back(f);
			
			if (f->toStop())
				break;
		}
		y++;
	}
	y = getPosOnBoard().y;
	while (x < getPosOnBoard().x + m_radius)//right screen
	{
		if (x >= 0 && x < level.getBoard().GetX())
		{
			if (sf::Vector2i{ x,y } == getPosOnBoard()) {
				x++;
				continue;
			}
			std::shared_ptr<Fire> f = std::make_shared<Fire>(m_holder,Horizontal_t,x,y);
			Objects * obj = level.getBoard().ObjAtPlace(f->getPosOnBoard());

			if (!processCollision(*f, *obj, level))
				m_fires.emplace_back(f);

			if (f->toStop())
				break;
		}
		x++;
	}
	x = getPosOnBoard().x;
	while (x > getPosOnBoard().x - m_radius)
	{
		if (x >= 0 && x < level.getBoard().GetX())
		{
			if (sf::Vector2i{ x,y } == getPosOnBoard()) {
				x--;
				continue;
			}
			std::shared_ptr<Fire> f = std::make_shared<Fire>(m_holder,Horizontal_t,x,y);
			Objects * obj = level.getBoard().ObjAtPlace(f->getPosOnBoard());

			if (!processCollision(*f, *obj, level))
				m_fires.emplace_back(f);

			if (f->toStop())
				break;
		}
		x--;
	}
	x = getPosOnBoard().x;
	while (y > getPosOnBoard().y - m_radius)
	{
		if (y >= 0 && y < level.getBoard().GetY())
		{
			if (sf::Vector2i{ x,y } == getPosOnBoard()) {
				y--;
				continue;
			}

			std::shared_ptr<Fire> f = std::make_shared<Fire>(m_holder,Vertical_t,x,y);
			Objects * obj = level.getBoard().ObjAtPlace(f->getPosOnBoard());

			if (!processCollision(*f, *obj, level))
				m_fires.emplace_back(f);

			if (f->toStop())
				break;
		}
		y--;
	}
}

bool Bomb::fireIsCreate()
{
	return m_fireCreated;
}

bool Bomb::explodeOn(Player & player, Level & level)
{
	bool hurt = false;
	for (int i = 0; i < m_fires.size(); i++) {
		if (processCollision(player, *m_fires[i], level) && !alreadyWounded(player.getType()))
		{
			hurt = true;
			m_wounded.emplace_back(player.getType());
		}
	}
	return hurt;
}

bool Bomb::alreadyWounded(Player_t player_type)
{
	for (int i = 0; i < m_wounded.size(); i++)
	{
		if (m_wounded[i] == player_type)
			return true;
	}
	return false;
}

int Bomb::getRad()
{
	return m_radius;
}

bool Bomb::checkOutOfBounds(Board & board)
{

	if (board.GetX() <= getPosOnBoard().x)
	{
		m_char.setPosition(31.f + LEFT_FRAME, m_char.getPosition().y);//לבדוק אם ניתן לתקן
		return true;
	}
	if (board.GetY() <= getPosOnBoard().y)
	{
		m_char.setPosition(m_char.getPosition().x, 31.f + OTHER_FRAME);//לבדוק אם ניתן לתקן
		return true;
	}
	if (0 > getPosOnBoard().x)//check
	{
		m_char.setPosition(LEFT_FRAME + SQUARE_SIZE * (board.GetX() - 1), m_char.getPosition().y);
		return true;
	}
	if (0 > getPosOnBoard().y)
	{
		m_char.setPosition(m_char.getPosition().x, OTHER_FRAME + SQUARE_SIZE * (board.GetY() - 1));
		return true;
	}

	return false;
}

/*void Bomb::fireSpread(Direction_t dir, Level & level, int start)
{
	int x = getPosOnBoard().x;
	int y = getPosOnBoard().y;

	while()
}*/
