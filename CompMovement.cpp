#include "CompMovement.h"
#include "Player.h"



CompMovement::CompMovement(Player * obj) : MoveBehavior::MoveBehavior(obj)
{
	timeTochange = clock.getElapsedTime().asSeconds();
	
}

CompMovement::~CompMovement()
{
	
}

void CompMovement::MoveTo(Direction_t dir)
{
	float speed = m_obj.getSpeed();
	sf::Vector2f new_pos = m_obj.getPosition();
	switch (dir)
	{
	case Right_t: new_pos += {speed, 0};
				  break;
	case Left_t: new_pos += {-speed, 0};
				 break;
	case Up_t: new_pos += {0, -speed};
			   break;
	case Down_t: new_pos += {0, speed};
				 break;
	}
	
	m_obj.setPosition(new_pos);
	if (clock.getElapsedTime().asSeconds() > 0.2f) {
		m_obj.incStep();
		clock.restart();
	}
}


Direction_t CompMovement::MoveSmart(vector<std::shared_ptr<Bomb>> & bombs, vector<sf::Vector2f> & places, Board & board)
{
	bool chase = true;
	static int factor = 0;
	factor = factor + 1;
	Direction_t dir = m_obj.getDirection();
	timeTochange += clock.getElapsedTime().asSeconds();
	
	/*for (int j = 0; j < bombs.size(); j++)
	{
		std::cout << "escape " << "\n";
		if (calculateDistance(bombs[j]->getPosition(), m_obj.getPosition()) <= bombs[j]->getRad()+1 && 
			sameLine(m_obj.getPosOnBoard(), bombs[j]->getPosOnBoard()))
		{
			dir = getAway(*bombs[j],board);
			chase = false;
		}
		
	}	*/
	//chase players in radius

	if (/*chase && */timeTochange > 15.f)
	{
		int opt = (rand() + factor) % 4;
		//std::cout << "chase " << "\n";
		for (int i = 0; i < places.size(); i++)
		{
			if (5 > calculateDistance(places[i], m_obj.getPosition())) // אם המרחק מהשחקן קטן מרדיוס מסויים, תתכוונן אליו
			{
				if (m_obj.getRad() > calculateDistance(places[i], m_obj.getPosition()))
					bombs.emplace_back(m_obj.createBomb());
				else
					dir = getTheObjDirection(places[i], opt);		
			}
				
		}
		dir = Direction_t(opt);
		timeTochange = 0;
	}

	return dir;
}

int CompMovement::calculateDistance(sf::Vector2f place1, sf::Vector2f place2)
{

	int x = std::pow((place1.x - place2.x) / STATIC_WIDTH, 2.0);
	int y = std::pow((place1.y - place2.y) / STATIC_HEIGHT, 2.0);

	int radius = std::sqrt(x + y);

	return radius;
}

Direction_t CompMovement::getTheObjDirection(sf::Vector2f place, int opt)
{
	if (opt % 2 == 0)
	{
		if (place.x > m_obj.getPosition().x)
			return Right_t;
		return Left_t;
	}
	else
	{
		if (place.y > m_obj.getPosition().y)
			return Down_t;
		return Up_t;
	}
}


bool CompMovement::sameLine(sf::Vector2i place1, sf::Vector2i place2)
{
	return (place1.y == place2.y || place1.x == place2.x);
}

Direction_t CompMovement::getAway(Bomb & bomb, Board & board)
{
	sf::Vector2i safe = m_obj.getPosOnBoard();
	if (bomb.getPosOnBoard().y == m_obj.getPosOnBoard().y)
	{
		if (board.isCleanPlace(safe + sf::Vector2i{ 1, 0 }))
			return Right_t;
		else if (board.isCleanPlace(safe + sf::Vector2i{ -1, 0 }))
			return Left_t;
	}
	else if (bomb.getPosOnBoard().x == m_obj.getPosOnBoard().x)
	{
		if (board.isCleanPlace(safe + sf::Vector2i{ 0, 1 }))
			return Up_t;
		else if (board.isCleanPlace(safe + sf::Vector2i{0, -1 }))
			return Down_t;

	}
	
	return m_obj.getDirection();
}
