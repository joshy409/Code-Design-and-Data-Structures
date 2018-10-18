#pragma once
#include "Enemy.h"
class Necromancer :
	public Enemy
{
public:
	Necromancer(float _x, float _y);
	void moveTo(const Vector2 & dest) override;
	void Draw() override;
};

