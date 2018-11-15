#pragma once
#include "raylib.h"
#include "SimpleSprites.h"
#include <cstdlib>
#include <ctime>
#include <list>
#include "tObjectPool.h"
class FallingFactorys
{
public:
	static SimpleSprites* spriteMasters;
	static size_t spriteCount;
	static void init();
	static void init(size_t poolSize);
	static tObjectPool<SimpleSprites*> tanks;

	static SimpleSprites * getRandom();// returns a random sprite from all sprites loaded
	static SimpleSprites * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.
	FallingFactorys();
	~FallingFactorys();
};

