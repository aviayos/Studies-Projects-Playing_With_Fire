#include "Factory.h"
#include "Singleton.h"

std::shared_ptr<Objects> Factory::create(const char& name) {
	auto it = Singleton::instance().get_map().find(name);
	if (it == Singleton::instance().get_map().end())
		return nullptr;
	return it->second();
}

bool Factory::registerIt(const char& name, std::shared_ptr<Objects>(*func)())
{
	
	Singleton::instance().get_map().emplace(name, func);
	return true;
}


