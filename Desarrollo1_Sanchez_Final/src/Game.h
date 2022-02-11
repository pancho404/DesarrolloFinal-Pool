#pragma once
#include "Ball.h"
#include "Border.h"
#include "Hole.h"
#include "Screen.h"
#include "SceneManager.h"
#include <vector>
using namespace std;

class Game 
{
private:
	Texture2D ballTexture;
	SceneManager* sceneManager;
	vector<Ball*> balls;
	vector<Border*> borders;
	vector<Hole*> holes;
	vector<pair<Ball*, Ball*>> CollidingBalls;
	Texture2D playerOneWins;
	Texture2D playerTwoWins;
	Rectangle backToMenu;
	Sound ballSound;
	bool playerOneTurn;
	bool gameOver;
	bool playerOneWon;
	bool playerTwoWon;
	bool allBallsStill;
	bool whiteBallHit;
	int ballsOnGame;
public:
	Game(SceneManager* sceneManager);
	~Game();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();
	void BallBallCollision(vector<Ball*> balls);
	void BorderBallCollision(vector<Border*> borders, Ball* ball);
	void HoleBallCollision(vector<Hole*> holes, Ball* ball);
	void Reset();
	int CheckBalls(vector<Ball*> balls);
};

