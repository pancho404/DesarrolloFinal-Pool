#include "Rules.h"

Rules::Rules(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
	backRec.width = 178;
	backRec.height = 71;
	backRec.x = 546;
	backRec.y = 634;
	texture = LoadTexture("res/rules.png");
}

Rules::~Rules()
{
	UnloadTexture(texture);
}

void Rules::Update()
{
	if (CheckCollisionPointRec(GetMousePosition(), backRec) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::MENU);
	}
}

void Rules::Draw()
{
	BeginDrawing();
	DrawTexture(texture, 0, 0, WHITE);
	EndDrawing();
}
