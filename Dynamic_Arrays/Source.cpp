#include "tStack.h"
#include <iostream>
#include "raylib.h"
#include <filesystem>
#include "Sprites.h"
#include "SpellElement.h"
#include "tForwardList.h"
#include "tQueue.h"

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

//int main() {
//	tVector<int> test;
//	
//	for (int i = 0; i < 5; i++) {
//		test.push_back(i*2);
//	}
//
//	test.print();
//	std::cout << test.size() << std::endl;
//	std::cout << test.capacity() << std::endl;
//
//
//	test.erase(4);
//
//	test.print();
//	std::cout << test.size() << std::endl;
//	std::cout << test.capacity() << std::endl;
//
//}

//node forward linked list
int main() {
	tForwardList<int> myList;
	myList.push_front(12);
	myList.push_front(52);
	myList.push_front(91);
	myList.push_front(40);
	// should print 40,91,52,12
	auto node = myList.first();
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}

	myList.pop_front();
	node = myList.first();
	std::cout << "popped" << std::endl;
	// should print 91,52,12
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}

	myList.clear();
	node = myList.first();
	std::cout << "clear" << std::endl;
	// should print nothing
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}

	myList.push_front(12);
	myList.push_front(12);
	myList.push_front(52);
	myList.push_front(91);
	myList.push_front(12);
	myList.push_front(12); 
	myList.push_front(40);
	

	myList.remove(12);
	node = myList.first();
	std::cout << "remove" << std::endl;
	// should print 40,91,51
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}


	tForwardList<int> copy = myList;
	std::cout << "copy" << std::endl;
	node = copy.first();
	// should print 40,91,51
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}

	myList.pop_front(); // remove 40 from original


	copy.push_front(60);
	std::cout << "copy test" << std::endl;
	node = copy.first();
	// should print 60,40,91,51
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}

	node = myList.first();
	std::cout << "original" << std::endl;
	// should print 91,51
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}


	myList = copy;
	node = myList.first();
	std::cout << "original" << std::endl;
	// should print 60,40,91,51
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}

	copy.pop_front(); // removes 60 from copy
	copy.pop_front(); // removes 40 from copy
	copy.pop_front(); // removes 92 from copy


	node = myList.first();
	std::cout << "original test" << std::endl;
	// should print 60,40,91,52
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}


	myList.resize(6);

	std::cout << "ahhhh" << std::endl;
	std::cout << "original iterator test" << std::endl; 
	// should print 60,40,91,52
	for (auto it = myList.begin(); it != myList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	auto it = myList.begin()+1;
	if (it == myList.begin()) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}


	node = copy.first();
	std::cout << "copy test" << std::endl;
	// should print 51
	while (node != nullptr) {
		std::cout << node->data << std::endl;
		node = node->next;
	}
}

