#include "ThrowGift.h"

bool ThrowGift::m_registerit = Factory::registerIt('4',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<ThrowGift>(); });

ThrowGift::ThrowGift()
{
	m_type = Throw_t;
}


ThrowGift::~ThrowGift()
{
}
