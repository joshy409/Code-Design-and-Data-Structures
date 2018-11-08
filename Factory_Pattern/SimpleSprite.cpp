#include "SimpleSprite.h"

SimpleSprite::SimpleSprite()
{
}

SimpleSprite::SimpleSprite(const SimpleSprite & copy)
{
	texture = copy.texture;
	sprType = copy.sprType;

}

SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{
	texture = LoadTexture(filename.c_str());
	sprType = _sprType;
}

SimpleSprite::~SimpleSprite()
{
}

void SimpleSprite::translate(const Vector2 &delta)
{
	pos = { pos.x + delta.x , pos.y + delta.y };
}

void SimpleSprite::draw()
{
	DrawTexture(texture, pos.x, pos.y, WHITE);
}