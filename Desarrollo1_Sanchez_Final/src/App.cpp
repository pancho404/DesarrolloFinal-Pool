#include "App.h"
#include <iostream>
App::App()
{
	InitWindow(1280, 720, "Pool by Francisco Sanchez");
	InitAudioDevice();
	sceneManager = new SceneManager();
	menu = new Menu(sceneManager);
	rules = new Rules(sceneManager);
	credits = new Credits(sceneManager);
	game = new Game(sceneManager);
	music = LoadMusicStream("res/music.mp3");
	SetMusicVolume(music, 0.2f);
	music.looping = true;
	
}

App::~App()
{
	delete sceneManager;
	delete menu;
	delete rules;
	delete credits;
	game->DeInit();
	delete game;
	UnloadMusicStream(music);
	CloseAudioDevice();
}

void App::start()
{
	game->Init();
	PlayMusicStream(music);
	
	while (!WindowShouldClose() && sceneManager->getScene()!=Scene::EXIT)
	{
		UpdateMusicStream(music);
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
			game->Input();
			game->Update();
			game->Draw();
		case Scene::EXIT:
			break;
		default:
			break;
		}

	}
}