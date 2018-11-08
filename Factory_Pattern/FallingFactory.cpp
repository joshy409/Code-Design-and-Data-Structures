#include "FallingFactory.h"

size_t FallingFactory::spriteCount = NULL;
SimpleSprite* FallingFactory::spriteMasters = nullptr;
std::list<SimpleSprite*> FallingFactory::tanks;
FallingFactory::FallingFactory()
{
}


FallingFactory::~FallingFactory()
{
}

void FallingFactory::init()
{
	//Load in the various sprites
	spriteCount = 4;
	spriteMasters = new SimpleSprite[spriteCount];
	spriteMasters[0] = *(new SimpleSprite("Sprites/tanks_tankDesert1.png", "tank", 1.f));
	spriteMasters[1] = *(new SimpleSprite("Sprites/tanks_tankGreen1.png", "tank", 1.f));
	spriteMasters[2] = *(new SimpleSprite("Sprites/tanks_tankGrey1.png", "tank", 1.f));
	spriteMasters[3] = *(new SimpleSprite("Sprites/tanks_tankNavy1.png", "tank", 1.f));
}

SimpleSprite * FallingFactory::getRandom()
{
	srand(time(NULL));
	SimpleSprite* randomTank =  new SimpleSprite(spriteMasters[rand()%4]);
	//SimpleSprite* randomTank = new SimpleSprite(spriteMasters[0]);
	tanks.push_back(randomTank);
	return randomTank;
}

SimpleSprite * FallingFactory::getFromType(const std::string & _sprType)
{
	return nullptr;
}
