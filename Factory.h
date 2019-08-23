#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "Objects.h"

class Factory
{
public:
//	Factory();
	static std::shared_ptr<Objects>create(const char& name);
	static bool registerIt(const char& name, std::shared_ptr<Objects>(*func)());
	//~Factory();
	
};
