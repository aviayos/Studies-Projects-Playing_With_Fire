#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Level.h"
#include "UserPlayer.h"
#include "CompPlayer.h"
#include <thread>
#include "CollisionHandling.h"

const int PLAYER_ONE = 0;
const int PLAYER_TWO = 1;


class Controller
{
public:
	Controller();
	~Controller();
	void runGame(sf::RenderWindow& win, const int& num_players, const int& num_rivels, const int& num_level);
	
private:
	//Data members
	std::vector<std::unique_ptr<Level>> m_levels;
	std::vector<std::unique_ptr<UserPlayer>> m_users;
	std::vector<std::unique_ptr<CompPlayer>> m_rivals;
	std::vector<std::shared_ptr<Bomb>> m_bombs;
	sf::Sprite m_background;
	
	//Functions
	void checkForInjuries(Bomb &, Level &);
	void draw(sf::RenderWindow& win,const int& num_level);
	void createPlayers(int num_of_user, int num_of_rivals);
	void getUserPress(int num_level);
	bool isCollide(std::unique_ptr<Level> & level, Player & player, Direction_t dir);
	sf::Vector2f fixPlacing(Direction_t dir, sf::Vector2i place, Player & player);
	void rivalsMove(int num_level,int rivals);
	void checkForBombs(Player &);
	void DoThrow(Player &);
	void moveBombs(const int);
	void updatePlayers(Player_t, const int num_of_users);
	void checkExploded(const int , const int );
	void checkDeath();
};

