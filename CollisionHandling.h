#pragma once

#include "Objects.h"
#include <memory>
#include <iostream>
#include <typeinfo>


class Level;

bool processCollision(Objects& object1, Objects& object2, Level &);
//bool Intersects(const sf::FloatRect & obj1, const sf::FloatRect & currOBJ);
bool AABBCollision(const sf::FloatRect & obj1, const sf::FloatRect & currOBJ);