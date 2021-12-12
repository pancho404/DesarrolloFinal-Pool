#pragma once
#include "SceneManager.h"
#include "Menu.h"
#include "Rules.h"
#include "Credits.h"
#include "Game.h"
class App
{
private:
	SceneManager* sceneManager;
	Menu* menu;
	Rules* rules;
	Credits* credits;
	Game* game;
	Music music;
public:
	App();
	~App();
	void start();
};

