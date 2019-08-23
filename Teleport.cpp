#include "Teleport.h"

bool Teleport::m_registerit = Factory::registerIt('t',
	[]() -> std::shared_ptr<Objects> { return std::make_shared<Teleport>(); });


Teleport::Teleport()
{
}


Teleport::~Teleport()
{
}
