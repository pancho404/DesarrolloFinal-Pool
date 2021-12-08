#pragma once
#include "SceneManager.h"
#include "Menu.h"
#include "Rules.h"
#include "Credits.h"
class App
{
private:
	SceneManager* sceneManager;
	Menu* menu;
	Rules* rules;
	Credits* credits;
public:
	App();
	~App();
	void start();
};

