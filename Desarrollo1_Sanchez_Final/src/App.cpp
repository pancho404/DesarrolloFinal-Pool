#include "App.h"

App::App()
{
	sceneManager = new SceneManager();
	menu = new Menu(sceneManager);
	rules = new Rules(sceneManager);
	credits = new Credits(sceneManager);
}

App::~App()
{
	delete sceneManager;
	delete menu;
	delete rules;
	delete credits;
}