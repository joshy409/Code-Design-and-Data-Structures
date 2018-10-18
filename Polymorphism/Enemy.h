#pragma once
#include "raylib.h"
#include <iostream>

class Enemy 
{
public:
	Vector2 position;
	Vector2 destination;
	float speed;
	Texture2D mySprite;
	Rectangle collider;
	virtual void moveTo(const Vector2 &dest) = 0;
	virtual void Draw() = 0;

};
