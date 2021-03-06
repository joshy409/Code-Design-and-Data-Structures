#include "Sprite.h"
#include "Button.h"
#include <string>
#include <vector>
#include <filesystem>

#define MAX_FRAME_SPEED     60
#define MIN_FRAME_SPEED      1

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	int framesCounter = 0;
	int framesSpeed = 8;
	int currentFrame = 0;
	SetTargetFPS(10);
	//--------------------------------------------------------------------------------------

	std::vector<std::string> spriteFileNames;
	std::string path = "PNG/Adventurer/Poses";
	for (auto & p : std::filesystem::directory_iterator(path)) {
		spriteFileNames.push_back(p.path().string());
	}

	Sprite walking = { spriteFileNames };

	std::vector<std::string> bbuttons;
	std::string path1 = "blueButton";
	for (auto & p : std::filesystem::directory_iterator(path1)) {
		bbuttons.push_back(p.path().string());
	}

	Button blueButton = { bbuttons, 140.f, 65.f };

	std::vector<std::string> gbuttons;
	std::string path2 = "greenButton";
	for (auto & p : std::filesystem::directory_iterator(path2)) {
		gbuttons.push_back(p.path().string());
	}

	Button greenButton = { gbuttons, 140.f, 115.f };

	Rectangle bbuttonCollider = { 140,65,194,49 };

	Rectangle gbuttonCollider = { 140,115,194,49 };

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		
		ClearBackground(RAYWHITE);
		// Update
		framesCounter++;
		if (framesSpeed < 1) { framesSpeed = 1; }
		if (framesCounter >= (60 / framesSpeed))
		{
			framesCounter = 0;
			currentFrame++;

			if (currentFrame > 5) { currentFrame = 0; }
			walking.frames();

		}

		if (IsKeyPressed(KEY_RIGHT)) { framesSpeed++; }
		else if (IsKeyPressed(KEY_LEFT)) { framesSpeed--; }

		if (framesSpeed > MAX_FRAME_SPEED) framesSpeed = MAX_FRAME_SPEED;
		else if (framesSpeed < MIN_FRAME_SPEED) framesSpeed = MIN_FRAME_SPEED;

		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		BeginDrawing();

		DrawText("FRAME SPEED: ", 165, 210, 10, DARKGRAY);
		DrawText(FormatText("%02i FPS", framesSpeed), 575, 190, 10, DARKGRAY);
		DrawText("PRESS RIGHT/LEFT KEYS to CHANGE SPEED!", 290, 240, 10, DARKGRAY);

		for (int i = 0; i < MAX_FRAME_SPEED; i++)
		{
			if (i < framesSpeed) { DrawRectangle(250 + 21 * i, 205, 20, 20, RED); }
			DrawRectangleLines(250 + 21 * i, 205, 20, 20, MAROON);
	
		}
		walking.Draw();
		blueButton.Draw();
		greenButton.Draw();
		DrawText("(c) Scarfy sprite by Eiden Marsal", screenWidth - 200, screenHeight - 20, 10, GRAY);
		// Draw
		//----------------------------------------------------------------------------------
		
		if (CheckCollisionPointRec(GetMousePosition(), bbuttonCollider)) {
			blueButton.Draw();
		}
		else {
			blueButton.frames();
		}
		DrawText("Frame Up", 155, 70, 35, GRAY);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), bbuttonCollider)) {
			framesSpeed++;
		}

		if (CheckCollisionPointRec(GetMousePosition(), gbuttonCollider)) {
			greenButton.Draw();
		}
		else {
			greenButton.frames();
		}
		DrawText("Frame Down", 155, 120, 35, GRAY);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), gbuttonCollider)) {
			framesSpeed--;
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}