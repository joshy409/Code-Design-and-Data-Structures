#pragma once
#include "Sprite.h"
class Button :
	public Sprite
{
public:
	Button();
	Button(std::vector<std::string> button, float _x, float _y);
	~Button();

	void Draw();
};

