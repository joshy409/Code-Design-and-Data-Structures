#include "Sprite.h"

void Sprite::Draw()
{
	DrawTexture(sprites[frameCount], 50, 50, WHITE);

	if (frameCount == frameMax) {
		frameCount = 0;
	}
	DrawText(std::to_string(frameCount).c_str(), 0, 0, 10, DARKGRAY);
}

void Sprite::frames()
{
	frameCount++;
}

Sprite::Sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
}

Sprite::Sprite()
{
}

Sprite::Sprite(std::vector<std::string> spriteFileNames)
{
	for (std::string spriteFileName : spriteFileNames) {
		
		sprites.push_back(LoadTexture(spriteFileName.c_str()));
	}

	frameMax = spriteFileNames.size()-1;
}


Sprite::~Sprite()
{
}
