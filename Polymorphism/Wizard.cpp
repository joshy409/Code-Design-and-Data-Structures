#include "Wizard.h"


Wizard::Wizard(const std::string & fileName) : Player(fileName)
{
	fireball = LoadTexture("Wizard/tank_explosion2.png");
}




void Wizard::moveTo(const Vector2 & dest)
{
	position = dest;
	collider.x = dest.x;
	collider.y = dest.y;
}

void Wizard::shoot(const Vector2 & dest)
{
	fireballDestination = dest;
	fireballPosition = position;
}

void Wizard::DrawFireball()
{
	fireballPosition.x += (fireballDestination.x - fireballPosition.x) * speed*2 * GetFrameTime();
	fireballPosition.y += (fireballDestination.y - fireballPosition.y) * speed*2 * GetFrameTime();

	DrawTexture(fireball, fireballPosition.x, fireballPosition.y, WHITE);
}
