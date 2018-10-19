#include <iostream>
#include "raylib.h"

template <typename T>
class gameObject
{
public:
	bool enabled;   // is this gameObject enabled?
	T * object;     // pointer to underlying instance of type T

	void update(float delta)
	{
		// todo: how to update the object?
		if (enabled) {
			object->update();
		}
	}

	void render()
	{
		// todo: how to render the object?
		if (enabled) {
			object->render();
		}
	}

	void setPos(Vector2 pos) {
		object->pos = pos;
	}

	// todo: What else would you need to include in this class declaration?
};

class Ninja {
public:
	Vector2 pos;
	void update();
};
class Soldier {
public:
	Vector2 pos;
	void render();
};

template<typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

template<typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");


	gameObject<Ninja> myNinja;
	gameObject<Soldier> mySoldier;

	myNinja.setPos(Vector2{ 0,0 });

	SetTargetFPS(60);
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

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
