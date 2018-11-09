#include "FallingFactorys.h"

size_t FallingFactorys::spriteCount = NULL;
SimpleSprites* FallingFactorys::spriteMasters = nullptr;
std::list<SimpleSprites*> FallingFactorys::tanks;
tObjectPool<SimpleSprites*> FallingFactorys::pool;

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
}

SimpleSprites * FallingFactorys::getRandom()
{
	static bool seeding = false;
	if (!seeding) {
		seeding = true;
		srand(time(NULL));
	}
	
	SimpleSprites* randomTank = spriteMasters[rand() % spriteCount].Clone();
	randomTank->isActive = true;
	pool.recycle(randomTank);
	tanks.push_back(randomTank);
	return randomTank;
}

SimpleSprites * FallingFactorys::getFromType(const std::string & _sprType)
{
	return nullptr;
}
