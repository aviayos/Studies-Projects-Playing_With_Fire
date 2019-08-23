#include "Singleton.h"


Singleton::Singleton()
{
	m_font.loadFromFile("Fonts//Font1.ttf");
	sf::Texture temp;
	for (int i = 0; i < NUM_OF_PICS; i++)
	{
		temp.loadFromFile("Graphics//pics" + std::to_string(i) + ".png");//load pictures of the objects
		m_pics.insert(std::pair<Pics_t, sf::Texture>(Pics_t(i), temp));//insert to map
	}

}

sf::Texture& Singleton::getPic(const Pics_t& pic)
{
	return m_pics[pic];
}

Singleton & Singleton::instance()
{
	static Singleton inst;
	return inst;
}

sf::Font& Singleton::getFont()
{
	return m_font;
}

std::map<char, std::shared_ptr<Objects>(*)()>& Singleton::get_map()
{
	static std::map<char, std::shared_ptr<Objects>(*)()> m_map;
	return m_map;
}
