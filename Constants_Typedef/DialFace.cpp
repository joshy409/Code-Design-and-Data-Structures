#include "DialFace.h"




void DialFace::DrawFace()
{
	DrawCircle(position.x, position.y, radius, WHITE);
}

void DialFace::Tick(Vector2 mousePosition)
{
	degrees++;
	float angle = degrees * PI / 180 ;
	//float angle = atan2(position.y - mousePosition.y, position.x - mousePosition.x);
	DrawLineEx(position, Vector2{ position.x - (radius * cos(angle)), position.y-(radius * sin(angle)) }, 5, BLACK);


}

DialFace::DialFace()
{
}

 