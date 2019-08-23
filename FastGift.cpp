#include "FastGift.h"

bool FastGift::m_registerit = Factory::registerIt('3',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<FastGift>(); });

FastGift::FastGift()
{
	m_type = Speed_t;
}


FastGift::~FastGift()
{
}
