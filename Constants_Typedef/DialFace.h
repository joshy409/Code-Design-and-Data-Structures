#pragma once
#include "raylib.h"
#include <math.h>
#include <string>
static float currentAngle;
class DialFace
{
public:
	static Vector2 position;
	static float radius;
	float degrees = 0;
	static void DrawFace();
	void Tick(Vector2 mousePosition);
	DialFace();

};