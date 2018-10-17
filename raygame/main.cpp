/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Hero.h"
#include "Potion.h"
#include "MyColor.h"
#include "main.h"


void leftCircleColor(MyColor &color) {
	if (IsKeyPressed(KEY_Q) || IsKeyDown(KEY_Q)) {
		color.r = (color.r + 1) % 255;
	}
	else if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) {
		color.r = (color.r - 1) % 255;
		if (color.r < 0) {
			color.r = 255;
		}
	}
	if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) {
		color.g = (color.g + 1) % 255;
	}
	else if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) {
		color.g = (color.g - 1) % 255;
		if (color.g < 0) {
			color.g = 255;
		}
	}
	if (IsKeyPressed(KEY_E) || IsKeyDown(KEY_E)) {
		color.b = (color.b + 1) % 255;
	}
	else if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) {
		color.b = (color.b - 1) % 255;
		if (color.b < 0) {
			color.b = 255;
		}
	}

	std::string r = std::to_string(color.r);
	char const *pchar = r.c_str();
	DrawText(pchar, 100, 275, 20, BLACK);
	std::string g = std::to_string(color.g);
	char const *pchar1 = g.c_str();
	DrawText(pchar1, 145, 275, 20, BLACK);
	std::string b = std::to_string(color.b);
	char const *pchar2 = b.c_str();
	DrawText(pchar2, 190, 275, 20, BLACK);


	DrawText("Q    W    E", 100, 250, 20, BLACK);
	DrawText("A    S    D", 100, 300, 20, BLACK);
	



}

void rightCircleColor(MyColor &color) {
	if (IsKeyPressed(KEY_U) || IsKeyDown(KEY_U)) {
		color.r = (color.r + 1) % 255;
	}
	else if (IsKeyPressed(KEY_J) || IsKeyDown(KEY_J)) {
		color.r = (color.r - 1) % 255;
		if (color.r < 0) {
			color.r = 255;
		}
	}
	if (IsKeyPressed(KEY_I) || IsKeyDown(KEY_I)) {
		color.g = (color.g + 1) % 255;
	}
	else if (IsKeyPressed(KEY_K) || IsKeyDown(KEY_K)) {
		color.g = (color.g - 1) % 255;
		if (color.g < 0) {
			color.g = 255;
		}
	}
	if (IsKeyPressed(KEY_O) || IsKeyDown(KEY_O)) {
		color.b = (color.b + 1) % 255;
	}
	else if (IsKeyPressed(KEY_L) || IsKeyDown(KEY_L)) {
		color.b = (color.b - 1) % 255;;
		if (color.b < 0) {
			color.b = 255;
		}
	}

	std::string r = std::to_string(color.r);
	char const *pchar = r.c_str();
	DrawText(pchar, 600, 275, 20, BLACK);
	std::string g = std::to_string(color.g);
	char const *pchar1 = g.c_str();
	DrawText(pchar1, 645, 275, 20, BLACK);
	std::string b = std::to_string(color.b);
	char const *pchar2 = b.c_str();
	DrawText(pchar2, 690, 275, 20, BLACK);

	DrawText("U    I    O", 600, 250, 20, BLACK);
	DrawText("J    K    L", 600, 300, 20, BLACK);
}

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");


	//Load Doom Ouch faces;
	Texture2D ouch1 = LoadTextureFromImage(LoadImage("doom_ouchface/ouch1.png"));
	Texture2D ouch2 = LoadTextureFromImage(LoadImage("doom_ouchface/ouch2.png"));
	Texture2D ouch3 = LoadTextureFromImage(LoadImage("doom_ouchface/ouch3.png"));
	Texture2D ouch4 = LoadTextureFromImage(LoadImage("doom_ouchface/ouch4.png"));
	Texture2D ouch5 = LoadTextureFromImage(LoadImage("doom_ouchface/ouch5.png"));

	Hero hero;
	Potion potion;
	MyColor firstColor(255, 1, 1, 255);
	MyColor secondColor(1, 255, 1, 255);

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	MyColor newColor;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		


		ClearBackground(RAYWHITE);

		//MyHeroExercise(hero, ouch1, ouch2, ouch3, ouch4, ouch5, potion);

		MyColorExercise(newColor, firstColor, secondColor);

		ClearBackground(RAYWHITE);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//---------------------------------------------------------------------------------------

	return 0;
}

void MyHeroExercise(Hero &hero, const Texture2D &ouch1, const Texture2D &ouch2, const Texture2D &ouch3, const Texture2D &ouch4, const Texture2D &ouch5, Potion &potion)
{
	DrawText("Keep your Hero alive by give it a Potion! Press Enter to give it potion", 0, 0, 20, BLACK);

	if (hero.hitPoints > 120) {
		DrawTexture(ouch1, 100, 100, WHITE);
	}
	else if (hero.hitPoints > 90) {
		DrawTexture(ouch2, 100, 100, WHITE);
	}
	else if (hero.hitPoints > 60) {
		DrawTexture(ouch3, 100, 100, WHITE);
	}
	else if (hero.hitPoints > 30) {
		DrawTexture(ouch4, 100, 100, WHITE);
	}
	else if (hero.hitPoints > 0) {
		DrawTexture(ouch5, 100, 100, WHITE);
	}

	hero.hitPoints--;

	if (hero.hitPoints < 0) {
		DrawText("Your Hero Died", 100, 100, 20, BLACK);
	}
	else {
		std::string hitPoints = std::to_string(hero.hitPoints);
		char const *pchar = hitPoints.c_str();
		DrawText(pchar, 200, 200, 20, BLACK);
	}

	if (hero.hitPoints > 150) {
		hero.hitPoints = 150;
	}
	if (IsKeyPressed(KEY_ENTER)) {
		hero += potion;
	}
}

void MyColorExercise(MyColor &newColor, MyColor &firstColor, MyColor &secondColor)
{
	DrawText("Color Operator", 325, 50, 20, BLACK);

	if (IsKeyPressed(KEY_UP)) {
		newColor = firstColor * secondColor;
	}
	if (IsKeyPressed(KEY_DOWN)) {
		newColor = firstColor / secondColor;
	}
	if (IsKeyPressed(KEY_RIGHT)) {
		newColor = firstColor + secondColor;
	}
	if (IsKeyPressed(KEY_LEFT)) {
		newColor = firstColor - secondColor;
	}

	DrawText("R    G    B", 350, 250, 20, BLACK);
	DrawText("Right: Add", 350, 300, 20, BLACK);
	DrawText("Left: Subtract", 350, 325, 20, BLACK);
	DrawText("Up: Multiply", 350, 350, 20, BLACK);
	DrawText("Down: Divde", 350, 375, 20, BLACK);
	leftCircleColor(firstColor);
	rightCircleColor(secondColor);

	Color fColor = { (unsigned char)firstColor.r, (unsigned char)firstColor.g, (unsigned char)firstColor.b,(unsigned char)firstColor.a };
	Color sColor = { (unsigned char)secondColor.r, (unsigned char)secondColor.g, (unsigned char)secondColor.b,(unsigned char)secondColor.a };
	Color tColor = { (unsigned char)newColor.r, (unsigned char)newColor.g, (unsigned char)newColor.b,(unsigned char)newColor.a };

	Color test = { 255,255,0,255 };
	DrawCircle(150, 200, 50.f, fColor);
	DrawCircle(650, 200, 50.f, sColor);
	DrawCircle(400, 200, 50.f, tColor);

	std::string r = std::to_string(tColor.r);
	char const *pchar = r.c_str();
	DrawText(pchar, 350, 275, 20, BLACK);
	std::string g = std::to_string(tColor.g);
	char const *pchar1 = g.c_str();
	DrawText(pchar1, 395, 275, 20, BLACK);
	std::string b = std::to_string(tColor.b);
	char const *pchar2 = b.c_str();
	DrawText(pchar2, 435, 275, 20, BLACK);
}

