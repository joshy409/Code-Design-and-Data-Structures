#include<iostream>
#include "raylib.h"
#include "FallingFactorys.h"
#include "SimpleSprites.h"
#include <stack>
#include <cstdlib>
#include <ctime>
#include "tObjectPool.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1856;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	FallingFactorys::init();
	Vector2 delta = { 0, 2 };

	int delayFrame = 0;
	SetTargetFPS(120);
	srand(time(NULL));
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

		ClearBackground(RAYWHITE);

		//creates a clone of one of the 4 tanks and sets its position to random x at the top 
		SimpleSprites* randomTank = nullptr;
		if (delayFrame > GetFPS()/8) { //spawns every 15 frames (.5 sec)
			randomTank = FallingFactorys::tanks.retrieve();
			if (randomTank != NULL) {
				randomTank->pos = Vector2{ (float)(rand() % screenWidth), 50 };
			}
			delayFrame = 0;
		}

		//draw and move all the tanks that are spawned. save the pointers to the tanks that needs to be deleted
		for (int i = 0; i < FallingFactorys::tanks.free.size(); i++) {
			if (FallingFactorys::tanks.free[i] == true) {
				FallingFactorys::tanks.pool[i]->draw();
				FallingFactorys::tanks.pool[i]->translate(delta);
				if (FallingFactorys::tanks.pool[i]->pos.y > 1000) {
					FallingFactorys::tanks.recycle(FallingFactorys::tanks.pool[i]);
				}
			}
		}

		delayFrame++;



		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}