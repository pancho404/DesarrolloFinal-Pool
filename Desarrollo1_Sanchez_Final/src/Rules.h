#pragma once
#include "raylib.h"

#include "SceneManager.h"
class Rules
{
private:
	Rectangle backRec;
	SceneManager* sceneManager;
	Texture2D texture;
public:
	Rules(SceneManager* sceneManager);
	~Rules();
	void Draw();
	void Update();
};

