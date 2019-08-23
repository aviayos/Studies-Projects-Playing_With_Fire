#include "Controller.h"
#include <DirectXCollision.h>
Controller::Controller()
{
	bool keepCreate = true;
	while (keepCreate) { m_levels.emplace_back(std::make_unique<Level>(keepCreate)); }
	m_background.setTexture(Singleton::instance().getPic(background_t));

}

Controller::~Controller()
{
}

void Controller::runGame(sf::RenderWindow& win, const int& num_players, const int& num_rivels, const int& num_level)
{

	createPlayers(num_players, num_rivels);

	while (m_users.size() + m_rivals.size() > 1)// לולאה על השלב עד שמישהו נפםל
	{

		sf::Event userEvent;
		getUserPress(num_level);//user player move
		rivalsMove(num_level, num_rivels);
		moveBombs(num_level);
		checkExploded(num_level, num_players);
		checkDeath();
		while (win.pollEvent(userEvent))//לולאה על קבלת קלט מהמשתמש
		{
			if (userEvent.type == sf::Event::MouseButtonPressed)
			{
				//quit or mute
			}
		}
		win.clear();
		draw(win, num_level);
		win.display();
	}

}

void Controller::checkForInjuries(Bomb & bomb, Level & level)
{
	for (int i = 0; i < m_users.size(); i++)
	{
		if (bomb.explodeOn(*m_users[i], level))
			m_users[i]->decLives();
	}
	for (int i = 0; i < m_rivals.size(); i++)
	{
		if (bomb.explodeOn(*m_rivals[i], level))
			m_rivals[i]->decLives();
	}

}

void Controller::draw(sf::RenderWindow & win, const int& num_level)
{
	win.draw(m_background);
	
	m_levels[num_level - 1]->draw(win);
	for (unsigned int i = 0; i < m_users.size(); i++)
		m_users[i].get()->draw(win);
	for (unsigned int j = 0; j < m_rivals.size(); j++)
		m_rivals[j]->draw(win);
	for (int i = 0; i < m_bombs.size(); i++)
		m_bombs[i]->draw(win);

}

void Controller::createPlayers(int num_of_user, int  num_of_rivals)
{
	if (num_of_user == 2)
		num_of_rivals--;
	for (int i = 0; i < num_of_user; i++)
	{
		m_users.emplace_back(std::make_unique<UserPlayer>(i, WIDTH, HEIGHT));
	}
	for (int j = 0; j < num_of_rivals; j++)
	{
		m_rivals.emplace_back(std::make_unique<CompPlayer>(j + num_of_user, WIDTH, HEIGHT));
	}

}

void Controller::getUserPress(int num_level)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isCollide(m_levels[num_level - 1], *m_users[PLAYER_ONE], Left_t))
		m_users[PLAYER_ONE]->getUserCommand(sf::Keyboard::Left);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isCollide(m_levels[num_level - 1], *m_users[PLAYER_ONE], Right_t))
		m_users[PLAYER_ONE]->getUserCommand(sf::Keyboard::Right);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isCollide(m_levels[num_level - 1], *m_users[PLAYER_ONE], Up_t))
		m_users[PLAYER_ONE]->getUserCommand(sf::Keyboard::Up);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isCollide(m_levels[num_level - 1], *m_users[PLAYER_ONE], Down_t))
		m_users[PLAYER_ONE]->getUserCommand(sf::Keyboard::Down);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		checkForBombs(*m_users[PLAYER_ONE]);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		DoThrow(*m_users[PLAYER_ONE]);


	if (m_users.size() == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !isCollide(m_levels[num_level - 1], *m_users[PLAYER_TWO], Left_t))
			m_users[PLAYER_TWO]->getUserCommand(sf::Keyboard::A);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !isCollide(m_levels[num_level - 1], *m_users[PLAYER_TWO], Right_t))
			m_users[PLAYER_TWO]->getUserCommand(sf::Keyboard::D);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isCollide(m_levels[num_level - 1], *m_users[PLAYER_TWO], Up_t))
			m_users[PLAYER_TWO]->getUserCommand(sf::Keyboard::W);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !isCollide(m_levels[num_level - 1], *m_users[PLAYER_TWO], Down_t))
			m_users[PLAYER_TWO]->getUserCommand(sf::Keyboard::S);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			checkForBombs(*m_users[PLAYER_TWO]);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			DoThrow(*m_users[PLAYER_TWO]);
	}

}



bool Controller::isCollide(std::unique_ptr<Level> & level, Player & player, Direction_t dir)
{
	sf::Vector2i place = player.getPosOnBoard();
	std::vector<sf::Vector2i> neighboors = level->getNeighboor(place);

	for (int i = 0; i < neighboors.size(); i++)
	{
		if (processCollision(player,
			*level->getObjAtPlace(neighboors[i]),
			*level))
		{

			sf::Vector2f new_place = fixPlacing(dir, place, player);
			player.setPosition(new_place);
			return true;
		}
	}
	return false;
}

sf::Vector2f Controller::fixPlacing(Direction_t dir, sf::Vector2i place, Player & player)
{
	sf::Vector2f center1, center2;
	sf::Vector2f center_pl = { (place.x * STATIC_WIDTH) + (PLAYER_WIDTH / 2) + LEFT_FRAME, (place.y * STATIC_HEIGHT) + (PLAYER_HEIGHT / 2) + OTHER_FRAME };

	switch (dir)
	{
	case Left_t:
	case Right_t:
		center1 = { (place.x * STATIC_WIDTH) + (PLAYER_WIDTH / 2) + LEFT_FRAME, ((place.y + 1) * STATIC_HEIGHT) + (PLAYER_HEIGHT / 2) + OTHER_FRAME };
		center2 = { (place.x * STATIC_WIDTH) + (PLAYER_WIDTH / 2) + LEFT_FRAME, ((place.y - 1) * STATIC_HEIGHT) + (PLAYER_HEIGHT / 2) + OTHER_FRAME };

		if (abs(center1.y - player.getPosition().y) > abs(center2.y - player.getPosition().y))
			return (player.getPosition() + sf::Vector2f{ 0, player.getSpeed() });

		else if (abs(center1.y - player.getPosition().y) < abs(center2.y - player.getPosition().y))
			return (player.getPosition() + sf::Vector2f{ 0, -player.getSpeed() });

		else
			return (center_pl);
		break;

	case Up_t:
	case Down_t:
		center1 = { ((place.x + 1) * STATIC_WIDTH) + (PLAYER_WIDTH / 2) + LEFT_FRAME, (place.y  * STATIC_HEIGHT) + (PLAYER_HEIGHT / 2) + OTHER_FRAME };
		center2 = { ((place.x - 1) * STATIC_WIDTH) + (PLAYER_WIDTH / 2) + LEFT_FRAME, (place.y  * STATIC_HEIGHT) + (PLAYER_HEIGHT / 2) + OTHER_FRAME };

		if (abs(center1.x - player.getPosition().x) > abs(center2.x - player.getPosition().x))
			return (player.getPosition() + sf::Vector2f{ player.getSpeed() , 0 });

		else if (abs(center1.x - player.getPosition().x) < abs(center2.x - player.getPosition().x))
			return (player.getPosition() + sf::Vector2f{ -player.getSpeed() , 0 });

		else
			return (center_pl);
		break;
	}
}

void Controller::rivalsMove(int num_level, int rivals)
{
	Direction_t dir;
	vector <sf::Vector2f> places;
	for (int i = 0; i < m_users.size(); i++)
		places.emplace_back(m_users[i]->getPosition());

	/*for (int i = 0; i < m_rivals.size(); i++)
		places.emplace_back(m_rivals[i]->getPosition());*/

	for (int j = 0; j < m_rivals.size(); j++)
	{
		dir = m_rivals[j]->getDirFromSmart(m_bombs, places, m_levels[num_level-1]->getBoard());
		if (!isCollide(m_levels[num_level - 1], *m_rivals[j], dir))
			m_rivals[j]->move(dir);
	
	}

}

void Controller::checkForBombs(Player & player)
{
	bool found = false;

	for (int i = 0; i < m_bombs.size(); i++)
	{
		if (m_bombs[i]->getPosOnBoard() == player.getPosOnBoard())//האם באותו מיקום?
			found = true;
	}

	if (!found && player.availableBombs())
		m_bombs.emplace_back(player.createBomb());

}

void Controller::DoThrow(Player & player)
{
	for (int i = 0; i < m_bombs.size(); i++)
	{
		if (m_bombs[i]->getPosOnBoard() == player.getPosOnBoard() && player.throwAble())//האם באותו מיקום?
			m_bombs[i]->setThrow(player.getDirection());
	}
}


void Controller::moveBombs(const int level_num)
{
	for (int i = 0; i < m_bombs.size(); i++)
		m_bombs[i]->move(m_levels[level_num - 1]->getBoard());

}

void Controller::updatePlayers(Player_t owner, const int num_of_users)
{
	for (int i = 0; i < m_users.size(); i++)
	{
		if (m_users[i]->getType() == owner)
			m_users[i]->DecBombs();
	}

	for (int i = 0; i < m_rivals.size(); i++)
	{
		if (m_rivals[i]->getType() == owner)
			m_rivals[i]->DecBombs();
	}
}

void Controller::checkExploded(const int num_level, const int num_of_users)
{
	for (int j = 0; j < m_bombs.size(); j++)
	{
		if (m_bombs[j]->exploded() && !m_bombs[j]->fireIsCreate())//התפוצצה וגם האש לא נוצרה
			m_bombs[j]->createFire(*m_levels[num_level - 1]);

		else if (m_bombs[j]->exploded())//התפוצצה
		{
			checkForInjuries(*m_bombs[j], *m_levels[num_level - 1]);
		}

		if (m_bombs[j]->timeToClean())
		{
			updatePlayers(m_bombs[j]->getHolder(), num_of_users);
			m_bombs.erase(m_bombs.begin() + j);
		}
	}
}

void Controller::checkDeath()
{
	for (int i = 0; i < m_users.size(); i++)
	{
		if (m_users[i]->getLives() <= 0)
			m_users.erase(m_users.begin() + i);
	}
	for (int j = 0; j < m_rivals.size(); j++)
	{
		if (m_rivals[j]->getLives() <= 0)
			m_rivals.erase(m_rivals.begin() + j);
	}
}


