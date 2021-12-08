#include "Ball.h"

Ball::Ball(Vector2 position, Color color, TypeOfBall type) {
    this->position = position;
    this->color = color;
    this->type = type;
}

Ball::~Ball() {
}

Vector2 Ball::GetPosition() {
    return position;
}

void Ball::SetPosition(Vector2 position) {
    this->position.x = position.x;
    this->position.y = position.y;
}

Vector2 Ball::GetVelocity() {
    return velocity;
}

void Ball::SetVelocity(Vector2 velocity) {
    this->velocity.x = velocity.x;
    this->velocity.y = velocity.y;
}

Vector2 Ball::GetDirection() {
    return direction;
}

void Ball::SetDirection(Vector2 direction) {
    this->direction.x = direction.x;
    this->direction.y = direction.y;
}

Color Ball::GetColor() {
    return color;
}

bool Ball::GetOnGame() {
    return onGame;
}

void Ball::SetOnGame(bool onGame) {
    this->onGame = onGame;
}

bool Ball::GetIsMoving() {
    return isMoving;
}

void Ball::SetIsMoving(bool isMoving) {
    this->isMoving = isMoving;
}

void Ball::Draw() {
    DrawCircle(position.x,position.y,radius,color);
}

void Ball::Movement() {
    acceleration -= friction * GetFrameTime(); //Se le aplica el rozamiento de la mesa a la velocidad
    acceleration -= airFriction * GetFrameTime(); //Se le aplica el rozamiento del aire a la velocidad

    if (acceleration < 0)         {
        acceleration = 0;
    }
    if (acceleration > 400) {
        acceleration = 400;
    }

    velocity.x = direction.x * acceleration * GetFrameTime(); //La velocidad se ve afectada por la direccion y aceleracion de la bola
    velocity.y = direction.y * acceleration * GetFrameTime();

    if (velocity.x > 10) {
        velocity.x = 10;
    }
    if (velocity.y > 10) {
        velocity.y =    10;
    }
    if (velocity.x < -10) {
        velocity.x = -10;
    }
    if (velocity.y < -10) {
        velocity.y = -10;
    }
    this->position.x += velocity.x;
    this->position.y += velocity.y;
}

void Ball::Hit(Vector2 mousePosition) {

    Vector2 forceOfHit = { (position.x - mousePosition.x) * 2,(position.y - mousePosition.y) * 2 }; //La fuerza es el doble de la diferencia entre la posición del mouse y la pelota

    if (forceOfHit.x > 300) {
        forceOfHit.x = 300;
    }
    if (forceOfHit.y > 300) {
        forceOfHit.y = 300;
    }
    if (forceOfHit.x < -300) {
        forceOfHit.x = -300;
    }
    if (forceOfHit.y < -300) {
        forceOfHit.y = -300;
    }

    direction.x = forceOfHit.x / sqrt((pow(forceOfHit.x,2)+pow(forceOfHit.y,2))); //Se descompone la fuerza en sus correspondientes direcciones normalizadas
    direction.y = forceOfHit.y / sqrt((pow(forceOfHit.x, 2) + pow(forceOfHit.y, 2)));

    acceleration = sqrt((pow(forceOfHit.x, 2) + pow(forceOfHit.y, 2)));
}

TypeOfBall Ball::GetType() {
    return type;
}

void Ball::SetAcceleration(float acceleration) {
    this->acceleration = acceleration;
}

float Ball::GetForce() {
    return mass*acceleration;
}

void Ball::SetForce(Vector2 force) {
   
    direction.x = force.x / sqrt((pow(force.x, 2) + pow(force.y, 2)));
    direction.y = force.y / sqrt((pow(force.x, 2) + pow(force.y, 2)));

    acceleration = sqrt((pow(force.x, 2) + pow(force.y, 2)));
}

void Ball::Move(Vector2 movement) {
    position.x += movement.x;
    position.y += movement.y;
}
