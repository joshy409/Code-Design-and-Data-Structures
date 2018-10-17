#pragma once
#include <string>
#include "Potion.h"

class Hero
{
public:
	Hero();
	~Hero();

	std::string name;
	std::string special;
	int age;
	int hitPoints;
	int wealth;

	void operator+= (Potion potion);
};

