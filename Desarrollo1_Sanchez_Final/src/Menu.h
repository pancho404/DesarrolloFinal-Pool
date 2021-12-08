#pragma once
#include "Button.h"
#include "SceneManager.h"
class Menu
{
private:
	Rectangle playRec;
	Rectangle rulesRec;
	Rectangle creditsRec;
	Rectangle quitRec;
	Button* playButton;
	Button* rulesButton;
	Button* creditsButton;
	Button* quitButton;
	SceneManager* sceneManager;
	Texture2D texture;
public:
	Menu(SceneManager* sceneManager);
	~Menu();
	void Update();
	void Draw();
};

