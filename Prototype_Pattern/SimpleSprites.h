#pragma once
#include <string>
#include "raylib.h"
class SimpleSprites
{
public:
public:
	std::string sprType;
	Vector2 pos;
	float rot;
	Rectangle r1, r2;//r1 = collider , r2 = calculated destination size
	Texture2D texture;

	void translate(const Vector2 &delta); // move the sprites position by delta.
	void draw(); //draw the sprite on screen
	SimpleSprites * Clone();

	SimpleSprites();
	SimpleSprites(const SimpleSprites &copy);
	SimpleSprites(const std::string & filename, const std::string _sprType = "", float scale = 1);
	~SimpleSprites();
};

