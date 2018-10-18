#pragma once
#include "Player.h"
class Wizard :
	public Player
{
public:
	Texture2D fireball;
	Vector2 fireballDestination;
	Vector2 fireballPosition;
	Wizard(const std::string & fileName);
	void moveTo(const Vector2 &dest);
	void shoot(const Vector2 &dest);
	void DrawFireball();
};

