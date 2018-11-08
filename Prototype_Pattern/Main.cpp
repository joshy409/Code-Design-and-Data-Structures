#include<iostream>
#include "Gold.h"
#include "Kryptonite.h"
#include "Red.h"
#include "raylib.h"
#include "FallingFactorys.h"
#include "SimpleSprites.h"
#include <stack>
#include <cstdlib>
#include <ctime>
#include "Wizard.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1856;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	FallingFactorys::init();
	Vector2 delta = { 0, 2 };
	Wizard wizard = { "Wizard/player_stand.png" };
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


		wizard.Draw();
		if (shooting) {
			wizard.DrawFireball();
			//500 is range
			if (sqrt(pow((wizard.fireballPosition.x - wizard.origin.x), 2) + pow((wizard.fireballPosition.y - wizard.origin.y), 2)) > 1000) {
				shooting = false;
			}
		}

		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
			wizard.shoot(GetMousePosition());
			shooting = true;
		}

		for (auto &tank : FallingFactorys::tanks) {
			if (CheckCollisionPointRec(wizard.fireballPosition, tank->r1)) {
				shooting = false;
				removeThese.push(tank);
				break;
			}
		}

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

	Kryptonite *k1 = new Gold();
	Kryptonite *k2 = new Red();
	Kryptonite *k3 = k1->Clone();
	Kryptonite *k4 = k2->Clone();

	std::cout << "k1=" << k1->Diagnose().c_str() << std::endl;
	std::cout << "k2=" << k2->Diagnose().c_str() << std::endl;
	std::cout << "k3=" << k3->Diagnose().c_str() << std::endl;
	std::cout << "k4=" << k4->Diagnose().c_str() << std::endl;
	//Of course we should tidy up afterwards
	delete k1;
	delete k2;
	delete k3;
	delete k4;

	return 0;
}