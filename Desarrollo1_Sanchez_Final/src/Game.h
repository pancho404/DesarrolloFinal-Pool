#pragma once
#include "Ball.h"
#include "Border.h"
#include "Hole.h"
#include "CueStick.h"
#include "Screen.h"
#include <vector>
using namespace std;

class Game 
{
private:
	vector<Ball*> balls;
	vector<Border*> borders;
	vector<Hole*> holes;
	CueStick* stick;
	vector<pair<Ball*, Ball*>> CollidingBalls;
	Sound ballSound;
	bool playerOneTurn;
public:
	Game();
	~Game();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();
	void BallBallCollision(vector<Ball*> balls);
	void BorderBallCollision(vector<Border*> borders, Ball* ball);
	void HoleBallCollision(vector<Hole*> holes, Ball* ball);
};

