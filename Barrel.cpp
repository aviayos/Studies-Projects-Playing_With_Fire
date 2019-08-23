#include "Barrel.h"

bool Barrel::m_registerit = Factory::registerIt('8',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<Barrel>(); });

Barrel::Barrel()
{
	m_char.setOrigin(SQUARE_SIZE / 2, SQUARE_SIZE / 2);//const
	m_char.setTexture(Singleton::instance().getPic(blocks_t));
	m_char.setTextureRect(sf::IntRect(SQUARE_SIZE, 0.f, SQUARE_SIZE, SQUARE_SIZE));
}


Barrel::~Barrel()
{
}

std::shared_ptr<Objects> Barrel::randGift()
{
	static int x = 0;

	x = (x + 1) % 6;

	int choice = x + rand() % 6;

	switch (choice)
	{
	case 0: return nullptr;
	case 1: return (Factory::create('1'));
	case 2: return (Factory::create('2'));
	case 3: return (Factory::create('3'));
	case 4: return (Factory::create('4'));
	case 5: return (Factory::create('5'));

	}
	return nullptr;
}