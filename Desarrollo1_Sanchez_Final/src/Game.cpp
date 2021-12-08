#include "Game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::Init() {
	holes.push_back(new Hole({ 36,36 }, 36));
	holes.push_back(new Hole({ 36,screenHeight - 36 }, 36));
	holes.push_back(new Hole({ screenWidth - 36,36 }, 36));
	holes.push_back(new Hole({ screenWidth - 36,screenHeight - 36 }, 36));
	holes.push_back(new Hole({ screenWidth/2,screenHeight - 36 }, 36));
	holes.push_back(new Hole({ screenWidth / 2, 36 }, 36));
	Rectangle upLeft;
	upLeft.x = 72;
	upLeft.y = 0;
	upLeft.width = screenWidth / 2 - 108;
	upLeft.height = 36;
	Rectangle upRight;
	upRight.x = screenWidth / 2 + 36;
	upRight.y = 0;
	upRight.width = screenWidth / 2 - 108;
	upRight.height = 36;
	Rectangle downLeft;
	downLeft.x = 72;
	downLeft.y = screenHeight - 36;
	downLeft.width = screenWidth / 2 - 108;
	downLeft.height = 36;
	Rectangle downRight;
	downRight.x = screenWidth / 2 + 36;
	downRight.y = screenHeight - 36;
	downRight.width = screenWidth / 2 - 108;
	downRight.height = 36;
	Rectangle left;
	left.x = 0;
	left.y = 72;
	left.width = 36;
	left.height = screenHeight - 144;
	Rectangle right;
	right.x = screenWidth-36;
	right.y = 72;
	right.width = 36;
	right.height = screenHeight - 144;
	borders.push_back(new Border(BorderPosition::UPLEFT, upLeft));
	borders.push_back(new Border(BorderPosition::UPRIGHT, upRight));
	borders.push_back(new Border(BorderPosition::DOWNLEFT, downLeft));
	borders.push_back(new Border(BorderPosition::DOWNRIGHT, downRight));
	borders.push_back(new Border(BorderPosition::LEFT, left));
	borders.push_back(new Border(BorderPosition::RIGHT, right));
	balls.push_back(new Ball({ screenWidth * 2 / 10,screenHeight / 2 }, WHITE, TypeOfBall::WHITEBALL));
	balls.push_back(new Ball({ screenWidth * 7 / 10,screenHeight * 5 /10 }, RED, TypeOfBall::STRIPED));
	balls.push_back(new Ball({ screenWidth * 7.4 / 10,screenHeight * 4.6 /10 }, RED, TypeOfBall::STRIPED));
	balls.push_back(new Ball({ screenWidth * 7.4 / 10,screenHeight * 5.4 /10 }, BLUE, TypeOfBall::SMOOTH));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 4.2 / 10 }, BLUE, TypeOfBall::SMOOTH));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 5/10 }, BLACK, TypeOfBall::BLACKBALL));
	balls.push_back(new Ball({ screenWidth * 7.8 / 10,screenHeight * 5.8 /10 }, RED, TypeOfBall::STRIPED));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 3.5 / 10 }, RED, TypeOfBall::STRIPED));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 4.5 / 10 }, BLUE, TypeOfBall::SMOOTH));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 5.5 / 10 }, RED, TypeOfBall::STRIPED));
	balls.push_back(new Ball({ screenWidth * 8.2 / 10,screenHeight * 6.5 / 10 }, BLUE, TypeOfBall::SMOOTH));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 3 / 10 }, BLUE, TypeOfBall::SMOOTH));
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 4 / 10 }, RED, TypeOfBall::STRIPED));									
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 5 / 10 }, BLUE, TypeOfBall::SMOOTH));									
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 6 / 10 }, BLUE, TypeOfBall::SMOOTH));									
	balls.push_back(new Ball({ screenWidth * 8.6 / 10,screenHeight * 7 / 10 }, RED, TypeOfBall::STRIPED));
	
}

void Game::Input() {
	Vector2 mousePosition = GetMousePosition();
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))     {
		balls[0]->Hit(mousePosition);
	}
}

void Game::Update() {
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i]->GetOnGame()) {
			balls[i]->Movement();
		}
		BorderBallCollision(borders, balls[i]);
		HoleBallCollision(holes, balls[i]);
	}
	BallBallCollision(balls);
}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(DARKGREEN);
	for (int i = 0; i < holes.size(); i++) {
		holes[i]->Draw();
	}
	for (int i = 0; i < borders.size(); i++) {
		borders[i]->Draw();
	}
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i]->GetOnGame()) {
			balls[i]->Draw();
		}
	}
	EndDrawing();
}

void Game::DeInit() {
}

void Game::BallBallCollision(vector<Ball*> balls) {
	float distance = 0.0f; //Seteamos variables de distancia entre bolas, la normal a la hora de la colision y la profundidad con la que una pelota se sobreposiciona en la otra
	Vector2 normal = { 0,0 };
	float depth = 0;
	for (int i = 0; i < balls.size(); i++) {
		for (int j = i+1; j < balls.size(); j++) { //Comparamos cada bola con las demas sin repetir ni comparar a la misma consigo misma
			distance = sqrt(pow(balls[j]->GetPosition().x - balls[i]->GetPosition().x, 2) + pow(balls[j]->GetPosition().y - balls[i]->GetPosition().y, 2)); //Obtenemos la distancia entre los centros de ambas a traves de pitágoras
			if (distance < radius * 2) { //Si la distancia es menor a la suma de los radios de las bolas

				normal.x = (balls[j]->GetPosition().x - balls[i]->GetPosition().x) / sqrt(pow(balls[j]->GetPosition().x - balls[i]->GetPosition().x, 2) + pow(balls[j]->GetPosition().y - balls[i]->GetPosition().y, 2)); //Obtenemos la normal de la colision en x

				normal.y = (balls[j]->GetPosition().y - balls[i]->GetPosition().y) / sqrt(pow(balls[j]->GetPosition().x - balls[i]->GetPosition().x, 2) + pow(balls[j]->GetPosition().y - balls[i]->GetPosition().y, 2));//Obtenemos la normal de la colision en y

				depth = radius - distance; //La cantidad de espacio que una bola invadió de otra	

				Vector2 normalForce1 = { -normal.x * abs(balls[i]->GetForce() - balls[j]->GetForce()) / 2,-normal.y * abs(balls[i]->GetForce() - balls[j]->GetForce()) / 2 }; //Fuerza que recibe la bola 1 al colisionar

				Vector2 directionForce1 = { balls[i]->GetDirection().x * balls[i]->GetForce() / 2,balls[i]->GetDirection().y * balls[i]->GetForce() / 2 }; //Obtenemos la direccion en la que iba la bola 1 al colisionar

				Vector2 result1 = { normalForce1.x + directionForce1.x,normalForce1.y + directionForce1.y }; //La suma de ambas fuerzas nos devuelve la nueva direccion y fuerza que adquiere la bola

				Vector2 normalForce2 = { normal.x * abs(balls[j]->GetForce() - balls[i]->GetForce()) / 2,normal.y * abs(balls[j]->GetForce() - balls[i]->GetForce()) / 2 }; //Fuerza que recibe la bola 2 al colisionar

				Vector2 directionForce2 = { balls[j]->GetDirection().x * balls[j]->GetForce() / 2,balls[j]->GetDirection().y * balls[j]->GetForce() / 2 };//Obtenemos la direccion en la que iba la bola 2 al colisionar

				Vector2 result2 = { (normalForce2.x + directionForce2.x) ,(normalForce2.y + directionForce2.y) };	//La suma de ambas fuerzas nos devuelve la nueva direccion y fuerza que adquiere la bola

				balls[i]->Move({ normal.x * depth / 2 , normal.y *depth/2}); //Se reubica la pelota en una posicion donde ya no colisione con la otra bola

				balls[i]->SetForce(result1); //Se le aplica la nueva fuerza surgida de la colision

				balls[j]->Move({ -normal.x * depth / 2 , -normal.y * depth / 2 });//Se reubica la pelota en una posicion donde ya no colisione con la otra bola

				balls[j]->SetForce({ result2.x , result2.y });//Se le aplica la nueva fuerza surgida de la colision
			}
		}
	}
}

void Game::BorderBallCollision(vector<Border*> borders, Ball* ball) {
	for (int i = 0; i < borders.size(); i++) {
		if(borders[i]->GetBorderPosition() == BorderPosition::UPLEFT){
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y - radius <= borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height) {
				ball->SetDirection({ ball->GetDirection().x, -ball->GetDirection().y });
				ball->SetPosition({ball->GetPosition().x, borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height + radius });
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::UPRIGHT) {
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y - radius <= borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height) {
				ball->SetDirection({ ball->GetDirection().x, -ball->GetDirection().y });
				ball->SetPosition({ ball->GetPosition().x, borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height + radius });
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::DOWNLEFT) {
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y + radius >= borders[i]->GetBorderRec().y) {
				ball->SetDirection({ ball->GetDirection().x * 0.8f, -ball->GetDirection().y * 0.8f });
				ball->SetPosition({ ball->GetPosition().x, borders[i]->GetBorderRec().y - radius });
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::DOWNRIGHT) {
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y + radius >= borders[i]->GetBorderRec().y) {
				ball->SetDirection({ ball->GetDirection().x, -ball->GetDirection().y });
				ball->SetPosition({ ball->GetPosition().x, borders[i]->GetBorderRec().y - radius });
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::RIGHT) {
			if (ball->GetPosition().x + radius >= borders[i]->GetBorderRec().x && ball->GetPosition().y - radius >= borders[i]->GetBorderRec().y && ball->GetPosition().y - radius <= borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height) {
				ball->SetDirection({ -ball->GetDirection().x, ball->GetDirection().y });
				ball->SetPosition({ ball->GetPosition().x - radius , ball->GetPosition().y});
			}
		}
		else if (borders[i]->GetBorderPosition() == BorderPosition::LEFT) {
			if (ball->GetPosition().x - radius <= borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width && ball->GetPosition().y - radius >= borders[i]->GetBorderRec().y && ball->GetPosition().y - radius <= borders[i]->GetBorderRec().y + borders[i]->GetBorderRec().height) {
				ball->SetDirection({ -ball->GetDirection().x, ball->GetDirection().y });
				ball->SetPosition({ borders[i]->GetBorderRec().x + borders[i]->GetBorderRec().width + radius , ball->GetPosition().y });
			}
		}
	}
}

void Game::HoleBallCollision(vector<Hole*> holes, Ball* ball) {
	for (int i = 0; i < holes.size(); i++) {
		if (sqrt(pow(holes[i]->GetPosition().x - ball->GetPosition().x, 2) + pow(holes[i]->GetPosition().y - ball->GetPosition().y, 2)) < (holes[i]->GetRadius() + radius)/2) {
			if (ball->GetType() == TypeOfBall::WHITEBALL) {
				ball->SetPosition({ screenWidth * 2 / 10, screenHeight / 2 });
				ball->SetDirection({ 0, 0 });
				ball->SetVelocity({ 0, 0 });
				ball->SetAcceleration(0);
			}
			if (ball->GetType() == TypeOfBall::BLACKBALL) {
				//Gameover
			}
			if (ball->GetType() == TypeOfBall::STRIPED) {
				//Jugador de rayadas gana un turno
				//Jugador de lisas pierde un turno
				ball->SetOnGame(false);
			}
			if (ball->GetType() == TypeOfBall::SMOOTH) {
				//Jugador de lisas gana un turno
				//Jugador de rayadas pierde un turno
				ball->SetOnGame(false);
			}
		}
		
	}
}
