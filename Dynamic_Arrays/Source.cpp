#include "tStack.h"
#include <iostream>
#include "raylib.h"
#include <filesystem>
#include "Sprites.h"
#include "Source.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1856;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	Texture2D lightning = LoadTexture("Spells/spark_05_rotated.png");

	std::vector<std::string> spriteFileNames;
	std::string path = "Spells/Fire";
	for (auto & p : std::filesystem::directory_iterator(path)) {
		spriteFileNames.push_back(p.path().string());
	}

	Sprite fire = { spriteFileNames };

	SetTargetFPS(40);
	//--------------------------------------------------------------------------------------
	int x = 0;
	int alternate = 0;
	bool y = false;
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

		ClearBackground(BLACK);
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
			animateLightning(lightning);
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			y = true;
		}

		animateFireball(fire, y);

		

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
void animateFireball(Sprite &fire, bool &y)
{
	if (fire.position.x > 1800) {
		fire.position.x = 0;
		y = false;
	}
	if (y) {
		fire.Draw();
		fire.frames();
	}
}

void animateLightning(const Texture2D &lightning)
{
	for (int i = 0; i < 100; i++) {
		DrawTexture(lightning, 0 + (512 * (i % 20)), 100, WHITE);
	}
}
//int main() {
//	tVector<int> test;
//	
//	for (int i = 0; i < 5; i++) {
//		test.push_back(i);
//	}
//
//	tVector<int> original;
//	original.push_back(4);
//	original.push_back(5);
//	original.push_back(6);
//
//	
//	tVector<int> copy = original;
//	original.pop_back(); // removes from the original array, but not the copy
//	original.pop_back();
//	original.pop_back();
//
//	std::cout << "copy" << std::endl;
//	copy.print();
//
//	original.push_back(9);
//	original.push_back(10);
//	original.push_back(11);
//	original.push_back(11);
//
//	original[0] = 15;
//
//
//
//	copy = original;
//
//	std::cout << "original" << std::endl;
//	original.print();
//	original.pop_back(); // removes from the original array, but not the copy
//	original.pop_back();
//	original.pop_back();
//
//	std::cout << "copy" << std::endl;
//	copy.print();
//
//	copy.clear();
//	if (!copy.empty()) {
//		
//		std::cout << "copy" << std::endl;
//		std::cout << copy.capacity() << std::endl;
//		copy.print();
//	}
//	else {
//		std::cout << "no element" << std::endl;
//	}
//
//	copy.push_back(10);
//
//	copy.push_back(10);
//	copy.resize(20);
//	copy.print();
//	std::cout << copy.size() << std::endl;
//	std::cout << copy.capacity() << std::endl;
//
//}

