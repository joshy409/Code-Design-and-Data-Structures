#pragma once
#include "Player.h"
class Barbarian :
	public Player
{
public:

	Barbarian(const std::string & fileName);
	void moveTo(const Vector2 &dest);
	void Draw();
};

