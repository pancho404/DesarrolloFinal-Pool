#pragma once
#include "raylib.h"
#include "SceneManager.h"
class Menu
{
private:
	Rectangle playRec;
	Rectangle rulesRec;
	Rectangle creditsRec;
	Rectangle quitRec;	
	SceneManager* sceneManager;
	Texture2D texture;
public:
	Menu(SceneManager* sceneManager);
	~Menu();
	void Update();
	void Draw();
};

