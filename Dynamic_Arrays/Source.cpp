#include "tStack.h"
#include <iostream>
#include "raylib.h"
#include <filesystem>
#include "Sprites.h"
#include "SpellElement.h"

//int main()
//{
//	// Initialization
//	//--------------------------------------------------------------------------------------
//	int screenWidth = 1856;
//	int screenHeight = 1024;
//
//	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
//
//	Texture2D lightning = LoadTexture("Spells/spark_05_rotated.png");
//
//	std::vector<std::string> spriteFileNames;
//	std::string path = "Spells/Fire";
//	for (auto & p : std::filesystem::directory_iterator(path)) {
//		spriteFileNames.push_back(p.path().string());
//	}
//
//	Sprite fire = { spriteFileNames };
//
//	SetTargetFPS(40);
//	//--------------------------------------------------------------------------------------
//	int x = 0;
//	int alternate = 0;
//	bool y = false;
//	// Main game loop
//	while (!WindowShouldClose())    // Detect window close button or ESC key
//	{
//		// Update
//		//----------------------------------------------------------------------------------
//		// TODO: Update your variables here
//		//----------------------------------------------------------------------------------
//
//		// Draw
//		//----------------------------------------------------------------------------------
//		BeginDrawing();
//
//		tStack<Spell> spellQueue;
//
//		if (IsKeyPressed(KEY_Q)) {
//			spellQueue.push({ WATER });
//		}else if (IsKeyPressed(KEY_W)) {
//			spellQueue.push({ FIRE });
//		}else if (IsKeyPressed(KEY_E)) {
//			spellQueue.push({ EARTH });
//		}else if (IsKeyPressed(KEY_R)) {
//			spellQueue.push({ LIGHTNING });
//		}
//
//		ClearBackground(BLACK);
//		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
//			animateLightning(lightning);
//		}
//
//		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//			y = true;
//		}
//
//		animateFireball(fire, y);
//
//		
//
//		EndDrawing();
//		//----------------------------------------------------------------------------------
//	}
//
//	// De-Initialization
//	//--------------------------------------------------------------------------------------   
//	CloseWindow();        // Close window and OpenGL context
//						  //--------------------------------------------------------------------------------------
//
//	return 0;
//}
//void animateFireball(Sprite &fire, bool &y)
//{
//	if (fire.position.x > 1800) {
//		fire.position.x = 0;
//		y = false;
//	}
//	if (y) {
//		fire.Draw();
//		fire.frames();
//	}
//}
//
//void animateLightning(const Texture2D &lightning)
//{
//	for (int i = 0; i < 100; i++) {
//		DrawTexture(lightning, 0 + (512 * (i % 20)), 100, WHITE);
//	}
//}

int main() {
	tVector<int> test;
	
	for (int i = 0; i < 5; i++) {
		test.push_back(i*2);
	}

	test.print();
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;


	test.erase(4);

	test.print();
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;

}

