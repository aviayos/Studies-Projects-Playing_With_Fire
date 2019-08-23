#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <vector>

class Objects;

const int NUM_OF_PICS = 16;
enum Pics_t {
	players_t, blocks_t, background_t, players_t1, players_t2, players_t3, players_t4, menu_background_t,
	Menu_Buttons1_t, Menu_Buttons2_t, Help1_t, Help2_t, Bombs_t, B_Gifts_t, Gifts_t, Fire_t};

class Singleton
{
public:
	static std::map<char, std::shared_ptr<Objects>(*)()>& get_map();
	sf::Texture& getPic(const Pics_t& pic);
	static Singleton & instance();
	sf::Font& getFont();

private:
	Singleton();
	std::map<Pics_t, sf::Texture> m_pics;
	std::map<Pics_t, sf::Sound> m_sounds;
	sf::Font m_font;	
};
