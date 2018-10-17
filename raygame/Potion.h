#pragma once
#include <string>
class Potion
{
public:
	Potion();
	~Potion();

	std::string name;
	int hpModifier;
	std::string quality;
	int useByDate;
};

