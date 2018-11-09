#pragma once
#include "raylib.h"
#include "SimpleSprites.h"
#include "tObjectPool.h"
#include <cstdlib>
#include <ctime>
#include <list>
class FallingFactorys
{
public:
public:
	static SimpleSprites* spriteMasters;
	static size_t spriteCount;
	static std::list<SimpleSprites*> tanks;
	static tObjectPool<SimpleSprites*> pool;
	static void init();

	static SimpleSprites * getRandom();// returns a random sprite from all sprites loaded
	static SimpleSprites * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.
	FallingFactorys();
	~FallingFactorys();
};

