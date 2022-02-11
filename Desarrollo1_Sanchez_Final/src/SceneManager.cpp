#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = Scene::MENU;
}

SceneManager::~SceneManager()
{

}

Scene SceneManager::getScene()
{
	return scene;
}

void SceneManager::setScene(Scene _scene)
{
	this->scene = _scene;
}