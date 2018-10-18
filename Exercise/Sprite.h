#pragma once
#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>
class Sprite : public Vector2
{
public:
	//Texture2D * spriteCells = NULL;
	std::vector<Texture2D> sprites;
	//float frameRate = 25.0;
	int frameCount = 0;
	int frameMax = 0;
	//int direction = 1;
	void Draw();
	void frames();



	Sprite(const std::string *filename, const  int cellCount = 1, const float _frameRate = 25.0);
	Sprite();
	Sprite(std::vector<std::string> spriteFileNames);
	~Sprite();
};

