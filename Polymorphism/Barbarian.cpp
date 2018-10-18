#include "Barbarian.h"

Barbarian::Barbarian(const std::string & fileName) : Player(fileName)
{
}


void Barbarian::moveTo(const Vector2 & dest)
{
	destination = dest;
}

void Barbarian::Draw()
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

	position.x += (destination.x - position.x) * speed * GetFrameTime();
	position.y += (destination.y - position.y) * speed * GetFrameTime();

	DrawTexture(mySprite, position.x, position.y, WHITE);
}
