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
	origin = position;
	fireballDestination = dest;
	fireballPosition = position;
	travelDistance.x = fireballDestination.x - fireballPosition.x;
	travelDistance.y = fireballDestination.y - fireballPosition.y;
	//angle = atan2(fireballPosition.y - fireballDestination.y, fireballPosition.x - fireballDestination.x) * 180 / PI;
	distance = sqrt(pow((fireballPosition.x - fireballDestination.x), 2) + pow((fireballPosition.y - fireballDestination.y), 2));

}

void Wizard::DrawFireball()
{
	fireballPosition.x += travelDistance.x/distance * fireballSpeed;
	fireballPosition.y += travelDistance.y/distance * fireballSpeed;

	DrawTexture(fireball, fireballPosition.x, fireballPosition.y, WHITE);
}
