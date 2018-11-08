#pragma once
#include "raylib.h"
#include "SimpleSprite.h"
#include <cstdlib>
#include <ctime>
#include <list>
class FallingFactory
{
public:
	static SimpleSprite* spriteMasters;
	static size_t spriteCount;
	static std::list<SimpleSprite*> tanks;
	static void init();

	static SimpleSprite * getRandom();// returns a random sprite from all sprites loaded
	static SimpleSprite * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.

	FallingFactory();
	~FallingFactory();
};

