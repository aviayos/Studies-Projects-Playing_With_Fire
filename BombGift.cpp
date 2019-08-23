#include "BombGift.h"

bool BombGift::m_registerit = Factory::registerIt('1',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<BombGift>(); });

BombGift::BombGift()
{
	m_type = Bomb_t;
}


BombGift::~BombGift()
{
}
