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
	bool shooting = false;
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

		if (delayFrame > GetFPS()/2) { //spawns every 60 frames (.5 sec)
			SimpleSprites* randomTank = FallingFactorys::getRandom();
			randomTank->pos = Vector2{ (float) (rand() % screenWidth), 50 };
			randomTank->r1.x = randomTank->pos.x;
			randomTank->r1.y = randomTank->pos.y;
			delayFrame = 0;
		}

		//draw and move all the tanks that are spawned. save the pointers to the tanks that needs to be deleted
		std::stack<SimpleSprites*> removeThese;
		for (auto &tank : FallingFactorys::tanks) {
			DrawText(std::to_string(FallingFactorys::tanks.size()).c_str(), 100, 100, 30, BLACK);
			tank->draw();
			tank->translate(delta);
			if (tank->pos.y > 1100) {
				removeThese.push(tank);
			}
		}

		delayFrame++;

		//delete all the tanks that are outside of the screen to clear memory space
		for (int i = 0; removeThese.size(); i++) {
			FallingFactorys::tanks.remove(removeThese.top());
			delete removeThese.top();
			removeThese.pop();
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