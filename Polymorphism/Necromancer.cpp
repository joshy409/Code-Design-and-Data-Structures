#include "Necromancer.h"


Necromancer::Necromancer(float _x, float _y)
{
	position = { _x, _y };
	destination = { _x, _y };
	speed = .9f;
	mySprite = LoadTexture("Necromancer/zombie_stand.png");
	collider = { _x, _y, 80, 110 };
}

void Necromancer::moveTo(const Vector2 &dest) {
	destination = dest;
}

void Necromancer::Draw()
{
	/*if ((position.x - destination.x) > 0) {
		position.x -= speed;
		collider.x -= speed;
	}
	else if ((position.x - destination.x) < 0) {
		position.x += speed;
		collider.x += speed;
	}

	if ((position.y - destination.y) > 0) {
		position.y -= speed;
		collider.x -= speed;
	}
	else if ((position.y - destination.y) < 0) {
		position.y += speed;
		collider.x += speed;
	}*/
	position.x += (destination.x - position.x) * .3 * GetFrameTime();
	collider.x += (destination.x - position.x) * .3 * GetFrameTime();
	position.y += (destination.y - position.y) * .3 * GetFrameTime();
	collider.y += (destination.y - position.y) * .3 * GetFrameTime();
	DrawTexture(mySprite, position.x, position.y, WHITE);
}
