#include "Button.h"



Button::Button()
{
}

Button::Button(std::vector<std::string> buttons, float _x, float _y)
{
	for (std::string button : buttons) {

		sprites.push_back(LoadTexture(button.c_str()));
	}

	frameMax = buttons.size() - 1;
	x = _x;
	y = _y;
}


Button::~Button()
{
}

void Button::Draw()
{
	DrawTexture(sprites[frameCount], x, y, WHITE);

	if (frameCount == frameMax) {
		frameCount = 0;
	}
}
