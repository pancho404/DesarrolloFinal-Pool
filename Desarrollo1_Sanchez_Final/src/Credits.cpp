#include "Credits.h"

Credits::Credits(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
	backRec.width = 178;
	backRec.height = 71;
	backRec.x = 546;
	backRec.y = 634;
	texture = LoadTexture("../res/credits.png");
}

Credits::~Credits()
{
	UnloadTexture(texture);
}

void Credits::Update()
{
	if (CheckCollisionPointRec(GetMousePosition(), backRec) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::MENU);
	}
}

void Credits::Draw()
{
	BeginDrawing();
	DrawTexture(texture, 0, 0, WHITE);
	EndDrawing();
}