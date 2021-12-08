#include "Menu.h"

Menu::Menu(SceneManager* sceneManager)
{
	playRec.width = 145;
	playRec.height = 70;
	playRec.x = 564;
	playRec.y = 265;
	rulesRec.width = 194;
	rulesRec.height = 71;
	rulesRec.x = 538;
	rulesRec.y = 361;
	creditsRec.width = 243;
	creditsRec.height = 71;
	creditsRec.x = 513;
	creditsRec.y = 468;
	quitRec.width = 149;
	quitRec.height = 71;
	quitRec.x = 560;
	quitRec.y = 569;	
	this->sceneManager = sceneManager;
	texture = LoadTexture("res/mainMenu.png");
}

Menu::~Menu()
{	
	UnloadTexture(texture);
}

void Menu::Update()
{
	if (CheckCollisionPointRec(GetMousePosition(), playRec)&& IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::GAMEPLAY);
	}
	if (CheckCollisionPointRec(GetMousePosition(), creditsRec) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::CREDITS);
	}
	if (CheckCollisionPointRec(GetMousePosition(), rulesRec) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::RULES);
	}
	if (CheckCollisionPointRec(GetMousePosition(), quitRec) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::EXIT);
	}
}

void Menu::Draw()
{
	BeginDrawing();
	DrawTexture(texture, 0, 0, WHITE);
	EndDrawing();
}