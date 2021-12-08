#include "raylib.h"
#include "App.h"

void main()
{
	App* app = new App();
	app->start();
	delete app;
}