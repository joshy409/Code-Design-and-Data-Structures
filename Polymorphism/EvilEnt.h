#pragma once
#include "Enemy.h"
class EvilEnt :
	public Enemy
{
public:
	EvilEnt(float _x, float _y);
	void moveTo(const Vector2 &dest) override;
	void Draw() override;
};

