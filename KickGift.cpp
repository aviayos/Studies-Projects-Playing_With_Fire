#include "KickGift.h"

bool KickGift::m_registerit = Factory::registerIt('5',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<KickGift>(); });

KickGift::KickGift()
{
	m_type = Kick_t;
}


KickGift::~KickGift()
{
}
