#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "UserPlayer.h"
#include "CompPlayer.h"
#include "Wall.h"
#include "BombGift.h"
#include "FastGift.h"
#include "BombPowerGift.h"
#include "KickGift.h"
#include "ThrowGift.h"

namespace { // unnamed namespace — the standard way to make function "static"

			// primary collision-processing functions
	bool userPlayer_Wall(Objects& userPlayer, Objects& wall, Level& level)
	{
		UserPlayer& player = dynamic_cast<UserPlayer&>(userPlayer);
		Wall& obj = dynamic_cast<Wall&>(wall);

		return AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect());
	}
	bool userPlayer_Barrel(Objects& userPlayer, Objects& obj, Level& level)
	{
		UserPlayer& player = dynamic_cast<UserPlayer&>(userPlayer);
		Barrel& barrel = dynamic_cast<Barrel&>(obj);

		return AABBCollision(player.getCharFloatRect(), barrel.getCharFloatRect());
	}
	bool compPlayer_Wall(Objects& compplayer, Objects& obj, Level& level)
	{
		CompPlayer& player = dynamic_cast<CompPlayer&>(compplayer);
		Wall& wall = dynamic_cast<Wall&>(obj);

		 return AABBCollision(player.getCharFloatRect(), wall.getCharFloatRect());
	}
	bool compPlayer_Barrel(Objects& compplayer, Objects& obj, Level& level)
	{
		CompPlayer& player = dynamic_cast<CompPlayer&>(compplayer);
		Barrel& barrel = dynamic_cast<Barrel&>(obj);

		return AABBCollision(player.getCharFloatRect(), barrel.getCharFloatRect());
	}
	bool compPlayer_compPlayer(Objects& compplayer1, Objects& compplayer2, Level& level)
	{
		CompPlayer& player1 = dynamic_cast<CompPlayer&>(compplayer1);
		CompPlayer& player2 = dynamic_cast<CompPlayer&>(compplayer2);

		player1.setDir(Up_t);
		player2.setDir(Down_t);
		return true;
	}
	bool userPlayer_bombGift(Objects& userPlayer, Objects& gift, Level& level)
	{
		UserPlayer& player = dynamic_cast<UserPlayer&>(userPlayer);
		BombGift& obj = dynamic_cast<BombGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.incBombs();
			return true;
		}
		return false;
	}
	bool compPlayer_bombGift(Objects& compPlayer, Objects& gift, Level& level)
	{
		CompPlayer& player = dynamic_cast<CompPlayer&>(compPlayer);
		BombGift& obj = dynamic_cast<BombGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.incBombs();
			return true;
		}
		return false;
	}
	bool userPlayer_throwGift(Objects& userPlayer, Objects& gift, Level& level)
	{
		UserPlayer& player = dynamic_cast<UserPlayer&>(userPlayer);
		ThrowGift& obj = dynamic_cast<ThrowGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.activateThrow();
			return true;
		}
		return false;
	}
	bool compPlayer_throwGift(Objects& compPlayer, Objects& gift, Level& level)
	{
		CompPlayer& player = dynamic_cast<CompPlayer&>(compPlayer);
		ThrowGift& obj = dynamic_cast<ThrowGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.activateThrow();
			return true;
		}
		return false;
	}
	bool userPlayer_kickGift(Objects& userPlayer, Objects& gift, Level& level)
	{
		UserPlayer& player = dynamic_cast<UserPlayer&>(userPlayer);
		KickGift& obj = dynamic_cast<KickGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.activateKick();
			return true;
		}
		return false;
	}
	bool compPlayer_kickGift(Objects& compPlayer, Objects& gift, Level& level)
	{
		CompPlayer& player = dynamic_cast<CompPlayer&>(compPlayer);
		KickGift& obj = dynamic_cast<KickGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.activateKick();
			return true;
		}
		return false;
	}
	bool userPlayer_bombPowerGift(Objects& userPlayer, Objects& gift, Level& level)
	{
		UserPlayer& player = dynamic_cast<UserPlayer&>(userPlayer);
		BombPowerGift& obj = dynamic_cast<BombPowerGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.incRadius();
			return true;
		}
		return false;
	}
	bool compPlayer_bombPowerGift(Objects& compPlayer, Objects& gift, Level& level)
	{
		CompPlayer& player = dynamic_cast<CompPlayer&>(compPlayer);
		BombPowerGift& obj = dynamic_cast<BombPowerGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.incRadius();
			return true;
		}
		return false;
	}
	bool userPlayer_fastGift(Objects& userPlayer, Objects& gift, Level& level)
	{
		UserPlayer& player = dynamic_cast<UserPlayer&>(userPlayer);
		FastGift& obj = dynamic_cast<FastGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.incSpeed();
			return true;
		}
		return false;
	}
	bool compPlayer_fastGift(Objects& compPlayer, Objects& gift, Level& level)
	{
		CompPlayer& player = dynamic_cast<CompPlayer&>(compPlayer);
		FastGift& obj = dynamic_cast<FastGift&>(gift);

		if (AABBCollision(player.getCharFloatRect(), obj.getCharFloatRect()))
		{
			level.delObjAtPlace(obj.getPosOnBoard());
			player.incSpeed();
			return true;
		}
		return false;
	}
	bool fire_wall(Objects& fire, Objects& wall, Level& level)
	{
		Fire& f = dynamic_cast<Fire&>(fire);
		Wall& obj = dynamic_cast<Wall&>(wall);

		if (AABBCollision(f.getCharFloatRect(), obj.getCharFloatRect()))
		{
			f.stopSpread();
			return true;
		}
		return false;
	}
	bool fire_barrel(Objects& f, Objects& obj, Level& level)
	{
		Fire& fire = dynamic_cast<Fire&>(f);
		Barrel& barrel = dynamic_cast<Barrel&>(obj);

		if (AABBCollision(f.getCharFloatRect(), obj.getCharFloatRect()))
		{
			sf::Vector2f pos = barrel.getPosition();
			auto gift = barrel.randGift();
			level.delObjAtPlace(barrel.getPosOnBoard());
			level.getBoard().setObj(gift,pos);
			fire.stopSpread();
			return false;
		}
		return true;
	}
	bool Player_fire(Objects & pl, Objects & obj, Level & level)
	{
		return AABBCollision(pl.getCharFloatRect(), obj.getCharFloatRect());
	}
}
//...

using HitFunctionPtr = bool(*)(Objects&, Objects&, Level&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;

HitMap initializeCollisionMap()
{
	HitMap phm;
	phm[Key(typeid(UserPlayer), typeid(Wall))] = &userPlayer_Wall;
	phm[Key(typeid(UserPlayer), typeid(Barrel))] = &userPlayer_Barrel;
	phm[Key(typeid(UserPlayer), typeid(ThrowGift))] = &userPlayer_throwGift;
	phm[Key(typeid(UserPlayer), typeid(KickGift))] = &userPlayer_kickGift;
	phm[Key(typeid(UserPlayer), typeid(BombPowerGift))] = &userPlayer_bombPowerGift;
	phm[Key(typeid(UserPlayer), typeid(BombGift))] = &userPlayer_bombGift;
	phm[Key(typeid(UserPlayer), typeid(Fire))] = &Player_fire;
	phm[Key(typeid(UserPlayer), typeid(FastGift))] = &userPlayer_fastGift;

	phm[Key(typeid(CompPlayer), typeid(Wall))] = &compPlayer_Wall;
	phm[Key(typeid(CompPlayer), typeid(Barrel))] = &compPlayer_Barrel;
	phm[Key(typeid(CompPlayer), typeid(ThrowGift))] = &compPlayer_throwGift;
	phm[Key(typeid(CompPlayer), typeid(KickGift))] = &compPlayer_kickGift;
	phm[Key(typeid(CompPlayer), typeid(BombPowerGift))] = &compPlayer_bombPowerGift;
	phm[Key(typeid(CompPlayer), typeid(BombGift))] = &compPlayer_bombGift;
	phm[Key(typeid(CompPlayer), typeid(FastGift))] = &compPlayer_fastGift;
	phm[Key(typeid(CompPlayer), typeid(Fire))] = &Player_fire;

	phm[Key(typeid(Fire), typeid(Wall))] = &fire_wall;
	phm[Key(typeid(Fire), typeid(Barrel))] = &fire_barrel;



	//phm[Key(typeid(UserPlayer), typeid(Bomb))] = &compPlayer_fastGift;
	return phm;
}

HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
{
	static HitMap collisionMap = initializeCollisionMap();
	auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
	if (mapEntry == collisionMap.end())
	{
		return nullptr;
	}
	return mapEntry->second;
}

 // end namespace

bool processCollision(Objects& object1, Objects& object2, Level& level)
{
	if (&object1 != nullptr && &object2 != nullptr) {//exception?
		auto phf = lookup(typeid(object1), typeid(object2));

		if (phf)
			return phf(object1, object2, level);
	}
	return false;
}

/*bool Intersects(const sf::FloatRect & obj1, const sf::FloatRect & currOBJ)
{
	return obj1.intersects(currOBJ);
}*/

bool AABBCollision(const sf::FloatRect & obj1, const sf::FloatRect & currOBJ)
{

	return std::abs(obj1.left - currOBJ.left) * 2 < (obj1.width + currOBJ.width - 1) &&
		std::abs(obj1.top - currOBJ.top) * 2 < (obj1.height + currOBJ.height - 1);

}
/*bool Collide(Direction_t dir, sf::Vector2f place)
{

}*/