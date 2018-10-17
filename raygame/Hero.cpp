#include "Hero.h"

Hero::Hero()
{
	name = "Doom Guy";
	special = "Death";
	age = 26;
	hitPoints = 150;
	wealth = 50;
}


Hero::~Hero()
{
}

void Hero::operator+=(Potion potion)
{
	hitPoints += potion.hpModifier;
}
