#include "Game.h"

Game::Game(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
	playerOneTurn = true;
	playerOneWon = false;
	playerTwoWon = false;
	allBallsStill = true;
	whiteBallHit = false;
	gameOver = false;
}

Game::~Game()
{

}

void Game::Init()
{
	playerOneWins = LoadTexture("res/playerOne.png");
	playerTwoWins = LoadTexture("res/playerTwo.png");
	playerOneTurn = true;
	playerOneWon = false;
	playerTwoWon = false;
	allBallsStill = true;
	whiteBallHit = false;
	gameOver = false;
	ballSound = LoadSound("res/ballSound.mp3");
	holes.push_back(new Hole({ 36,36 }, 36));
	holes.push_back(new Hole({ 36,screenHeight - 36 }, 36));
	holes.push_back(new Hole({ screenWidth - 36,36 }, 36));
	holes.push_back(new Hole({ screenWidth - 36,screenHeight - 36 }, 36));
	holes.push_back(new Hole({ screenWidth / 2,screenHeight - 36 }, 36));
	holes.push_back(new Hole({ screenWidth / 2, 36 }, 36));
	backToMenu.x = 351;
	backToMenu.y = 631;
	backToMenu.width = 603;
	backToMenu.height = 71;
	Rectangle upLeft;
	upLeft.x = 72;
	upLeft.y = 0;
	upLeft.width = screenWidth / 2 - 108;
	upLeft.height = 32;
	Rectangle upRight;
	upRight.x = screenWidth / 2 + 36;
	upRight.y = 0;
	upRight.width = screenWidth / 2 - 108;
	upRight.height = 32;
	Rectangle downLeft;
	downLeft.x = 72;
	downLeft.y = screenHeight - 36;
	downLeft.width = screenWidth / 2 - 108;
	downLeft.height = 32;
	Rectangle downRight;
	downRight.x = screenWidth / 2 + 36;
	downRight.y = screenHeight - 36;
	downRight.width = screenWidth / 2 - 108;
	downRight.height = 32;
	Rectangle left;
	left.x = 0;
	left.y = 72;
	left.width = 30;
	left.height = screenHeight - 144;
	Rectangle right;
	right.x = screenWidth - 36;
	right.y = 72;
	right.width = 30;
	right.height = screenHeight - 144;
	borders.push_back(new Border(BorderPosition::UPLEFT, upLeft));
	borders.push_back(new Border(BorderPosition::UPRIGHT, upRight));
	borders.push_back(new Border(BorderPosition::DOWNLEFT, downLeft));
	borders.push_back(new Border(BorderPosition::DOWNRIGHT, downRight));
	borders.push_back(new Border(BorderPosition::LEFT, left));
	borders.push_back(new Border(BorderPosition::RIGHT, right));
	balls.push_back(new Ball({ screenWidth * 2 / 10,screenHeight / 2 }, WHITE, TypeOfBall::WHITEBALL, 0));
	balls.push_back(new Ball({ screenWidth * 7 / 10,screenHeight * 5 / 10 }, RED, TypeOfBall::STRIPED, 1));
	balls.push_back(new Ball({ screenWidth * 7.4 / 10,screenHeight * 4.6 / 10 }, RED, TypeOfBall::STRIPED, 2));
	balls.push_back(new Ball({ screenWidth * 7.4 / 10,screenHeight * 5.4 / 10 }, BLUE, TypeOfBall::SMOOTH, 3));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 4.2 / 10 }, BLUE, TypeOfBall::SMOOTH, 4));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 5 / 10 }, BLACK, TypeOfBall::BLACKBALL, 5));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 5.8 / 10 }, RED, TypeOfBall::STRIPED, 6));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 3.5 / 10 }, RED, TypeOfBall::STRIPED, 7));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 4.5 / 10 }, BLUE, TypeOfBall::SMOOTH, 8));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 5.5 / 10 }, RED, TypeOfBall::STRIPED, 9));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 6.5 / 10 }, BLUE, TypeOfBall::SMOOTH, 10));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 3 / 10 }, BLUE, TypeOfBall::SMOOTH, 11));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 4 / 10 }, RED, TypeOfBall::STRIPED, 12));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 5 / 10 }, BLUE, TypeOfBall::SMOOTH, 13));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 6 / 10 }, BLUE, TypeOfBall::SMOOTH, 14));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 7 / 10 }, RED, TypeOfBall::STRIPED, 15));
	ballsOnGame = 16;
}

void Game::Input()
{
	Vector2 mousePosition = GetMousePosition();

	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && balls[0]->GetVelocity().x == 0 && balls[0]->GetVelocity().y == 0 && allBallsStill)
	{
		balls[0]->Hit(mousePosition);
		whiteBallHit = true;
	}
}

void Game::Update()
{

	if (!gameOver)
	{
		
		int previousBallsOnGame = CheckBalls(balls);
		int ballsStill = 0;
		for (int i = 0; i < balls.size(); i++) {
			BorderBallCollision(borders, balls[i]);
			HoleBallCollision(holes, balls[i]);
		}
		BallBallCollision(balls);
		for (int i = 0; i < balls.size(); i++)
		{

			if (balls[i]->GetVelocity().x == 0 && balls[i]->GetVelocity().y == 0)
			{
				ballsStill++;
			}

		}
		if (ballsStill == 16)
		{
			allBallsStill = true;
		}
		else
		{
			allBallsStill = false;
		}
		ballsOnGame = CheckBalls(balls);

		if (previousBallsOnGame==ballsOnGame && whiteBallHit && allBallsStill)
		{
			playerOneTurn = !playerOneTurn;
			whiteBallHit = false;
		}
	}
	else
	{
		if (CheckCollisionPointRec(GetMousePosition(), backToMenu) && IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
		{
			Reset();
			sceneManager->setScene(Scene::MENU);
		}
	}
}

void Game::Draw()
{
	BeginDrawing();
	if (!gameOver)
	{
		ClearBackground(DARKGREEN);
		if (playerOneTurn)
		{
			DrawText("Player 1", screenWidth / 2 - 130, screenHeight / 2, 60, BLACK);
		}
		else
		{
			DrawText("Player 2", screenWidth / 2 - 130, screenHeight / 2, 60, BLACK);
		}
		for (int i = 0; i < holes.size(); i++)
		{
			holes[i]->Draw();
		}
		for (int i = 0; i < borders.size(); i++)
		{
			borders[i]->Draw();
		}
		for (int i = 0; i < balls.size(); i++)
		{
			if (balls[i]->GetOnGame()) {
				balls[i]->Draw();
			}
		}

	}
	else
	{
		if (playerOneWon)
		{
			DrawTexture(playerOneWins, 0, 0, WHITE);
		}
		else if (playerTwoWon)
		{
			DrawTexture(playerTwoWins, 0, 0, WHITE);
		}
	}

	EndDrawing();
}

void Game::DeInit()
{
	UnloadSound(ballSound);
	UnloadTexture(playerOneWins);
	UnloadTexture(playerTwoWins);
}

void Game::BallBallCollision(vector<Ball*> balls)
{
	for (auto& ball : balls)
	{
		ball->SetAcceleration({ -ball->GetVelocity().x * 0.8f ,-ball->GetVelocity().y * 0.8f});
		if (ball->GetAcceleration().x > -0.05 && ball->GetAcceleration().x < 0.05)
		{
			ball->SetAcceleration({ 0, ball->GetAcceleration().y });
		}
		if (ball->GetAcceleration().y > -0.05 && ball->GetAcceleration().y < 0.05)
		{
			ball->SetAcceleration({ ball->GetAcceleration().x,0 });
		}
		// Update ball physics
		ball->SetVelocity({ ball->GetVelocity().x + ball->GetAcceleration().x * GetFrameTime(), ball->GetVelocity().y + ball->GetAcceleration().y * GetFrameTime() });
		ball->SetPosition({ ball->GetPosition().x + ball->GetVelocity().x * GetFrameTime(), ball->GetPosition().y + ball->GetVelocity().y * GetFrameTime() });

		// Clamp velocity near zero
		if (fabs(ball->GetVelocity().x * ball->GetVelocity().x + ball->GetVelocity().y * ball->GetVelocity().y) < 1)
		{
			ball->SetVelocity({ 0,0 });
		}
	}

	for (auto& ball : balls)
	{
		for (auto& target : balls)
		{
			if (ball->GetID() != target->GetID())
			{
				if (sqrt(pow(ball->GetPosition().x - target->GetPosition().x, 2) + pow(ball->GetPosition().y - target->GetPosition().y, 2)) <= radius * 2)
				{
					PlaySound(ballSound);
					CollidingBalls.push_back({ ball, target });
					float distance = sqrt(pow(ball->GetPosition().x - target->GetPosition().x, 2) + pow(ball->GetPosition().y - target->GetPosition().y, 2));
					float overlap = 0.5f * (distance - radius * 2);

					ball->SetPosition({ ball->GetPosition().x - overlap * (ball->GetPosition().x - target->GetPosition().x) / distance, ball->GetPosition().y - overlap * (ball->GetPosition().y - target->GetPosition().y) / distance });

					target->SetPosition({ target->GetPosition().x + overlap * (ball->GetPosition().x - target->GetPosition().x) / distance, target->GetPosition().y + overlap * (ball->GetPosition().y - target->GetPosition().y) / distance });
				}
			}
		}
	}

	for (auto& collision : CollidingBalls)
	{
		Ball* b1 = collision.first;
		Ball* b2 = collision.second;

		float distance = sqrt(pow(b1->GetPosition().x - b2->GetPosition().x, 2) + pow(b1->GetPosition().y - b2->GetPosition().y, 2));

		float normalX = (b2->GetPosition().x - b1->GetPosition().x) / distance;
		float normalY = (b2->GetPosition().y - b1->GetPosition().y) / distance;

		float tangX = -normalY;
		float tangY = normalX;

		float dotTan1 = b1->GetVelocity().x * tangX + b1->GetVelocity().y * tangY;
		float dotTan2 = b2->GetVelocity().x * tangX + b2->GetVelocity().y * tangY;

		float dotNormal1 = b1->GetVelocity().x * normalX + b1->GetVelocity().y * normalY;
		float dotNormal2 = b2->GetVelocity().x * normalX + b2->GetVelocity().y * normalY;

		float m1 = (2.0f * mass * dotNormal2) / (mass * 2);
		float m2 = (2.0f * mass * dotNormal1) / (mass * 2);

		b1->SetVelocity({ -(tangX * dotTan2 + normalX * mass / 2), -(tangY * dotTan2 + normalY * mass / 2) });
		b2->SetVelocity({ tangX * dotTan1 + normalX * mass / 2 , tangY * dotTan1 + normalY * mass / 2 });

	}
	CollidingBalls.clear();
}

void Game::BorderBallCollision(vector<Border*> borders, Ball* ball)
{
	for (int i = 0; i < borders.size(); i++)
	{
		if (borders[i]->GetBorderPosition() == BorderPosition::UPLEFT)
		{
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y - radius <= borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height)
			{
				ball->SetVelocity({ ball->GetVelocity().x, -ball->GetVelocity().y });
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::UPRIGHT)
		{
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y - radius <= borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height)
			{
				ball->SetVelocity({ ball->GetVelocity().x , -ball->GetVelocity().y });
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::DOWNLEFT)
		{
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y + radius >= borders[i]->GetBorderRec().y)
			{
				ball->SetVelocity({ ball->GetVelocity().x , -ball->GetVelocity().y });
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::DOWNRIGHT)
		{
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y + radius >= borders[i]->GetBorderRec().y)
			{
				ball->SetVelocity({ ball->GetVelocity().x , -ball->GetVelocity().y });
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::RIGHT)
		{
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().y - radius >= borders[i]->GetBorderRec().y && ball->GetPosition().y - radius <= borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height)
			{
				ball->SetVelocity({ -ball->GetVelocity().x , ball->GetVelocity().y });

			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::LEFT)
		{
			if (ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y - radius >= borders[i]->GetBorderRec().y && ball->GetPosition().y - radius <= borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height)
			{
				ball->SetVelocity({ -ball->GetVelocity().x, ball->GetVelocity().y });
			}
		}
	}
}

void Game::HoleBallCollision(vector<Hole*> holes, Ball* ball)
{
	for (int i = 0; i < holes.size(); i++)
	{
		if (sqrt(pow(holes[i]->GetPosition().x - ball->GetPosition().x, 2) + pow(holes[i]->GetPosition().y - ball->GetPosition().y, 2)) < (holes[i]->GetRadius() + radius) / 2)
		{
			if (ball->GetType() == TypeOfBall::WHITEBALL)
			{
				ball->SetPosition({ screenWidth * 2 / 10, screenHeight / 2 });
				ball->SetDirection({ 0, 0 });
				ball->SetVelocity({ 0, 0 });
				ball->SetAcceleration({ 0 });
				playerOneTurn = !playerOneTurn;
			}
			if (ball->GetType() == TypeOfBall::BLACKBALL)
			{
				int counterStriped = 0;
				int counterSmooth = 0;
				for (int j = 0; j < balls.size(); j++)
				{
					if (!balls[j]->GetOnGame() && balls[j]->GetType() == TypeOfBall::STRIPED)
					{
						counterStriped++;
					}
					if (!balls[j]->GetOnGame() && balls[j]->GetType() == TypeOfBall::SMOOTH)
					{
						counterSmooth++;
					}
				}

				if (playerOneTurn)
				{
					if (counterStriped == 7)
					{
						playerOneWon = true;
					}
					else if (counterStriped < 7)
					{
						playerTwoWon = true;
					}
				}
				else
				{
					if (counterSmooth == 7)
					{
						playerTwoWon = true;
					}
					else if (counterSmooth < 7)
					{
						playerOneWon = true;
					}
				}
				//Gameover
				gameOver = true;
			}
			if (ball->GetType() == TypeOfBall::STRIPED)
			{
				if (!playerOneTurn)
				{
					playerOneTurn = true;
				}
				//Jugador de rayadas gana un turno
				//Jugador de lisas pierde un turno
				ball->SetOnGame(false);
			}
			if (ball->GetType() == TypeOfBall::SMOOTH)
			{
				if (playerOneTurn)
				{
					playerOneTurn = false;
				}
				//Jugador de lisas gana un turno
				//Jugador de rayadas pierde un turno
				ball->SetOnGame(false);
			}
		}

	}
}

void Game::Reset()
{
	playerOneTurn = true;
	playerOneWon = false;
	playerTwoWon = false;
	gameOver = false;
	balls.clear();
	balls.push_back(new Ball({ screenWidth * 2 / 10,screenHeight / 2 }, WHITE, TypeOfBall::WHITEBALL, 0));
	balls.push_back(new Ball({ screenWidth * 7 / 10,screenHeight * 5 / 10 }, RED, TypeOfBall::STRIPED, 1));
	balls.push_back(new Ball({ screenWidth * 7.4 / 10,screenHeight * 4.6 / 10 }, RED, TypeOfBall::STRIPED, 2));
	balls.push_back(new Ball({ screenWidth * 7.4 / 10,screenHeight * 5.4 / 10 }, BLUE, TypeOfBall::SMOOTH, 3));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 4.2 / 10 }, BLUE, TypeOfBall::SMOOTH, 4));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 5 / 10 }, BLACK, TypeOfBall::BLACKBALL, 5));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 5.8 / 10 }, RED, TypeOfBall::STRIPED, 6));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 3.5 / 10 }, RED, TypeOfBall::STRIPED, 7));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 4.5 / 10 }, BLUE, TypeOfBall::SMOOTH, 8));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 5.5 / 10 }, RED, TypeOfBall::STRIPED, 9));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 6.5 / 10 }, BLUE, TypeOfBall::SMOOTH, 10));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 3 / 10 }, BLUE, TypeOfBall::SMOOTH, 11));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 4 / 10 }, RED, TypeOfBall::STRIPED, 12));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 5 / 10 }, BLUE, TypeOfBall::SMOOTH, 13));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 6 / 10 }, BLUE, TypeOfBall::SMOOTH, 14));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 7 / 10 }, RED, TypeOfBall::STRIPED, 15));
}

int Game::CheckBalls(vector<Ball*> balls)
{
	int counter = 0;
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i]->GetOnGame())
		{
			counter++;
		}

	}
	return counter;
}

