#include "SimpleSprites.h"



SimpleSprites::SimpleSprites()
{
}

SimpleSprites::SimpleSprites(const SimpleSprites & copy)
{
	texture = copy.texture;
	sprType = copy.sprType;
	r1 = copy.r1;

}

SimpleSprites::SimpleSprites(const std::string & filename, const std::string _sprType, float scale)
{
	texture = LoadTexture(filename.c_str());
	sprType = _sprType;
	r1 = { pos.x, pos.y, (float)texture.width, (float) texture.height };
}

SimpleSprites::~SimpleSprites()
{
}

void SimpleSprites::translate(const Vector2 &delta)
{
	pos = { pos.x + delta.x , pos.y + delta.y };
	r1.y += delta.y;
}

void SimpleSprites::draw()
{
	DrawTexture(texture, pos.x, pos.y, WHITE);
}

SimpleSprites * SimpleSprites::Clone()
{
	return new SimpleSprites(*this);
}
