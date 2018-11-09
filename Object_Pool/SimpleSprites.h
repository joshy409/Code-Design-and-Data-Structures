#pragma once
#include <string>
#include "raylib.h"
#include "tObjectPool.h"
class SimpleSprites
{
public:
public:
	std::string sprType;
	Vector2 pos;
	float rot;
	Rectangle r1;//r1 = collider 
	Texture2D texture;
	bool isActive;
	void translate(const Vector2 &delta); // move the sprites position by delta.
	void draw(); //draw the sprite on screen
	SimpleSprites * Clone();

	SimpleSprites();
	SimpleSprites(const SimpleSprites &copy);
	SimpleSprites(const std::string & filename, const std::string _sprType = "", float scale = 1);
	~SimpleSprites();
};

