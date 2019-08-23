#include "BombPowerGift.h"

bool BombPowerGift::m_registerit = Factory::registerIt('2',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<BombPowerGift>(); });

BombPowerGift::BombPowerGift()
{
	m_type = Lightning_t;
}


BombPowerGift::~BombPowerGift()
{
}
