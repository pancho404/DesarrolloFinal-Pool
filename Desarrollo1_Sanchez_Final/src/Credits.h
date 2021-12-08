#pragma once
#include "SceneManager.h"
#include "raylib.h"
class Credits
{
private:
	Rectangle backRec;
	Texture2D texture;
	SceneManager* sceneManager;
public:
	Credits(SceneManager* sceneManager);
	~Credits();
	void Update();
	void Draw();
};

