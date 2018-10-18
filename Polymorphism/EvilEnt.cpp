#include "EvilEnt.h"



EvilEnt::EvilEnt(float _x, float _y)
{
	position = { _x, _y };
	destination = { _x, _y };
	speed = 1.f;
	mySprite = LoadTexture("EvilEnt/female_stand.png");
	collider = { _x, _y, 80, 110 };
}

void EvilEnt::moveTo(const Vector2 & dest)
{
	destination = dest;
}

void EvilEnt::Draw()
{
	if ((position.x - destination.x) > 0) {
		position.x -= speed;
		collider.x -= speed;
	}
	else if ((position.x - destination.x) < 0) {
		position.x += speed;
		collider.x += speed;
	}

	if ((position.y - destination.y) > 0) {
		position.y -= speed;
		collider.y -= speed;
	}
	else if ((position.y - destination.y) < 0) {
		position.y += speed;
		collider.y += speed;
	}

	DrawTexture(mySprite, position.x, position.y, WHITE);
}
