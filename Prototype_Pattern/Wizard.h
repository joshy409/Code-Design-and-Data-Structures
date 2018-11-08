#pragma once
#include "Player.h"
#include <math.h>

class Wizard :
	public Player
{
public:
	Texture2D fireball;
	Vector2 fireballDestination;
	Vector2 fireballPosition;
	Vector2 travelDistance;
	Vector2 origin;
	float angle;
	float distance;
	float fireballSpeed = 20;
	Wizard(const std::string & fileName);
	void moveTo(const Vector2 &dest);
	void shoot(const Vector2 &dest);
	void DrawFireball();
};

