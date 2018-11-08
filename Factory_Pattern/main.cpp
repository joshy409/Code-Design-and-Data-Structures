#include<iostream>
#include <string>

#include "IBox.h"
#include "IFactory.h"
#include "Factory.h"

#include "FallingFactory.h"
#include "SimpleSprite.h"

#include <stack>;
int main() {
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1856;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(10);
	//--------------------------------------------------------------------------------------
	FallingFactory::init();
	Vector2 delta ={ 0, 3 };
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

		//creates a clone of one of the 4 tanks and sets its position to mouse position
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			SimpleSprite* randomTank = FallingFactory::getRandom(); 
			randomTank -> pos = GetMousePosition();
		}


		//draw and move all the tanks that are spawned. save the pointers to the tanks that needs to be deleted
		std::stack<SimpleSprite*> removeThese;
		for (auto &tank : FallingFactory::tanks) {
			DrawText(std::to_string(FallingFactory::tanks.size()).c_str(), 100, 100, 30, BLACK);
			tank->draw();
			tank->translate(delta);
			if (tank->pos.y > 1100) {
				removeThese.push(tank);
			}
		}
	
		//delete all the tanks that are outside of the screen to clear memory space
		for (int i = 0; removeThese.size(); i++) {
			FallingFactory::tanks.remove(removeThese.top());
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

	IBox* p = NULL;
	p = Factory::GetInstance().Create("Red");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	p = Factory::GetInstance().Create("Blue");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	return 1;
}