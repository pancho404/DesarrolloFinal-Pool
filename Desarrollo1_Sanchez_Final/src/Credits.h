#pragma once
#include "raylib.h"

#include "SceneManager.h"

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

