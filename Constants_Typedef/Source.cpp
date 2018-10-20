#include "raylib.h"
#include "DialFace.h"
static int screenWidth = 800;
static int screenHeight = 450;
Vector2 DialFace::position = Vector2{ (float)screenWidth / 2, (float)screenHeight / 2 };
float DialFace::radius = 200.f;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	//int screenWidth = 800;
	//int screenHeight = 450;

	DialFace clock;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(120);
	//--------------------------------------------------------------------------------------

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

		ClearBackground(GRAY);

		DialFace::DrawFace();
		clock.Tick(GetMousePosition());
		

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}