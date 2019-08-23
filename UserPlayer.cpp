#include "UserPlayer.h"

static int m_pplayer = 1;

UserPlayer::UserPlayer(int i, const int width, const int height) :
	Player::Player(i, width, height)
{
	m_move = std::move(std::make_unique<UserMovement>(this));
//	m_attack = std::move(std::make_unique<AttackRegular>(this));

	if (m_pplayer == 1) {
		m_orders.emplace(sf::Keyboard::Right, [&]() { m_dir = Right_t, m_move->MoveTo(m_dir);});
		m_orders.emplace(sf::Keyboard::Left, [&]() { m_dir = Left_t, m_move->MoveTo(m_dir);});
		m_orders.emplace(sf::Keyboard::Up, [&]() { m_dir = Up_t; m_move->MoveTo(m_dir);});
		m_orders.emplace(sf::Keyboard::Down, [&]() {m_dir = Down_t; m_move->MoveTo(m_dir);});
	}
	else
	{
		m_orders.emplace(sf::Keyboard::D, [&]() {m_dir = Right_t; m_move->MoveTo(m_dir);});
		m_orders.emplace(sf::Keyboard::A, [&]() {m_dir = Left_t; m_move->MoveTo(m_dir);});
		m_orders.emplace(sf::Keyboard::W, [&]() {m_dir = Up_t; m_move->MoveTo(m_dir);});
		m_orders.emplace(sf::Keyboard::S, [&]() {m_dir = Down_t; m_move->MoveTo(m_dir);});
	}
	m_pplayer++;
}

UserPlayer::~UserPlayer()
{
	m_pplayer = 1;
}

void UserPlayer::getUserCommand(sf::Keyboard::Key keypress)
{ 
	auto it = m_orders.find(keypress);
	if (it != m_orders.end()) {
		it->second();
	}
}






