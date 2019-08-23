#include <iostream>
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include <string>
#include <fstream>
#include "Menu.h"

int main()
{
	srand(time(NULL));
	sf::RenderWindow win(sf::VideoMode(1085, 810), "Tetris", sf::Style::Titlebar | sf::Style::Close);
	//Controller con;
	//con.runGame(win, 1, 2, 3);
	Menu m;
	m.Action(win);

}