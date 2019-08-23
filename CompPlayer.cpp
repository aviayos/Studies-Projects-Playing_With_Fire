#include "CompPlayer.h"


CompPlayer::CompPlayer(int i, const int width, const int height): 
	Player::Player(i, width, height)
{
	m_move = std::move(std::make_unique<CompMovement>(this));
	//m_attack = std::move(std::make_unique<AttackRegular>(this));
}


CompPlayer::~CompPlayer()
{
}

void CompPlayer::setRadius(int r)
{
	m_radius = r;
}

void CompPlayer::move(Direction_t dir)
{
	m_dir = dir;
	m_move->MoveTo(m_dir);
}

Direction_t CompPlayer::getDirFromSmart(vector<std::shared_ptr<Bomb>> & bombs, vector<sf::Vector2f> & places, Board & board)
{
	return m_move->MoveSmart(bombs, places, board);
}


