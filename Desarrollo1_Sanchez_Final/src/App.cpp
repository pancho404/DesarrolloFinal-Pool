#include "App.h"

App::App()
{
	InitWindow(1280, 720, "Pool by Francisco Sanchez");
	sceneManager = new SceneManager();
	menu = new Menu(sceneManager);
	rules = new Rules(sceneManager);
	credits = new Credits(sceneManager);
	game = new Game();
}

App::~App()
{
	delete sceneManager;
	delete menu;
	delete rules;
	delete credits;
	delete game;
}

void App::start()
{
	while (!WindowShouldClose && sceneManager->getScene()!=Scene::EXIT)
	{
		switch (sceneManager->getScene())
		{
		case Scene::MENU:
			menu->Update();
			menu->Draw();
			break;
		case Scene::RULES:
			rules->Update();
			rules->Draw();
			break;
		case Scene::CREDITS:
			credits->Update();
			credits->Draw();
			break;
		case Scene::GAMEPLAY:

		case Scene::EXIT:
			break;
		default:
			break;
		}

	}
}