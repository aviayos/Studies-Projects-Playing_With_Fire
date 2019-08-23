#include "Player.h"



Player::Player(int i, const int width, const int height):
	m_type(Player_t(i)), m_bombRadius(2), m_totalBombs(1), m_usedBombs(0), m_thorwBomb(false), 
	m_kickBomb(false), m_speed(0.3f), m_lives(3)
{
	m_char.setOrigin(sf::Vector2f{ PLAYER_WIDTH / 2,PLAYER_HEIGHT / 2 });

	switch (m_type)
	{
	case Blue_t: m_char.setPosition(sf::Vector2f{ LEFT_FRAME + SQUARE_SIZE + 50 / 2, OTHER_FRAME + SQUARE_SIZE + 60 / 2 });
		m_char.setTexture(Singleton::instance().getPic(players_t1));
		m_dir = Down_t;
		break;
	case Red_t:m_char.setPosition(sf::Vector2f{ LEFT_FRAME + SQUARE_SIZE * (width - 2) + PLAYER_WIDTH / 2, OTHER_FRAME + SQUARE_SIZE * (height - 2) + PLAYER_HEIGHT / 2 });
		m_char.setTexture(Singleton::instance().getPic(players_t2));
		m_dir = Up_t;
		break;
	case Green_t:m_char.setPosition(sf::Vector2f{ LEFT_FRAME + SQUARE_SIZE * (width - 2) + PLAYER_WIDTH / 2, OTHER_FRAME + SQUARE_SIZE + PLAYER_HEIGHT / 2 });
		m_char.setTexture(Singleton::instance().getPic(players_t3));
		m_dir = Down_t;
		break;
	case Purple_t:m_char.setPosition(sf::Vector2f{ LEFT_FRAME + SQUARE_SIZE + PLAYER_WIDTH / 2, OTHER_FRAME + SQUARE_SIZE * (height - 2) + PLAYER_HEIGHT / 2 });
		m_char.setTexture(Singleton::instance().getPic(players_t4));
		m_dir = Up_t;
		break;
	}

}


Player::~Player()
{
}

void Player::draw(sf::RenderWindow & win)
{

	if (m_dir == Left_t) {
		m_char.setTextureRect(sf::IntRect(m_stepChar * 50, Right_t*PLAYER_HEIGHT, 50 - 4, 60 - 4));
		m_char.setScale(-1, 1);
	}
	else {
		m_char.setTextureRect(sf::IntRect(m_stepChar * 50, m_dir * 60, 50 - 4, 60 - 4));
		m_char.setScale(1, 1);
	}

	win.draw(m_char);
	if (m_stepChar == NUM_STEPS)
		m_stepChar = 0;

}

void Player::decLives()
{
	std::cout << "hurt\n";
	m_lives--;
}

void Player::setDir(Direction_t dir)
{
	m_dir = dir;
}

void Player::incBombs()
{
	m_totalBombs++;
}

void Player::DecBombs()
{
	m_usedBombs--;
}

void Player::incRadius()
{
	if (m_bombRadius < MAX_RADIUS)
		m_bombRadius++;

}

void Player::incSpeed()
{
	if (m_speed < MAX_SPEED)
		m_speed+=0.1f;
}

int Player::getLives()
{
	return m_lives;
}

/*void Player::ActivateAttack(Board &board)
{
	m_attack->PerformAttack(board);
}*/


std::shared_ptr<Bomb> Player::createBomb()
{
	m_usedBombs++;
	return std::make_shared<Bomb>(m_type, getPosOnBoard(), m_bombRadius);
}

int Player::availableBombs()
{
	return (m_totalBombs - m_usedBombs > 0);
}

bool Player::throwAble()
{
	return m_thorwBomb;
}

void Player::activateThrow()
{
	m_thorwBomb = true;
}

void Player::activateKick()
{
	m_kickBomb = true;
}

int Player::getRad()
{
	return m_bombRadius;
}

float Player::getSpeed()
{
	return m_speed;
}

