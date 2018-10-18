#include "raylib.h"
#include "Barbarian.h"
#include "Wizard.h"
#include "EvilEnt.h"
#include "Necromancer.h"
#include <vector>
#include <filesystem>
#include "main.h"




int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1900;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");


	Wizard wizard = { "Wizard/player_stand.png" };
	Barbarian barbarian = { "Barbarian/soldier_stand.png"};

	Texture2D wizardButton = LoadTexture("Wizard/blue_button05.png");
	Texture2D barbarianButton = LoadTexture("Barbarian/green_button05.png");

	Rectangle wizardButtonCollider = { 0,800,194,49 };
	Rectangle barbButtonCollider = { 200,800,194,49 };

	bool wizardPlay = false;
	bool barbarianPlay = false;
	bool shooting = false;
	//Enemy * enemies[10];
	std::vector<Enemy*> enemies;
	enemies.push_back(new EvilEnt(1800,50));
	enemies.push_back(new EvilEnt(1300,150));
	enemies.push_back(new EvilEnt(1700,225));
	enemies.push_back(new EvilEnt(1650,325));
	enemies.push_back(new EvilEnt(1400,350));
	enemies.push_back(new EvilEnt(1450,450));
	enemies.push_back(new EvilEnt(1500,550));
	enemies.push_back(new Necromancer(1300,300));
	enemies.push_back(new Necromancer(1500,250));
	enemies.push_back(new Necromancer(1700,650));
	
	std::vector<int> removal;
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

		if (wizardPlay) {
			wizard.Draw();
			if (shooting) {
				wizard.DrawFireball();
			}
			for (auto enemy : enemies) {
				enemy->Draw();
				//DrawRectangleRec(enemy->collider, BLACK);
			}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				wizard.moveTo(GetMousePosition());
				for (auto enemy : enemies) {
					enemy->moveTo(GetMousePosition());
				}
			}

			if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
				wizard.shoot(GetMousePosition());
				shooting = true;
			}

			for (int i = 0; i < enemies.size(); i++) {
				if (CheckCollisionPointRec(wizard.fireballPosition, enemies[i]->collider)) {
					wizard.fireballPosition = Vector2{ 0, 0 };
					removal.push_back(i);
					shooting = false;
					break;
				}
			}

			if (removal.size() > 0) {
				for (auto remove : removal) {
					enemies.erase(enemies.begin() + remove );
				}
				removal.clear();
			}

		}
		if (barbarianPlay) {
			barbarian.Draw();
			for (auto enemy : enemies) {
				enemy->Draw();
			}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				barbarian.moveTo(GetMousePosition());
				for (auto enemy : enemies) {
					enemy->moveTo(GetMousePosition());
				}
			}
		}

		characterButtons(wizard, barbarian, wizardButton, barbarianButton, wizardButtonCollider, barbarianPlay, wizardPlay, barbButtonCollider);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        
	// Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

void characterButtons(Wizard &wizard, Barbarian &barbarian, const Texture2D &wizardButton, const Texture2D &barbarianButton, const Rectangle &wizardButtonCollider, bool &barbarianPlay, bool &wizardPlay, const Rectangle &barbButtonCollider)
{
	DrawTexture(wizardButton, 0, 800, WHITE);
	DrawText("Wizard", 35, 805, 35, GRAY);
	DrawTexture(barbarianButton, 200, 800, WHITE);
	DrawText("Barbarian", 215, 805, 35, GRAY);

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), wizardButtonCollider)) {
		barbarianPlay = false;
		wizardPlay = true;
		barbarian.position = { 100.f, 100.f };
		barbarian.destination = { 100.f, 100.f };
	}

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), barbButtonCollider)) {
		wizardPlay = false;
		barbarianPlay = true;
		wizard.position = { 100.f, 100.f };
		wizard.destination = { 100.f, 100.f };
	}
}
