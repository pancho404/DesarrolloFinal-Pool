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
	beepSound = LoadSound("res/beep.mp3");
	confirmSound = LoadSound("res/confirm.mp3");
	isMouseOverButton = false;
}

Menu::~Menu()
{
	UnloadTexture(texture);
	UnloadSound(beepSound);
	UnloadSound(confirmSound);
}

void Menu::Update()
{
	hoverMouse();
	if (CheckCollisionPointRec(GetMousePosition(), playRec) && IsMouseButtonReleased(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::GAMEPLAY);
		PlaySound(confirmSound);
	}
	if (CheckCollisionPointRec(GetMousePosition(), creditsRec) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::CREDITS);
		PlaySound(confirmSound);
	}
	if (CheckCollisionPointRec(GetMousePosition(), rulesRec) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::RULES);
		PlaySound(confirmSound);
	}
	if (CheckCollisionPointRec(GetMousePosition(), quitRec) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		sceneManager->setScene(Scene::EXIT);
		PlaySound(confirmSound);
	}

}

void Menu::Draw()
{
	BeginDrawing();
	DrawTexture(texture, 0, 0, WHITE);
	EndDrawing();
}

void Menu::hoverMouse()
{
	if (CheckCollisionPointRec(GetMousePosition(), playRec) && !isMouseOverButton)
	{
		PlaySound(beepSound);
		isMouseOverButton = true;
	}
	if (CheckCollisionPointRec(GetMousePosition(), creditsRec) && !isMouseOverButton)
	{
		PlaySound(beepSound);
		isMouseOverButton = true;
	}
	if (CheckCollisionPointRec(GetMousePosition(), rulesRec) && !isMouseOverButton)
	{
		PlaySound(beepSound);
		isMouseOverButton = true;
	}
	if (CheckCollisionPointRec(GetMousePosition(), quitRec) && !isMouseOverButton)
	{
		PlaySound(beepSound);
		isMouseOverButton = true;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), playRec) && !CheckCollisionPointRec(GetMousePosition(), creditsRec) && !CheckCollisionPointRec(GetMousePosition(), rulesRec) && !CheckCollisionPointRec(GetMousePosition(), quitRec) && isMouseOverButton)
	{
		isMouseOverButton = false;
	}
	

}