#include "Player.h"



void Player::moveTo(const Vector2 & dest)
{

}

void Player::Draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}

Player::Player(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

