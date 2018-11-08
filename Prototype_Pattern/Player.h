#pragma once
#include "raylib.h"
#include <iostream>
class Player
{
public:
	Vector2 position = { 1856/2,1024-200 };
	Vector2 destination = { 100,100 };
	float speed = 3;
	Texture2D mySprite;
	void moveTo(const Vector2 &dest);
	void Draw();
	Rectangle collider = { 100,100,80,110 };
	Player(const std::string & fileName);//assign the sprite image.
};

