#include "FallingFactorys.h"

size_t FallingFactorys::spriteCount = NULL;
SimpleSprites* FallingFactorys::spriteMasters = nullptr;
tObjectPool<SimpleSprites*> FallingFactorys::tanks;

FallingFactorys::FallingFactorys()
{
}


FallingFactorys::~FallingFactorys()
{
}

void FallingFactorys::init()
{
	//Load in the various sprites
	spriteCount = 4;
	spriteMasters = new SimpleSprites[spriteCount];
	spriteMasters[0] = *(new SimpleSprites("Sprites/tanks_tankDesert1.png", "tank", 1.f));
	spriteMasters[1] = *(new SimpleSprites("Sprites/tanks_tankGreen1.png", "tank", 1.f));
	spriteMasters[2] = *(new SimpleSprites("Sprites/tanks_tankGrey1.png", "tank", 1.f));
	spriteMasters[3] = *(new SimpleSprites("Sprites/tanks_tankNavy1.png", "tank", 1.f));

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 5; i++) {
				tanks.pool.push_back( spriteMasters[j].Clone());
		}
	}
	
}

void FallingFactorys::init(size_t poolSize)
{
	//Load in the various sprites
	spriteCount = 4;
	spriteMasters = new SimpleSprites[spriteCount];
	spriteMasters[0] = *(new SimpleSprites("Sprites/tanks_tankDesert1.png", "tank", 1.f));
	spriteMasters[1] = *(new SimpleSprites("Sprites/tanks_tankGreen1.png", "tank", 1.f));
	spriteMasters[2] = *(new SimpleSprites("Sprites/tanks_tankGrey1.png", "tank", 1.f));
	spriteMasters[3] = *(new SimpleSprites("Sprites/tanks_tankNavy1.png", "tank", 1.f));
	delete spriteMasters;
}

SimpleSprites * FallingFactorys::getRandom()
{
	static bool seeding = false;
	if (!seeding) {
		seeding = true;
		srand(time(NULL));
	}
	

	return *tanks.retrieve();
}

SimpleSprites * FallingFactorys::getFromType(const std::string & _sprType)
{
	return nullptr;
}
